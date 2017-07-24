#nom de l'executable
NAMEPROG=Dessin 

#parametres
CXX=g++
CPPFLAGS=-std=c++11 -g
LDFLAGS= -g
LDLIBS=

#sources et objets
SRCS=main.cpp Feuille.cpp Figures/Carre.cpp Figures/Cercle.cpp Figures/Figures.cpp Figures/Ligne.cpp Figures/Point.cpp Figures/Rectangle.cpp Format/CBitmap.cpp Image/CImage.cpp Image/CLigne.cpp Image/CPixel.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(NAMEPROG)

$(NAMEPROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAMEPROG) $^ $(LDLIBS)

main.o: $(SRCS)

Feuille.o: Feuille.cpp Feuille.h

Carre.o: Carre.cpp Carre.h

Cercle.o: Cercle.cpp Cercle.h

Figures.o: Figures.cpp Figures.h

Ligne.o: Ligne.cpp Ligne.h

Point.o: Point.cpp Point.h

Rectangle.o: Rectangle.cpp Rectangle.h

CBitmap.o: CBitmap.cpp CBitmap.h

CImage.o: CImage.cpp CImage.h

CLigne.o: CLigne.cpp CLigne.h

CPixel.o: CPixel.cpp CPixel.h

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f tool