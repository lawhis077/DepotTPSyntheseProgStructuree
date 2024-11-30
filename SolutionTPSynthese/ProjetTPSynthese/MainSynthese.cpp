#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Affichage.h"
using namespace std;

const string FICHIER_PRODUITS = "Produit.txt";
int compteurLettres = 0;

int main()
{
	setlocale(LC_ALL, "");

	ifstream canalLectureFichierProduit;

	string choixUtilisateur;

	afficher_menu();

	bool fichierProduitOuvert = ouvrir_fichier_en_lecture(canalLectureFichierProduit, FICHIER_PRODUITS);
}