#include "joueur.h"

- void Joueur::SetNom(string aNom)
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

void Joueur::AjouterUneCarteDansLaMain(Carte* aCarte)
{
	for (int i = 0; i < maxCartesAJouer; i++)
	{
		if (mainDuJoueur[i] == NULL)
		{
			mainDuJoueur[i] = aCarte;
		}
	}
}

void Joueur::EnleverLesCartesDeLaMain()
{
	for (int i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}

void Joueur::AugmenterDefaite()
{
	nombreDefaite++;
}

void Joueur::AugmenterVictoire()
{
	nombreVictoire++;
}