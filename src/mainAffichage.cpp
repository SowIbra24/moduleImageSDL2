#include "Image.h"
#include "ImageViewer.h"
#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    SDL_Init(0);
    Image image (61,61);

    Pixel blanc (255, 255, 255);
    Pixel bleu (39, 114, 190);
    Pixel noir (0, 0, 0);
    Pixel rouge (227, 20, 26);
    Pixel jaune (252, 241, 0);
    Pixel vert (65, 177, 71);

    image.effacer(blanc);
    image.dessinerRectangle(3,22,18,37,bleu);
    image.dessinerRectangle(5,24,16,35,blanc);
    image.dessinerRectangle(23,22,38,37,noir);
    image.dessinerRectangle(25,24,36,35,blanc);
    image.dessinerRectangle(43,22,58,37,rouge);
    image.dessinerRectangle(45,24,56,35,blanc);
    image.dessinerRectangle(13,29,28,44,jaune);
    image.dessinerRectangle(15,31,26,42,blanc);
    image.dessinerRectangle(33,29,48,44,vert);
    image.dessinerRectangle(35,31,46,42,blanc);


    ImageViewer imview;
    imview.afficher(image);


    return 0;
}
