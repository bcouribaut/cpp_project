#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Figures.h"
#include "../Image/CImage.h"


class Point : public Figures
{
private: //Attributs


public:	//Méthodes
	
	Point();
    Point(std::string f, int x, int y, std::string c, int t, int z);
    
    void afficher(CImage *img);
    void ajouter();


};

#endif // POINT_H_INCLUDED
