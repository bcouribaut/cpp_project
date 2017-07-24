#include "Feuille.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


//Constructeurs
Feuille::Feuille(){
    echelle = 0;
}

void Feuille::ajouter_forme(string forme){

        if(forme.compare("Point") == 0)
        {
            Point *point = new Point();
            point->setForme(forme);
            point->ajouter();
            figures.push_back(point);
        }

        else if(forme.compare("Ligne") == 0)
        {
            Ligne *ligne = new Ligne();
            ligne->setForme(forme);
            ligne->ajouter();
            figures.push_back(ligne);
        }

        else if((forme.compare("Rectangle") == 0)||(forme.compare("RectangleS") == 0))
        {
            Rectangle *rectangle = new Rectangle();
            rectangle->setForme(forme);
            rectangle->ajouter();
            figures.push_back(rectangle);
        }

        else if((forme.compare("Carre") == 0)||(forme.compare("CarreS") == 0))
        {
            Carre *carre = new Carre();
            carre->setForme(forme);
            carre->ajouter();
            figures.push_back(carre);
        }

        else if((forme.compare("Cercle") == 0)||(forme.compare("CercleS") == 0))
        {
            Cercle *cercle = new Cercle();
            cercle->setForme(forme);
            cercle->ajouter();
            figures.push_back(cercle);
        }
}

void Feuille::loadFromFile(string fichier){

    ifstream myFile;
    myFile.open(fichier.c_str());

    // int cpt=0;

    if(myFile)
    {
        while(!(myFile.eof())){
            string buf;
            string forme;

            getline(myFile, buf);
            forme=buf;

            getline(myFile, buf);
            istringstream intcoordx(buf);
            int x(0);
            intcoordx >> x;

            getline(myFile, buf);
            istringstream intcoordy(buf);
            int y(0);
            intcoordy >> y;

            if (forme.compare("Point") == 0){
                Point *point = new Point();
                point->setForme(forme);
                point->setCoordx(x);
                point->setCoordy(y);

                getline(myFile, buf);
                point->setCouleur(buf);

                getline(myFile, buf);
                istringstream inttransp(buf);
                int t(0);
                inttransp >> t;
                point->setTransparence(t);

                getline(myFile, buf);
                istringstream intplanz(buf);
                int z(0);
                intplanz >> z;
                point->setPlanz(z);

                figures.push_back(point);

            }
            if (forme.compare("Ligne") == 0){
                Ligne *ligne = new Ligne();
                ligne->setForme(forme);
                ligne->setCoordx(x);
                ligne->setCoordy(y);

                getline(myFile, buf);
                istringstream intcoordx2(buf);
                int x2(0);
                intcoordx2 >> x2;
                ligne->setCoordx2(x2);

                getline(myFile, buf);
                istringstream intcoordy2(buf);
                int y2(0);
                intcoordy2 >> y2;
                ligne->setCoordy2(y2);

                getline(myFile, buf);
                ligne->setCouleur(buf);

                getline(myFile, buf);
                istringstream inttransp(buf);
                int t(0);
                inttransp >> t;
                ligne->setTransparence(t);

                getline(myFile, buf);
                istringstream intplanz(buf);
                int z(0);
                intplanz >> z;
                ligne->setPlanz(z);

                figures.push_back(ligne);

            }
            if ((forme.compare("Carre") == 0)||(forme.compare("CarreS") == 0)){
                Carre *carre = new Carre();
                carre->setForme(forme);
                carre->setCoordx(x);
                carre->setCoordy(y);

                getline(myFile, buf);
                istringstream intlongueur(buf);
                int l(0);
                intlongueur >> l;
                carre->setLongueur(l);

                getline(myFile, buf);
                carre->setCouleur(buf);

                getline(myFile, buf);
                istringstream inttransp(buf);
                int t(0);
                inttransp >> t;
                carre->setTransparence(t);

                getline(myFile, buf);
                istringstream intplanz(buf);
                int z(0);
                intplanz >> z;
                carre->setPlanz(z);

                figures.push_back(carre);

            }
            if ((forme.compare("Rectangle") == 0)||(forme.compare("RectangleS") == 0)){
                Rectangle *rectangle = new Rectangle();
                rectangle->setForme(forme);
                rectangle->setCoordx(x);
                rectangle->setCoordy(y);

                getline(myFile, buf);
                istringstream intlongueur(buf);
                int l(0);
                intlongueur >> l;
                rectangle->setLongueur(l);

                getline(myFile, buf);
                istringstream inthauteur(buf);
                int h(0);
                inthauteur >> h;
                rectangle->setHauteur(h);

                getline(myFile, buf);
                rectangle->setCouleur(buf);

                getline(myFile, buf);
                istringstream inttransp(buf);
                int t(0);
                inttransp >> t;
                rectangle->setTransparence(t);

                getline(myFile, buf);
                istringstream intplanz(buf);
                int z(0);
                intplanz >> z;
                rectangle->setPlanz(z);

                figures.push_back(rectangle);

            }
            if ((forme.compare("Cercle") == 0)||(forme.compare("CercleS") == 0)){
                Cercle *cercle = new Cercle();
                cercle->setForme(forme);
                cercle->setCoordx(x);
                cercle->setCoordy(y);

                getline(myFile, buf);
                istringstream intrayon(buf);
                int r(0);
                intrayon >> r;
                cercle->setRayon(r);

                getline(myFile, buf);
                cercle->setCouleur(buf);

                getline(myFile, buf);
                istringstream inttransp(buf);
                int t(0);
                inttransp >> t;
                cercle->setTransparence(t);

                getline(myFile, buf);
                istringstream intplanz(buf);
                int z(0);
                intplanz >> z;
                cercle->setPlanz(z);

                figures.push_back(cercle);
            }
            // cout << cpt << endl;
            // cpt++;
        }
    }
    else
    {
        cout << "Erreur" << endl;
    }
    myFile.close(); 
}

void Feuille::Tracer(CImage *img){
    cout << "taille vector : " << figures.size() << endl;
    if(figures.size()!=0){
        int z = 0;
        int i = 0;
        int plan_z = 0;
        while(i < figures.size())
        {
            for(int j = 0; j < figures.size(); j++)
            {
                if(figures.at(j)->getPlanz() == z)
                {
                    plan_z = figures.at(j)->getPlanz();
                    cout << plan_z << endl;
                    figures.at(j)->afficher(img);
                    cout << "Affiche figure " << j << endl;
                    i++;
                }
            }  
            z++;
        }
    }
    else
        cout << "Rien à afficher." << endl;
}


void Feuille::zoom(CImage *img, int e){

}


