#include "Image.h"
#include "ImageViewer.h"
int main() 
{
    Pixel rouge (205, 9, 13);
    Pixel jaune (242, 248, 22);
    Pixel bleu (120, 193, 246);
    Image image1 (64,48);

    image1.effacer(bleu);
    image1.dessinerRectangle(6, 8, 26, 21, rouge);
    image1.setPix(16,14,jaune);
    image1.setPix(46,33,jaune);
    image1.sauver("./data/image1.ppm");

    Image image2;
    
    image2.ouvrir("./data/image1.ppm");
    image2.dessinerRectangle(23, 18, 37, 28, rouge);
    image2.dessinerRectangle(34, 26, 50, 36, jaune);
    image2.sauver("./data/image2.ppm");


    return 0;
}