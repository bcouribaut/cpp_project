#include "Carre.h"
#include "Figures.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Constructeurs
Carre::Carre(string f, int x, int y, int l, string c, int t, int z){
    Figures(f, x, y, c, t, z);
    longueur = l;
}

Carre::Carre(){
	Figures();
    longueur = 0;
}


//Getters
int Carre::getLongueur(){
    return longueur;
}


//Setters
void Carre::setLongueur(int l){
    longueur = l;
}


void Carre::afficher(CImage *img){
    CPixel *p = new CPixel();
    if(forme.compare("Carre") == 0){
        int x1=coordx;
        int y1=coordy;
        p = img->getPixel(coordx,coordy);
        p->Color(couleur, transparence);
        for (x1=coordx; x1<coordx+longueur; x1++)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
        for (y1=coordy; y1<coordy+longueur; y1++)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
        for (x1=coordx+longueur; x1>coordx; x1--)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
        for (y1=coordy+longueur; y1>coordy; y1--)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
    }

    else if(forme.compare("CarreS") == 0){
        int x1 = coordx;
        int y1 = coordy;
        p = img->getPixel(coordx,coordy);
        p->Color(couleur, transparence);
        for (int x1=coordx ; x1<coordx+longueur ; x1++ )
        {
           for (int y1=coordy ; y1<coordy+longueur ; y1++ )
           {
               p = img->getPixel(x1, y1);
               p->Color(couleur, transparence);
           }
        }
    }
}


void Carre::ajouter(){
    Figures::ajouter();

    cout << "Longueur : ";
    cin >> longueur;
    cin.ignore();

    cout << "Couleur : ";
    getline(cin, couleur);

    cout << "Transparence : ";
    cin >> transparence;
    cin.ignore();

    cout << "Plan z : ";
    cin >> planz;
    cin.ignore();
}