#include "carte.h"

Carte::Carte()
{
  valeur = 0;
  atout = "";
}
void Carte::InitialiserCarte(int inValeur, string inAtout)
{
	valeur = inValeur;
	atout = inAtout;
}
int Carte::GetValeur() const
{
  return valeur;
}
string Carte::GetAtout() const
{
  return atout;
}

void Carte::Afficher(int inX, int inY) const
{
	Gotoxy(inX, inY);
	cout << valeur << " " << atout;
}
