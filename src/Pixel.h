#ifndef _PIXEL_H
#define _PIXEL_H

/**
 * @struct Pixel
 * 
 * @brief Structure représentant un Pixel
 * 
 * Permet de créer un Pixel, défini par une couleur RGB (Rouge Vert Bleu).
*/
struct Pixel
{
    unsigned char r; ///< Composante Rouge
    unsigned char g; ///< Composante Verte
    unsigned char b; ///< Composante Bleue
    
    /** 
     * @brief Constructeur par défaut
     * 
     * Initialise les composantes à 0 (couleur noire)
    */
    Pixel();
    
    Pixel(unsigned char nr, unsigned char ng ,unsigned char nb);

    /**
     * @brief Opérateur de surcharge 
     * 
     * Tester l'égalité de deux structures Pixel
     * 
     * @param pix2 Second Pixel dont on veut tester l'égalité
    */
    bool operator==(const Pixel& pix2) const;

    /**
     * @brief Afficher un Pixel
     * @param pix Pixel à afficher
    */
    void afficherPixel(const Pixel& pix);
};

#endif
