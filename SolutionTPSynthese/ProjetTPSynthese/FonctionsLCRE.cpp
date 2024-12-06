#include "FonctionsLCRE.h"
#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Constante.h"

using namespace std;
void operation_lister_produit(char choixUtilisateur)
{

	switch (choixUtilisateur)
	{
	case '*':

		lister_tous_les_produits();

		break;

	case 'C':

		lister_circulaire();

		break;

	case '1':

		lister_farine_et_grains();

		break;

	case '2':

		lister_pret_a_manger();

		break;

	case '3':

		lister_viandes_et_substituts();

		break;
	}

}

void lister_tous_les_produits(char choixUtilisateur)
{
	int compteurElementListe = 0;
	while (choixUtilisateur != 'R')
	{
		
	
		// Envoyer le fichier itemEstValide sur la fonction
		for (compteurElementListe; compteurElementListe < 10; compteurElementListe++)
		{
			system("cls");

			// Cout << itemEstValide.nom.at(i); etc...
		}

		system("pause");
		cout << "Que voulez-vous faire? Entrez ";
	}
}

void lister_circulaire()
{
}

void lister_farine_et_grains()
{
}

void lister_pret_a_manger()
{
}

void lister_viandes_et_substituts()
{
}
