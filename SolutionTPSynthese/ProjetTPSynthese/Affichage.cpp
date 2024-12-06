#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Constante.h"
#include "FonctionsLCRE.h"

using namespace std;

void afficher_menu()
{
	system("pause");

	cout << "-----------------------------------\n";
	cout << " March� d'alimentation L.Lamonde\n";
	cout << "-----------------------------------\n";
	cout << endl;
	cout << "L) Lister Produits\n";
	cout << "C) Charger Circulaire\n";
	cout << "R) Recevoir Marchandise\n";
	cout << "A) Effectuer Achats\n";
	cout << "Q) Quitter\n" << endl;
	cout << "Choix : " << endl;
}

void lister_produits(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide)
{
	string choixListerProduit;
	char entreeChoixListerProduit;
	vector <string> categorieProduit;
	cout << endl;
	system("pause");

	cout << "-----------------------------------\n";
	cout << " Afficher la liste de produits\n";
	cout << "-----------------------------------\n";
	cout << endl;
	cout << "*) Tous les produits\n";
	cout << "C) Circulaire\n " << endl;
	cout << "Cat�gorie\n" << endl;

	bool categorieSemblable;

	for (int i = 0; i < itemEstValide.size(); i++)
	{
		for (int ii = 0; ii < categorieProduit.size(); ii++)
		{
			if (itemEstValide.at(i).categorieProduit == categorieProduit.at(ii))
			{
				categorieSemblable = true;
			}
			if (!categorieSemblable)
			{
				categorieProduit.push_back(itemEstValide.at(i).categorieProduit);
			}
		}
	}

	for (int i = 0; i < categorieProduit.size(); i++)
	{
		cout << i << ") " << categorieProduit.at(i);
	}
	cout << "Choix : " << endl;
	
	getline(cin, choixListerProduit);
	
	// Si isdigit et <= categorieProduit.size()

	entreeChoixListerProduit = convertion_de_string_en_char(choixListerProduit);

	entreeChoixListerProduit = toupper(entreeChoixListerProduit);

	bool choixValide = false;

	

	for (int i = 0; i < CHOIX_VALIDE_LISTER_PRODUIT.size(); i++)
	{
		if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(i))
		{
			choixValide = true;
		}
	}

	while (!choixValide)
	{
		cout << "Erreur!! Mauvaise entr�e de donn�e\n";
		cout << "Choix : " << endl;

		getline(cin, choixListerProduit);

		for (int i = 0; i < CHOIX_VALIDE_LISTER_PRODUIT.size(); i++)
		{
			if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(i))
			{
				choixValide = true;
			}
		}
	}

	operation_lister_produit(entreeChoixListerProduit);
}

void charger_circulaire()
{
}

void recevoir_marchandise()
{
	cout << endl;
	system("pause");

	cout << "-----------------------------------\n";
	cout << " Recevoir Marchandise\n";
	cout << "-----------------------------------\n";
	cout << endl;
	cout << "Entrez le code du produit";
	cout << "Choix : " << endl;
}

void effectuer_achat()
{
	char choixAchats;

	cout << endl;
	system("pause");

	cout << "-----------------------------------\n";
	cout << "		Effectuer des achats\n";
	cout << "-----------------------------------\n";
	cout << endl;
	cout << "Sous total: ";
	cout << "- 'L' pour lister les produits" << endl; 
	cout << "- 'A' pour annuler la facture" << endl;
	cout << ">" << endl;
}
