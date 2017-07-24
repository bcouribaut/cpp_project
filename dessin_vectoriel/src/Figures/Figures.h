#ifndef FIGURES_H_INCLUDED
#define FIGURES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "../Image/CImage.h"

class Figures
{
protected: //Attributs
    std::string forme;
    int coordx;
    int coordy;
    std::string couleur;
    int transparence;
    int planz;

public:	//Méthodes

    virtual void ajouter();
    virtual void afficher(CImage *img);

    //Constructeurs
    Figures();
    Figures(std::string f, int x, int y, std::string c, int t, int z);
    ~Figures();

    //Getters
    std::string getForme()const;
    int getCoordx()const;
    int getCoordy()const;
    std::string getCouleur()const;
    int getTransparence()const;
    int getPlanz()const;

    //Setters
    void setForme(std::string);
    void setCoordx(int);
    void setCoordy(int);
    void setCouleur(std::string);
    void setTransparence(int);
    void setPlanz(int);

};

#endif // FIGURES_H_INCLUDED
