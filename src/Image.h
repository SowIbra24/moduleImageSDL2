#ifndef _IMAGE_H
#define _IMAGE_H

#include "Pixel.h"
#include <string>

using namespace std;

/**
 * @class Image
 * 
 * @brief Classe représentant une Image
 * 
 * Permet de créer une image en associant un ensemble de Pixel.
*/

class Image
{
private:
    Pixel *tab; ///< Tableau stockant l'ensemble de Pixel de l'Image
    int dimx; ///< Dimension X de l'Image
    int dimy; ///< Dimension Y de l'Image

    /**
     * @brief Vérifie la validité d'un Pixel
     * @param x Coordonée X du Pixel
     * @param y Coordonée Y du Pixel
     * @return Retourne 'true' si le Pixel est valide, sinon 'false'
    */
    bool validitePixel(int x, int y) const;

public:
    /**
     * @brief Constructeur par défaut de la classe Image
     * 
     * Initialise les dimensions de l'image à 0 et le tableau à nullptr
    */
    Image();

    /**
     * @brief Constructeur paramétré de la classe Image
     * Vérifie les dimensions et alloue la mémoire pour tab
     * @param dimensionX Dimension X de l'image
     * @param dimensionY Dimension Y de l'image
    */
    Image(int dimensionX, int dimensionY);

    /**
     * @brief Destructeur de la classe Image
     * Désalloue la mémoire de tab et met les dimensions à 0
    */
    ~Image();

    /** 
     * @brief Récupérer un Pixel en spécifiant sa position en vérifiant sa validité (passage par référence)
     * @param x Coordonée X du Pixel
     * @param y Coordonée Y du Pixel
     * @return Le Pixel aux coordonées indiquées
    */
    Pixel& getPix(int x,int y);

    /** 
     * @brief Récupérer un Pixel en spécifiant sa position en vérifiant sa validité (mode donnée)
     * @param x Coordonée X du Pixel
     * @param y Coordonée Y du Pixel
     * @return Le Pixel aux coordonées indiquées
    */
    Pixel getPix (int x, int y) const ;

    /**
     * @brief Définir la couleur d'un Pixel
     * @param x Coordonée X du Pixel
     * @param y Coordonée Y du Pixel
     * @param couleur Couleur à appliquer
    */
    void setPix(int x, int y, const Pixel & couleur);

    /**
     * @brief Dessiner un rectangle
     * @param Xmin Coordonnée minimale de X
     * @param Ymin Coordonnée minimale de Y
     * @param Xmax Coordonnée maximale de X
     * @param Ymax Coordonnée maximale de Y
     * @param couleur Couleur à appliquer
    */
    void dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, const Pixel & couleur);

    /**
     * @brief Efface l'image en la remplissant de la couleur passée en paramètre
     * @param couleur Couleur utilisée
    */
    void effacer (const Pixel & couleur) ;

    /**
     * @brief Sauvegarde l'image sous format ppm
    */
    void sauver(const string & filename) const;

    /** 
     * @brief Ouvre un fichier et charge son contenu dans un objet Image
     * @param filename Nom du fichier image
    */
    void ouvrir(const string & filename);

    /**
     * @brief Affiche une image dans la console
    */
    void afficherConsole();

    /**
     * @brief Effectue une série de tests de régression
     * 
     * Vérifie que toutes les fonctions s'exécutent correctement et que les données membres
     * de l'objet sont conformes.
    */
    static void testRegression();
};

#endif
