#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Figures/Figures.h"
#include "./Figures/Point.h"
#include "./Figures/Ligne.h"
#include "Feuille.h"


int main(int argc, char * argv[]) {
    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;

    // int h = 0;
    // int l = 0;
    // cout << "Quelle taille d'image désirez-vous ? (Hauteur*Longueur)" << endl << "Hauteur : ";
    // cin >> h;
    // cout << "Longueur : ";
    // cin >> l;

    // CImage *img = new CImage(h, l);

    CImage *img = new CImage(204, 204);
    Feuille *feuille = new Feuille();

    if(argc == 1)
    {
        string forme = "";

        int i =1;
        string reponse = "";

        while(i!=0)
        {
            cout << "Quelle figure voulez-vous ajouter ?" << endl << "(Point, Ligne, Rectangle, RectangleS, Carre, CarreS, Cercle, CercleS)" << endl;
            cin >> forme;

            if ((forme.compare("Point") == 0)||(forme.compare("Ligne") == 0)||(forme.compare("Rectangle") == 0)||(forme.compare("RectangleS") == 0)||(forme.compare("Carre") == 0)||(forme.compare("CarreS") == 0)||(forme.compare("Cercle") == 0)||(forme.compare("CercleS") == 0))
            {    
                feuille->ajouter_forme(forme);
            }
            else
            {
                cout << "Erreur : forme incorrecte." << endl;
            }
            
            cout << "Voulez-vous ajouter une autre figure ? (oui ou non)" << endl;
            cin >> reponse;

            if(reponse.compare("oui") == 0)
            {
                i = 1;
            }
            else
            {
                i = 0;
            }
        }
    }

    else
    {
        filename2 = argv[2];

        string filename = argv[1];
        feuille->loadFromFile(filename);
    }


    feuille->Tracer(img);
    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    // img->~CImage();
    // delete feuille;

    return 1;
}