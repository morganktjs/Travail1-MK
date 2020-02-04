#include "donnees.h"


Donnees::Donnees()
{
	InitialiserCartes();
}


void Donnees::InitialiserCartes()
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Carte newCarte;
			switch (i)
			{
			case 0:
				newCarte.InitialiserCarte(j, "coeur");
			case 1:
				newCarte.InitialiserCarte(j, "carreau");
			case 2:
				newCarte.InitialiserCarte(j, "pique");
			case 3:
				newCarte.InitialiserCarte(j, "trèfle");
			}	
		}
	}
}
