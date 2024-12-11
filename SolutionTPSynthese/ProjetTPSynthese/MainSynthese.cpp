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
	vector <structureCirculaireTxt> itemCirculaireEstValide;

	ifstream canalLectureFichier;

	bool fichierProduitOuvert = ouvrir_fichier_en_lecture(canalLectureFichier, FICHIER_PRODUITS, itemEstValide, itemInventaireEstValide);
	bool fichierInventaireOuvert = ouvrir_fichier_en_lecture(canalLectureFichier, FICHIER_INVENTAIRE, itemEstValide, itemInventaireEstValide);

	if (fichierProduitOuvert && fichierInventaireOuvert)
	{
		menu_principale(itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
	}
	else
	{
		if (!fichierProduitOuvert)
		{
			cout << "Erreur de l'ouverture du fichier " << FICHIER_PRODUITS << endl;
		}
		if (!fichierInventaireOuvert)
		{
			cout << "Erreur de l'ouverture du fichier " << FICHIER_INVENTAIRE << endl;
		}
	}

	cout << "Fin du Programme. Bonne Journée!!" << endl;
}

