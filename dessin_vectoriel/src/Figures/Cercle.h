#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Figures.h"
#include "../Image/CImage.h"


class Cercle : public Figures
{
private: //Attributs
    int rayon;

public:	//Méthodes

    void afficher(CImage *img);
    void ajouter();

    //Constructeurs
    Cercle(std::string f, int x, int y, int r, std::string c, int t, int z);
    Cercle();

    //Getters
    int getRayon();

    //Setters
    void setRayon(int);

};

#endif // CERCLE_H_INCLUDED
