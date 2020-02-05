#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
	public:
	Carte paquetDeCarte[52];
	Joueur Joueur1;
	Joueur Joueur2;
	Donnees();
	const void InitialiserCartes();
};

