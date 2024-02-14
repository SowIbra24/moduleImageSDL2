#ifndef MODULE_IMAGE_IMAGEVIEWER_H
#define MODULE_IMAGE_IMAGEVIEWER_H

#include"Image.h"
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @class ImageViewer
 * 
 * @brief Permet d'afficher une image via SDL
 * 
*/
class ImageViewer
{
private:
    SDL_Window * window; ///< Lien sur la fenêtre de SDL
    SDL_Renderer * renderer; ///< Lien sur la renderer de SDL
    SDL_Surface * surface; ///< Lien sur une surface SDL
    SDL_Texture * texture; ///< Lien sur une texture SDL


public:
    // Constructeur qui initialise tout SDL2 et crée la fenêtre
    // et le rendere

    /**
     * @brief Constructeur par défaut
     * Initialise SDL et crée la fenêtre
    */
    ImageViewer();

    /**
     * @brief Destructeur par défaut
     * Détruit et ferme SDL
    */
    ~ImageViewer();

    /**
     * @brief Afficher une image passée en paramètre
     * @param im Image à afficher
    */
    void afficher(const Image & im);

};

#endif
