#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#include "Figures.h"


//Constructeurs
Figures::Figures(){
    forme = "";
    coordx = 0;
    coordy = 0;
    couleur = "";
    transparence = 0;
    planz = 0;
}


Figures::Figures(string f, int x, int y, string c, int t, int z){
    forme = f;
    coordx = x;
    coordy = y;
    couleur = c;
    transparence = t;
    planz = z;
}

//Destructeur
Figures::~Figures(){

}

void Figures::ajouter(){
    
    cout << "Coordonnée x de départ (en bas à gauche pour Rectangle et Carre, centre pour Cercle) : ";
    cin >> coordx;
    cin.ignore();

    cout << "Coordonée y de départ (en bas à gauche pour Rectangle et Carre, centre pour Cercle) : ";
    cin >> coordy;
    cin.ignore();
}

void Figures::afficher(CImage *img){

}


//Getters
string Figures::getForme()const{
    return forme;
}

int Figures::getCoordx()const{
    return coordx;
}

int Figures::getCoordy()const{
    return coordy;
}

string Figures::getCouleur()const{
    return couleur;
}

int Figures::getTransparence()const{
    return transparence;
}

int Figures::getPlanz()const{
    return planz;
}


//Setters
void Figures::setForme(string f){
    forme = f;
}

void Figures::setCoordx(int x){
    coordx = x;
}

void Figures::setCoordy(int y){
    coordy = y;
}

void Figures::setCouleur(string c){
    couleur = c;
}

void Figures::setTransparence(int t){
    transparence = t;
}

void Figures::setPlanz(int z){
    planz = z;
}
