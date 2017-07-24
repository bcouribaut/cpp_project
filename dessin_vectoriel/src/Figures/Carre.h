#ifndef CARRE_H_INCLUDED
#define CARRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Figures.h"
#include "../Image/CImage.h"


class Carre : public Figures
{
private:	//attributs
    int longueur;

public:	//méthodes

    void afficher(CImage *img);
    void ajouter();

    //Constructeurs
    Carre(std::string f, int x, int y, int l, std::string c, int t, int z);
    Carre();

    //Getters
    int getLongueur();

    //Setters
    void setLongueur(int);

};

#endif // CARRE_H_INCLUDED
