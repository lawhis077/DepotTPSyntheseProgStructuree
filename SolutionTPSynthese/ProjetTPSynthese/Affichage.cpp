#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Constante.h"
#include "Strings.h"
#include "ChoixSousMenu.h"
using namespace std;

void afficher_menu()
{
	system("pause");

	cout << "-----------------------------------\n";
	cout << " Marché d'alimentation L.Lamonde\n";
	cout << "-----------------------------------\n";
	cout << endl;
	cout << "L) Lister Produits\n";
	cout << "C) Charger Circulaire\n";
	cout << "R) Recevoir Marchandise\n";
	cout << "A) Effectuer Achats\n";
	cout << "Q) Quitter\n" << endl;
	cout << "Choix : " << endl;
}

void redirection_sous_menu(char entreeChoixUtilisateur, vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide)
{
	switch (entreeChoixUtilisateur)
	{
	case 'L':

		lister_produits(itemEstValide, itemInventaireEstValide);

		break;

	case 'C':

		charger_circulaire();

		break;

	case 'R':

		recevoir_marchandise();

		break;

	case 'A':

		effectuer_achat();

		break;

	case 'Q':
		break;
	}


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
	cout << "Catégorie\n" << endl;

	bool categorieSemblable = false;

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
			categorieSemblable = false;
		}
	}

	for (int i = 0; i < categorieProduit.size(); i++)
	{
		cout << i + 1 << ") " << categorieProduit.at(i);
	}

	cout << "Choix : " << endl;

	// choix_lister_produit(choixListerProduit, entreeChoixListerProduit, categorieProduit, itemEstValide, itemInventaireEstValide);
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
