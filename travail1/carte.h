#include <string>
using namespace std;

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef carteH
#define carteH

class Carte
{
  private:
    int valeur;  //chiffre
    string atout;  //pique, coeur, trèfle ou carreau
  public:
    Carte();
	void InitialiserCarte(int, string);
    int GetValeur() const;
    string GetAtout() const;
	void Afficher(int X, int Y) const;
};

#endif
 