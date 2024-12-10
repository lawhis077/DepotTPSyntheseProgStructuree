#include "ChoixSousMenu.h"

void choix_lister_produit(string& choixListerProduit, char& entreeChoixListerProduit, vector<string> categorieProduit, vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide)
{
	int choixUtilisateurEnInt = 99;
	int repetitionErreur = 0;
	bool choixValide = false;

	while (!choixValide)
	{
		repetitionErreur++;
		if (repetitionErreur > 1)
		{
			cout << "Erreur!! Mauvaise entrée de donnée\n" << endl;
		}
		getline(cin, choixListerProduit);

		entree_utilisateur(choixListerProduit, entreeChoixListerProduit);

		if (isdigit(entreeChoixListerProduit))
		{
			extraire_entier(choixListerProduit, choixUtilisateurEnInt);
		}

		for (int i = 0; i < CHOIX_VALIDE_LISTER_PRODUIT.size(); i++)
		{
			if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(i) || choixUtilisateurEnInt <= categorieProduit.size() - 1)
			{
				choixValide = true;
			}
		}
	}

	operation_lister_produit(choixListerProduit, entreeChoixListerProduit, choixUtilisateurEnInt, categorieProduit, itemEstValide, itemInventaireEstValide);
}
