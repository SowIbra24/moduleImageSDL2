#include "Pixel.h"
#include <iostream>

using namespace std;

Pixel::Pixel() : r(0), g(0), b(0) {}

Pixel::Pixel(unsigned char nr, unsigned char ng ,unsigned char nb) : r(nr), g(ng), b(nb) {}

bool Pixel::operator==(const Pixel &pix2) const
{
    return ((r==pix2.r) && (g==pix2.g) && (b==pix2.b));
}

void Pixel::afficherPixel(const Pixel &pix)
{
    cout << "RGB(" << pix.r << ", " << pix.g << ", " << pix.b << endl;
}