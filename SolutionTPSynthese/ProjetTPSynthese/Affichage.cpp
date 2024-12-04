#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"


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

void lister_produits()
{
	string choixListerProduit;
	char entreeChoixListerProduit;

	cout << endl;
	system("pause");

	cout << "-----------------------------------\n";
	cout << " Afficher la liste de produits\n";
	cout << "-----------------------------------\n";
	cout << endl;
	cout << "*) Tous les produits\n";
	cout << "C) Circulaire\n " << endl;
	cout << "Catégorie\n" << endl;
	cout << " 1) Farine et grains\n";
	cout << " 2) Prêt à manger\n" ;
	cout << " 3) Viandes et substituts\n" << endl << endl;
	cout << "Choix : " << endl;
	


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

	getline(cin, choixAchats);

	while (choixAchats != 'L' && choixAchats != 'A')
	{
		cout << endl;
		system("cls");

		cout << "-----------------------------------\n";
		cout << "		Effectuer des achats\n";
		cout << "-----------------------------------\n";
		cout << endl;
		cout << "Sous total: ";
		cout << "- 'L' pour lister les produits" << endl;
		cout << "- 'A' pour annuler la facture" << endl;
		cout << "Entrez un choix valide !!" << endl;
		cout << ">" << endl;

	}

}
