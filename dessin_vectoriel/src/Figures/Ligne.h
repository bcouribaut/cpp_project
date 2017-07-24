#ifndef LIGNE_H_INCLUDED
#define LIGNE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Figures.h"
#include "../Image/CImage.h"


class Ligne : public Figures
{
private: //Attributs
    int coordx2;
    int coordy2;

public:	//Méthodes

    void afficher(CImage *img);
    void ajouter();

    //Constructeurs
    Ligne(std::string f, int x, int y, int x2, int y2, std::string c, int t, int z);
    Ligne();

    //Getters
    int getCoordx2()const;
    int getCoordy2()const;

    //Setters
    void setCoordx2(int);
    void setCoordy2(int);

};

#endif // LIGNE_H_INCLUDED
