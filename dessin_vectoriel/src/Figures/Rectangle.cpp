#include "Rectangle.h"
#include "Figures.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

//Constructeurs
Rectangle::Rectangle(string f, int x, int y, int l, int h, std::string c, int t, int z){
    Figures(f, x, y, c, t, z);
    longueur = l;
    hauteur = h;
}

Rectangle::Rectangle(){
    Figures();
    longueur = 0;
    hauteur = 0;
}


//Getters
int Rectangle::getLongueur()const{
    return longueur;
}

int Rectangle::getHauteur()const{
    return hauteur;
}


//Setters
void Rectangle::setLongueur(int l){
    longueur = l;
}

void Rectangle::setHauteur(int h){
    hauteur = h;
}

//Methode
void Rectangle::afficher(CImage *img){
    CPixel *p = new CPixel();

    if(forme.compare("Rectangle") == 0){
        int x1 = coordx;
        int y1 = coordy;
        p = img->getPixel(coordx,coordy);
        p->Color(couleur, transparence);
        for (x1=coordx; x1<coordx+longueur; x1++)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
        for (y1=coordy; y1<coordy+hauteur; y1++)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
        for (x1=coordx+longueur; x1>coordx; x1--)
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
        for (y1=coordy+hauteur; y1>coordy; y1-- )
        {
            p = img->getPixel(x1, y1);
            p->Color(couleur, transparence);
        }
    }
    else if(forme.compare("RectangleS") == 0){
        int x1 = coordx;
        int y1 = coordy;
        p = img->getPixel(coordx,coordy);
        p->Color(couleur, transparence);
        for (int x1=coordx; x1<coordx+longueur; x1++)
        {
            for (int y1=coordy; y1<coordy+hauteur; y1++)
            {
                p = img->getPixel(x1, y1);
                p->Color(couleur, transparence);
            }
        }
    }
}

void Rectangle::ajouter(){

    Figures::ajouter();

    cout << "Longueur : ";
    cin >> longueur;
    cin.ignore();

    cout << "Hauteur : ";
    cin >> hauteur;
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
