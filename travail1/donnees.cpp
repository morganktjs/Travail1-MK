#include "donnees.h"


Donnees::Donnees()
{
	InitialiserCartes();
}


void Donnees::InitialiserCartes()
{
	int cpt = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{

			Carte newCarte;
			if (i == 0)
			{
				newCarte.InitialiserCarte(j, "coeur");
				paquetDeCarte[cpt] = newCarte;
			}
			else if (i == 1)
			{
				newCarte.InitialiserCarte(j, "carreau");
				paquetDeCarte[cpt] = newCarte;
			}
			else if (i == 2)
			{
				newCarte.InitialiserCarte(j, "pique");
				paquetDeCarte[cpt] = newCarte;
			}
			else if (i == 3)
			{
				newCarte.InitialiserCarte(j, "trefle");
				paquetDeCarte[cpt] = newCarte;
			}
			cpt++;
		}
	}
}
