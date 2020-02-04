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
	void SetNom(string aNom);
	void AjouterUneCarteDansLaMain(Carte* aCarte);
	void EnleverLesCartesDeLaMain();
};
#endif