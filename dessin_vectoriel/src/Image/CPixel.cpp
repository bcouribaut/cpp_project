/*
 *  CPixel.cpp
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include "CPixel.h"

CPixel::CPixel(int r, int g, int b){
	red   = r;
	green = g;
	blue  = b;
}

CPixel::CPixel(){
    //fond noir
	red   = 0;
	green = 0;
	blue  = 0;
}

int CPixel::Red(){
	return red;
}

void CPixel::Red(int r){
	red = (r>255)?255:r;
	red = (red>=0)?red:0;
}

int CPixel::Green(){
	return green;
}

void CPixel::Green(int g){
	green = (g>255)?255:g;
	green = (green>=0)?green:0;
}

int CPixel::Blue(){
	return blue;
}

void CPixel::Blue(int b){
	blue = (b>255)?255:b;
	blue = (blue>=0)?blue:0;
}

void CPixel::RGB(int r, int g, int b){
	Red(r);
	Green(g);
	Blue(b);
}

void CPixel::Color(string c, int t){

	if (c == "bleu")
	{
    	red = ((100-t)*red)/100;
    	green = ((100-t)*green)/100;
    	blue = ((100-t)*blue+t*255)/100;
    }
    else if (c == "rouge")
    {
        red = ((100-t)*red+t*255)/100;
        green = ((100-t)*green)/100;
        blue = ((100-t)*blue)/100;
    }
    else if (c == "vert")
    { 	
        red = ((100-t)*red)/100;
        green = ((100-t)*green+t*070)/100;
        blue = ((100-t)*blue)/100;
    }
    else if (c == "noir")
    {
        red = ((100-t)*red)/100;
        green = ((100-t)*green)/100;
        blue = ((100-t)*blue)/100;
    }
    else if (c == "jaune")
    {
        red = ((100-t)*red+t*255)/100;
        green = ((100-t)*green+t*255)/100;
        blue = ((100-t)*blue)/100;
    }
    else if (c == "gris")
    {
        red = ((100-t)*red+t*128)/100;
        green = ((100-t)*green+t*128)/100;
        blue = ((100-t)*blue+t*128)/100;
    }
    else if (c == "marron")
    {
        red = ((100-t)*red+t*128)/100;
        green = ((100-t)*green)/100;
        blue = ((100-t)*blue)/100;
    }
    else if (c == "beige")
    {
        red = ((100-t)*red+t*200)/100;
        green = ((100-t)*green+t*173)/100;
        blue = ((100-t)*blue+t*127)/100;
    }
    else if (c == "rose")
    {
        red = ((100-t)*red+t*253)/100;
        green = ((100-t)*green+t*108)/100;
        blue = ((100-t)*blue+t*158)/100;
    }
    else
    {
        red = ((100-t)*red+t*255)/100;
        green = ((100-t)*green+t*255)/100;
        blue = ((100-t)*blue+t*255)/100;
    }
}
