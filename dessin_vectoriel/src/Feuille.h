#ifndef FEUILLE_H_INCLUDED
#define FEUILLE_H_INCLUDED

#include "./Figures/Point.h"
#include "./Figures/Ligne.h"
#include "./Figures/Rectangle.h"
#include "./Figures/Carre.h"
#include "./Figures/Cercle.h"
#include "./Figures/Figures.h"
#include "./Image/CImage.h"
#include "./Image/CLigne.h"
#include "./Image/CPixel.h"
#include "./Format/CBitmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Feuille
{
private: //Attributs
    int echelle;
    vector<Figures*> figures;

public:	//Méthodes

	//Constructeurs
	Feuille();


	void loadFromFile(std::string fichier);
	void ajouter_forme(std::string forme);
 	void Tracer(CImage *img);
    void zoom(CImage *img, int e);



};

#endif // FEUILLE_H_INCLUDED
