#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Affichage.h"
#include "StructureFichiers.h"
#include "Constante.h"
using namespace std;

int main()
{	
	setlocale(LC_ALL, "");
	vector <structureProduitTxt> itemEstValide;
	vector <structureInventaireTxt> itemInventaireEstValide;
	string choixUtilisateur;
	char entreeChoixUtilisateur = 'X';
	ifstream canalLectureFichierProduit;

	bool fichierProduitOuvert = ouvrir_fichier_en_lecture(canalLectureFichierProduit, FICHIER_PRODUITS, itemEstValide, itemInventaireEstValide);
	bool fichierInventaireOuvert = ouvrir_fichier_en_lecture(canalLectureFichierProduit, FICHIER_INVENTAIRE, itemEstValide, itemInventaireEstValide);
	// menu_principale()
	while (entreeChoixUtilisateur != 'Q')
	{
		afficher_menu();

		getline(cin, choixUtilisateur);

		entreeChoixUtilisateur = convertion_de_string_en_char(choixUtilisateur);

		bool entreeMenuValide = false;

		for (int i = 0; i < CHOIX_VALIDE_MENU_PRINCIPALE.size(); i++)
		{
			if (entreeChoixUtilisateur == CHOIX_VALIDE_MENU_PRINCIPALE.at(i))
			{
				entreeMenuValide = true;
			}
		}
		while (!entreeMenuValide)
		{
			afficher_menu();

			cout << "Entrez un choix valide!!" << endl;

			getline(cin, choixUtilisateur);

			entreeChoixUtilisateur = choixUtilisateur.at(0);

			entreeChoixUtilisateur = toupper(entreeChoixUtilisateur);

		}
		if (entreeChoixUtilisateur != 'Q')
		{
			redirection_sous_menu(entreeChoixUtilisateur, itemEstValide, itemInventaireEstValide);
		}
	}

	cout << "Fin du Programme. Bonne Journée!!" << endl;
}

