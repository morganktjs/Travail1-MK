#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;

void InitialiserJoueurs();
void Jouer();

int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
}

void Jouer() 
{

}

void InitialiserJoueurs()
{
	string nom = "";

	cout << "\nQuel est le nom du premier joueur ?";
	cin >> nom;
	leJeu.Joueur1.SetNom(nom);
	cout << "\nQuel est le nom du deuxieme joueur ?";
	cin >> nom;
	leJeu.Joueur2.SetNom(nom);
}
