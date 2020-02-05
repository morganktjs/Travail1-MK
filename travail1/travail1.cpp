#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <limits> 
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;
int nombreDeCarteDansLePaquet = 52;

void InitialiserJoueurs();
int Afficher(Joueur aJoueur);
void DistribuerLesCartes(int aNombreDeCarteADistribuer);
void Jouer();
int DemanderNombreDeCarteADistribuer();
void MelangerLePaquet();
void AugmenterVictoireEtDefaite(int aResultatJoueur1, int aResultatJoueur2);
void AfficherMessageDeFinDePartie();

int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		ClrScr();
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;
		
	}
	ClrScr();
	AfficherMessageDeFinDePartie();
}

void Jouer() 
{
	int resultatJoueur1;
	int resultatJoueur2;
	int nombreDeCarteADistribuer = DemanderNombreDeCarteADistribuer();
	ClrScr();
	MelangerLePaquet();
	DistribuerLesCartes(nombreDeCarteADistribuer);
	resultatJoueur1 = Afficher(leJeu.Joueur1);
	resultatJoueur2 = Afficher(leJeu.Joueur2);
	AugmenterVictoireEtDefaite(resultatJoueur1, resultatJoueur2);
	leJeu.Joueur1.EnleverLesCartesDeLaMain();
	leJeu.Joueur2.EnleverLesCartesDeLaMain();
}

void InitialiserJoueurs()
{
	string nom = "";
	cout << "Quel est le nom du premier joueur ? \n";
	cin >> nom;
	leJeu.Joueur1.SetNom(nom);
	cout << "Quel est le nom du deuxieme joueur ? \n";
	cin >> nom;
	leJeu.Joueur2.SetNom(nom);
}

int DemanderNombreDeCarteADistribuer()
{
	int aNombreDeCarteADistribuer;

	cout << "Combien de carte faut-il distribuer \n";
	while (!((std::cin >> aNombreDeCarteADistribuer) && (aNombreDeCarteADistribuer > 0) && (aNombreDeCarteADistribuer < 27)))
	{
		if (std::cin.fail())
		{
			std::cout << "Saisie incorrecte, recommencez : ";
			std::cin.clear();
			std::cin.ignore(1500, '\n');
		}
		else
		{
			std::cout << "Le chiffre n'est pas entre 1 et 26, recommencez : ";
		}
	}
	return aNombreDeCarteADistribuer;
}

void MelangerLePaquet()
{
	srand(time(NULL));
	int i, j;
	Carte tempo;

	for (int cpt = 0; cpt < 4; cpt++)
	{
		for (i = 0; i < nombreDeCarteDansLePaquet - 1; i++)
		{
			j = i + rand() % (nombreDeCarteDansLePaquet - i);
			tempo = leJeu.paquetDeCarte[i];
			leJeu.paquetDeCarte[i] = leJeu.paquetDeCarte[j];
			leJeu.paquetDeCarte[j] = tempo;
		}
	}

}

void DistribuerLesCartes(int aNombreDeCarteADistribuer)
{
	int idJoueur=1;
	for (int i = 0; i < aNombreDeCarteADistribuer*2 ; i++)
	{
		if (idJoueur == 1)
		{
			leJeu.Joueur1.AjouterUneCarteDansLaMain(&leJeu.paquetDeCarte[i]);
			idJoueur = 2;
		}
		else
		{
			leJeu.Joueur2.AjouterUneCarteDansLaMain(&leJeu.paquetDeCarte[i]);
			idJoueur = 1;
		}
	}

}

void AugmenterVictoireEtDefaite(int aResultatJoueur1, int aResultatJoueur2)
{
	if (aResultatJoueur1 > aResultatJoueur2)
	{
		leJeu.Joueur1.AugmenterVictoire();
		leJeu.Joueur2.AugmenterDefaite();
		cout << "Bien joue " << leJeu.Joueur1.GetNom() << " tu gagnes cette partie";
	}
	else
	{
		leJeu.Joueur2.AugmenterVictoire();
		leJeu.Joueur1.AugmenterDefaite();
		cout << "Bien joue " << leJeu.Joueur2.GetNom() << " tu gagnes cette partie";
	}
}

void AfficherMessageDeFinDePartie()
{
	cout << "Voici les stats des joueurs : \n";
	cout << leJeu.Joueur1.GetNom() << " :\n" << "- " << leJeu.Joueur1.GetNombreVictoire() << " victoire(s)\n" << "- " << leJeu.Joueur1.GetNombreDefaite() << " defaite(s)\n\n";
	cout << leJeu.Joueur2.GetNom() << " :\n" << "- " << leJeu.Joueur2.GetNombreVictoire() << " victoire(s)\n" << "- " << leJeu.Joueur2.GetNombreDefaite() << " defaite(s)\n\n";
	if (leJeu.Joueur1.GetNombreVictoire() > leJeu.Joueur2.GetNombreVictoire())
	{
		cout << "Bien joue " << leJeu.Joueur1.GetNom() << " tu gagnes le jeu";
	}
	else
	{
		cout << "Bien joue " << leJeu.Joueur2.GetNom() << " tu gagnes le jeu";
	}
}

int Afficher(Joueur aJoueur)
{
	int i = 0;
	int resultat = 0;
	cout << aJoueur.GetNom() << "\n";
	while (aJoueur.GetCarte(i) != NULL)
	{
		resultat += aJoueur.GetCarte(i)->GetValeur();
		cout << "- " << aJoueur.GetCarte(i)->GetValeur() << " " << aJoueur.GetCarte(i)->GetAtout() << "\n";
		i++;
	}
	cout << "Le total de " << aJoueur.GetNom() << " est de " << resultat << "\n\n";

	return resultat;
}