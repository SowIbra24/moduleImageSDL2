#include "Image.h"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

Image::Image() : dimx(0), dimy(0), tab(nullptr) {}

Image::Image(int dimensionX, int dimensionY)
{
    assert(dimensionX > 0 && dimensionY > 0);

    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image()
{
    dimx = 0;
    dimy = 0;

    if (tab!= nullptr) {
        delete [] tab;
    }

    tab = nullptr;
}

bool Image::validitePixel(int x, int y) const
{
    return ((x>=0 && x<dimx) && (y>=0 && y<dimy));
}


Pixel& Image::getPix(int x, int y)
{
    assert(validitePixel(x,y));
    return tab[y * dimx+x]; // passage d'un tableau 2D à un tableau 1D
}

Pixel Image::getPix(int x, int y) const
{
    assert(validitePixel(x,y));
    return tab[y * dimx+x];
}

void Image::setPix(int x, int y,const Pixel & couleur)
{
    assert(validitePixel(x,y));
    tab[y*dimx+x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, const Pixel & couleur)
{
    assert(validitePixel(Xmin,Ymin) && validitePixel(Xmax,Ymax));
    {
        for(int y=Ymin;y<=Ymax;y++)
        {
            for(int x=Xmin;x<=Xmax;x++)
            {
                setPix(x,y,couleur);
            }
        }
    }
}

void Image::effacer(const Pixel &couleur)
{
    dessinerRectangle(0,0,dimx-1,dimy-1,couleur);
}

void Image::sauver(const string & filename) const
{
    ofstream fichier (filename.c_str());

    assert(fichier.is_open());

    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    for(unsigned int y=0; y<dimy; y++)
    {
        for(unsigned int x=0; x<dimx; x++)
        {
            Pixel pix = getPix(x,y);
            fichier << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
    }

    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename)
{
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());

    int  r,g,b;
    string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;

    assert(dimx > 0 && dimy > 0);

    if (tab != NULL) delete [] tab;

    tab = new Pixel [dimx*dimy];

    for(unsigned int y=0; y<dimy; y++)
    {
        for(unsigned int x=0; x<dimx; x++)
        {
            fichier >> r >> g >> b;
            setPix(x,y, Pixel(r,g,b));
        }
    }

    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole()
{
    cout << dimx << " " << dimy << endl;

    for(unsigned int y=0; y<dimy; y++)
    {
        for(unsigned int x=0; x<dimx; x++)
        {
            const Pixel pix = getPix(x,y);
            cout << +pix.r << " " << +pix.g << " " << +pix.b<< " ";
        }

        cout << endl;
    }
}

void Image::testRegression()
{
    Image im1(5,10);
    //Image im2(2,2);
    // test de la validié du pixel (il est dans le tableau)
    assert(im1.validitePixel(4,8) == true);

    // test de getPix et setPix (couleur qui entre = couleur qui sort)
    Pixel pixel1 (255,0,0);
    im1.setPix(2,5,pixel1);
    assert(im1.getPix(2,5) == pixel1);

    // test sur le rectangle
    Pixel pixel2(0,0,255);
    im1.dessinerRectangle(0,0,im1.dimx-1,im1.dimy-1,pixel2);

    for(int y=0;y<=im1.dimy-1;y++)
    {
        for(int x=0;x<=im1.dimx-1;x++)
        {
            assert((im1.getPix(x,y) == pixel2));
        }
    }

    // test sur effacer avec un nouveau rectagle
    Pixel couleur(0,255,0);
    im1.effacer(couleur);

    for(int y=0;y<=im1.dimy-1;y++)
    {
        for (int x = 0; x <= im1.dimx - 1; x++)
        {
            assert((im1.getPix(x, y) == couleur));
        }
    }

    Pixel& ref = im1.getPix(2,5);
    ref.g=25;
    ref.r = 200;

    assert(im1.getPix(2,5).g == 25);
    assert(im1.getPix(2,5).r == 200);

    im1.sauver("./data/imageTest.ppm");
    std::cout<< "test de regression reussi\n";
}
