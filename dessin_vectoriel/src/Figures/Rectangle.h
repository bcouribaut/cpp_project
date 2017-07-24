#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Figures.h"
#include "../Image/CImage.h"


class Rectangle : public Figures
{
public:	//Attributs
    int longueur;
    int hauteur;

public:	//Méthodes

    void afficher(CImage *img);
    void ajouter();

    //Constructeurs
    Rectangle(std::string f, int x, int y, int l, int h, std::string c, int t, int z);
    Rectangle();

    //Getters
    int getLongueur()const;
    int getHauteur()const;

    //Setters
    void setLongueur(int);
    void setHauteur(int);

};

#endif // RECTANGLE_H_INCLUDED
