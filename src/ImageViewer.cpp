#include "ImageViewer.h"
#include <SDL2/SDL.h>
#include <cassert>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Image.h"
#define DIMW 200 // si vous le mettez à 500, c'est cool

using namespace std;

ImageViewer::ImageViewer()

{
    surface = nullptr;
    texture = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << endl;
        SDL_Quit();
    }


    window = SDL_CreateWindow("ModuleImage",SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , DIMW , DIMW ,SDL_WINDOW_MINIMIZED);

    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenêtre : " << SDL_GetError() << endl;
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) // Gestion des erreurs
    {
        cout << "Erreur lors de la creation du renderer : " << SDL_GetError() << endl;
        SDL_Quit();
    }

}

ImageViewer::~ImageViewer() 
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit(); // On quitte la SDL

    window = nullptr;
    renderer = nullptr;
    surface = nullptr;
    texture = nullptr;
}

void ImageViewer::afficher(const Image &im)
{
    im.sauver("data/affiche.ppm");
    surface = IMG_Load("data/affiche.ppm");
    if(surface == nullptr)
    {
        cout << "error load image \n";
        SDL_Quit();
        exit(1);

    }
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    assert(texture != nullptr);


    SDL_Event events;
    bool quit = false;
    float x, y, w = 100, h = 100;

    x = (DIMW / 2) - (w / 2);
    y = (DIMW / 2) - (h / 2);

    // tant que ce n'est pas la fin ...
    while (!quit) {

        // tant qu'il y a des evenements à traiter
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN)
            {
                switch (events.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        quit = true;
                        break;
                    case SDLK_t:
                        w*=1.1;
                        h*=1.1;
                        break;
                    case SDLK_g:
                        w/=1.1;
                        h/=1.1;
                        break;
                    default: break;
                }
            }
        }

        x = (DIMW / 2) - (w / 2);
        y = (DIMW / 2) - (h / 2);

        // on affiche l'image sur le buffer caché
        int ok;
        SDL_Rect r;
        r.x = x;
        r.y = y;
        r.w = w;
        r.h = h;

        ok = SDL_RenderCopy(renderer,texture,nullptr,&r);
        assert(ok == 0);


        // on efface le renderer et on permute les deux buffers

        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
    }
}
