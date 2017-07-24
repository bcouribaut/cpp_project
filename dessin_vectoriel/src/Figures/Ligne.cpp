#include "Ligne.h"
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

Ligne::Ligne(string f, int x, int y, int x2, int y2, string c, int t, int z){
    Figures(f, x, y, c, t, z);
    coordx2 = x2;
    coordy2 = y2;
}


Ligne::Ligne(){
    Figures();
    coordx2 = 0;
    coordy2 = 0;
}


//Getters
int Ligne::getCoordx2()const{
    return coordx2;
}

int Ligne::getCoordy2()const{
    return coordy2;
}


//Setters
void Ligne::setCoordx2(int x2){
    coordx2 = x2;
}

void Ligne::setCoordy2(int y2){
    coordy2 = y2;
}

//Methode
void Ligne::ajouter(){

    Figures::ajouter();

    cout << "Coordonnée x d'arrivée : ";
    cin >> coordx2;
    cin.ignore();

    cout << "Coordonnée y d'arrivée : ";
    cin >> coordy2;
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

void Ligne::afficher(CImage *img){
    CPixel *p = new CPixel();

    int mx = 0;
    int my = 0;

    if (coordx2 < coordx)
    {
        swap(coordx,coordx2);
        swap(coordy,coordy2);
    }
    
    if (coordx<coordx2 && coordy<coordy2 && (coordy2-coordy)<=(coordx2-coordx))
    {
        float dy = coordy2-coordy;
        float dx = coordx2-coordx;
        int y = coordy;
        int f = 0;
        for (int x=coordx; x<=coordx2; x++)
        {
            f=f+dy;
            p = img->getPixel(x, y);
            p->Color(couleur, transparence);
            if (f>(dx/2))
            {
                y = y+1;
                f = f-dx;
            }
        }
    }


    else if (coordx<coordx2 && coordy>coordy2 && (coordy-coordy2)<=(coordx2-coordx))
    {
        float dy = coordy-coordy2;
        float dx = coordx2-coordx;
        int y = coordy;
        int f = 0;
        for (int x=coordx; x<=coordx2; x++)
        {
            f=f+dy;
            p = img->getPixel(x, y);
            p->Color(couleur, transparence);
            if (f>(dx/2))
            {
                y = y-1;
                f = f-dx;
            }
        }
    }


    else if (coordx<coordx2 && coordy<coordy2 && (coordy2-coordy)>=(coordx2-coordx))
    {
        float dy = coordy2-coordy;
        float dx = coordx2-coordx;
        int x = coordx;
        int f = 0;
        for (int y=coordy; y<=coordy2; y++)
        {
            f=f+dx;
            p = img->getPixel(x, y);
            p->Color(couleur, transparence);
            if (f>(dy/2))
            {
                x = x+1;
                f = f-dy;
            }
        }
    }

    else if (coordx<coordx2 && coordy>coordy2 && (coordy-coordy2)>=(coordx2-coordx))
    {
        float dy = coordy-coordy2;
        float dx = coordx2-coordx;
        int x = coordx;
        int f = 0;
        for (int y=coordy; y>=coordy2; y--)
        {
            f=f+dx;
            p = img->getPixel(x, y);
            p->Color(couleur, transparence);
            if (f>(dy/2))
            {
                x = x+1;
                f = f-dy;
            }
        }
    }
}
