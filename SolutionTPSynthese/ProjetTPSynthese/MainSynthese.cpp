#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Affichage.h"
#include "StructureFichiers.h"
using namespace std;

const string FICHIER_PRODUITS = "Produit.txt";
int compteurLettres = 0;

int main()
{
	// 7/12 -- Terminer Lister
	// 8/12 -- Terminer Circulaire
	// 9/12 -- Terminer Recevoir Marchandise
	// 10/12 -- Effectuer Achat Terminer / Bugfixing

	vector <structureProduitTxt> itemEstValide;
	vector <structureInventaireTxt> itemInventaireEstValide;
	setlocale(LC_ALL, "");

	ifstream canalLectureFichierProduit;

	// String to char???

	string choixUtilisateur;
	char entreeChoixUtilisateur = 'Q';

	// Quest-ce qui constitue une erreur dans la ligne ( < 0 ?) 
	bool fichierProduitOuvert = ouvrir_fichier_en_lecture(canalLectureFichierProduit, FICHIER_PRODUITS, itemEstValide, itemInventaireEstValide);

	afficher_menu();

	getline(cin, choixUtilisateur);

	entreeChoixUtilisateur = convertion_de_string_en_char(choixUtilisateur);


	while (entreeChoixUtilisateur != 'L' && 
		entreeChoixUtilisateur != 'C' && 
		entreeChoixUtilisateur != 'R' ||
		entreeChoixUtilisateur != 'A' ||
		entreeChoixUtilisateur != 'Q')
	{
		afficher_menu();

		cout << "Entrez un choix valide!!" << endl;

		getline(cin, choixUtilisateur);

		entreeChoixUtilisateur = choixUtilisateur.at(0);

		entreeChoixUtilisateur = toupper(entreeChoixUtilisateur);
	}

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

