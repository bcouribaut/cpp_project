#include "Cercle.h"
#include "Figures.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//Constructeur
Cercle::Cercle(string f, int x, int y, int r, string c, int t, int z){
    Figures(f, x, y, c, t, z);
    rayon = r;
}

Cercle::Cercle(){
    rayon = 0;
}


//Getters
int Cercle::getRayon(){
    return rayon;
}


//Setters
void Cercle::setRayon(int r){
    rayon = r;
}

void Cercle::ajouter(){
    Figures::ajouter();

    cout << "Rayon : ";
    cin >> rayon;
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


void Cercle::afficher(CImage *img){
    CPixel *p = new CPixel();
    if(forme.compare("Cercle") == 0)
    {
        int x = 0;
        int y = rayon;
        int d = rayon-1;

        while(y >= x)
        {
            p = img->getPixel(coordx + x, coordy + y);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx + y, coordy + x);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx - x, coordy + y);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx - y, coordy + x);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx + x, coordy - y);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx + y, coordy - x);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx - x, coordy - y);
            p->Color(couleur, transparence);
            p = img->getPixel(coordx - y, coordy - x);
            p->Color(couleur, transparence);

            if(d >= 2*x)
            {
                d = d-2*x+1;
                x++;
            }
            else if(d < (2*(rayon-y)))
            {
                d = d+2*y-1;
                y--;
            }
            else
            {
                d = d+2*(y-x-1);
                y--;
                x++;
            }
        }
    }

    else if(forme.compare("CercleS") == 0)
    {       
        // int d = rayon-1;
        // int a = rayon-1;
        // int b = 0;
        // CPixel *p = new CPixel();

        // while(a >= b)
        // {
        //     for (int i = -a; i <= a; i++)
        //     {
        //         p = img->getPixel(coordx + b, coordy + i);
        //         p->Color(couleur, transparence);    
        //     }
        //     for (int j = -b; j <= b; j++)
        //     {
        //         p = img->getPixel(coordx + a, coordy + j);
        //         p->Color(couleur, transparence);   
        //     }
        //     for (int k = -a; k <= a; k++)
        //     {
        //         p = img->getPixel(coordx - b, coordy + k);
        //         p->Color(couleur, transparence);   
        //     }
        //     for (int m = -b; m <= b; m++)
        //     {
        //         p = img->getPixel(coordx - a, coordy + m);
        //         p->Color(couleur, transparence);   
        //     }
        //     if(d >= 2*b)
        //     {
        //          d = d-2*b-1;
        //          b++;
        //     }
        //     else if(d < 2*(rayon-a))
        //     {
        //          d = d+2*a-1;
        //          a--;
        //     }    
        //     else
        //     {     
        //          d = d+2*(a-b-1);
        //          a--;
        //          b++;
        //     }
        // }

        int d, y, x;


        d = 3 - (2 * rayon);
        x = 0;
        y = rayon;

        while (y >= x) 
        {
           for (int i = 0; i < 2*x+1; i++)
            {
                p = img->getPixel(coordx - x + i, coordy - y);
                p->Color(couleur, transparence);    
            }
            for (int j = 0; j < 2*x+1; j++)
            {
                p = img->getPixel(coordx - x + j, coordy + y);
                p->Color(couleur, transparence);   
            }
            for (int k = 0; k < 2*y+1; k++)
            {
                p = img->getPixel(coordx - y + k, coordy - x);
                p->Color(couleur, transparence);   
            }
            for (int m = 0; m < 2*y+1; m++)
            {
                p = img->getPixel(coordx - y + m, coordy + x);
                p->Color(couleur, transparence); 
            }

            if (d < 0)
                d = d + (4 * x) + 6;

            else 
            {
                d = d + 4 * (x - y) + 10;
                y--;
            }

        x++;
        }
    }
}
