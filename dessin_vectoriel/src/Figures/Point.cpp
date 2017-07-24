#include "Point.h"
#include "Figures.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Constructeurs
Point::Point(){
	Figures();
}

Point::Point(string f, int x, int y, string c, int t, int z){
    Figures(f, x, y, c, t, z);
}

void Point::afficher(CImage *img){
	CPixel *p = new CPixel();
    p = img->getPixel(coordx, coordy);
	p->Color(couleur, transparence);
}

void Point::ajouter(){

	Figures::ajouter();

    cout << "Couleur : ";
    getline(cin, couleur);

    cout << "Transparence : ";
    cin >> transparence;
    cin.ignore();

    cout << "Plan z : ";
    cin >> planz;
    cin.ignore();
}