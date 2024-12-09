#include "VerfierErreurFichier.h"
#include <fstream>
#include <vector>
#include <string>
#include "Affichage.h"
#include "StructureFichiers.h"
#include "Constante.h"
#include "Utilitaire.h"
#include "Strings.h"
using namespace std;
void verifier_fichier_produit(ifstream& canalLectureFichier, vector<string>& itemProduit, vector<structureProduitTxt>& itemProduitEstValide, string nomFichier)
{
	int compteurLigne = 0;

	string ligneProduitTxt;

	ifstream canalLectureProduit;

	bool erreurFichierProduit = false;

	while (getline(canalLectureProduit, ligneProduitTxt))
	{
		compteurLigne++;
		rogner_espaces(ligneProduitTxt);

		if (ligneProduitTxt.at(0) != CARACTERE_COMMENTAIRE)
		{
			itemProduit = separer(ligneProduitTxt, SEPARATEUR_PRODUITS);
			rogner_espaces_vecteur(itemProduit);

			if (itemProduit.size() != NOMBRE_VALEURS_PRODUITS)
			{
				erreurFichierProduit = true;
			}

			structureProduitTxt produit;
			ajuster_produit(itemProduit, produit);

			if (produit.codeProduit < 0)
			{
				erreurFichierProduit = true;
			}

			if (produit.quantiteProduit < 0 || (produit.quantiteProduit != 0 && produit.uniteProduit != UNITE_POSSIBLE.at(0)))
			{
				erreurFichierProduit = true;
			}

			bool uniteEstValide = false;

			for (int i = 0; i < UNITE_POSSIBLE.size(); i++)
			{
				if (produit.uniteProduit == UNITE_POSSIBLE.at(i))
				{
					uniteEstValide = true;
				}
			}

			if (uniteEstValide == false)
			{
				erreurFichierProduit = true;
			}

			if (itemProduit.at(5) != "oui" || itemProduit.at(5) != "non")
			{
				erreurFichierProduit = true;
			}

			if (produit.prixProduit < 0)
			{
				erreurFichierProduit = true;
			}

			if (erreurFichierProduit)
			{
				cout << "Erreur à la ligne " << compteurLigne;
			}
			else
			{
				itemProduitEstValide.push_back(produit);
			}
		}
	}
}

void verifier_fichier_inventaire(ifstream& canalLectureFichier, vector<string>& itemInventaire, vector<structureInventaireTxt>& itemInventaireEstValide, string nomFichier)
{
	int compteurLigne = 0;

	string ligneInventaireTxt;

	ifstream canalLectureInventaire;

	bool erreurFichierInventaire = false;

	while (getline(canalLectureInventaire, ligneInventaireTxt))
	{
		structureInventaireTxt inventaire;
		compteurLigne++;

		itemInventaire = separer(ligneInventaireTxt, SEPARATEUR_INVENTAIRE);

		if (itemInventaire.size() != NOMBRE_VALEURS_INVENTAIRE)
		{
			erreurFichierInventaire = true;
		}

		ajuster_inventaire(itemInventaire, inventaire);

		if (inventaire.codeProduitInventaire < 0)
		{
			erreurFichierInventaire = true;
		}
		if (inventaire.nombreProduitInventaire < 0)
		{
			erreurFichierInventaire = true;
		}
		if (!erreurFichierInventaire)
		{
			itemInventaireEstValide.push_back(inventaire);
		}
		
	}
}
