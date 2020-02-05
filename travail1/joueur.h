#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{
private:
	string nom;
	int nombreVictoire;
	int nombreDefaite;
	Carte* mainDuJoueur[26];

public:
	Joueur();
	const void SetNom(string aNom);
	string GetNom();
	int GetNombreVictoire();
	int GetNombreDefaite();
	Carte * GetCarte(int indiceTableau);
	const void AjouterUneCarteDansLaMain(Carte* aCarte);
	const void EnleverLesCartesDeLaMain();
	const void AugmenterVictoire();
	const void AugmenterDefaite();
};
#endif