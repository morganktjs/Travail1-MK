#include "joueur.h"

const void Joueur::SetNom(string aNom)
{
	nom = aNom;
}

Joueur::Joueur()
{
	nom = "";
	nombreVictoire = 0;
	nombreDefaite = 0;
	for (int i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}

const void Joueur::AjouterUneCarteDansLaMain(Carte* aCarte)
{

	int i = -1;
	/*for (int i = 0; i < maxCartesAJouer; i++)
	{
		if (mainDuJoueur[i] == NULL)
		{
			mainDuJoueur[i] = aCarte;
		}
	}*/

	do
	{
		i++;
	} while (mainDuJoueur[i] != NULL);
	mainDuJoueur[i] = aCarte;


}

const void Joueur::EnleverLesCartesDeLaMain()
{
	for (int i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}

const void Joueur::AugmenterDefaite()
{
	nombreDefaite++;
}

const void Joueur::AugmenterVictoire()
{
	nombreVictoire++;
}

string Joueur::GetNom()
{
	return nom;
}

int Joueur::GetNombreVictoire()
{
	return nombreVictoire;
}

int Joueur::GetNombreDefaite()
{
	return nombreDefaite;
}

Carte * Joueur::GetCarte(int indiceTableau)
{
	return mainDuJoueur[indiceTableau];
}
