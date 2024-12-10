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

	while (getline(canalLectureFichier, ligneProduitTxt))
	{
		bool erreurFichierProduit = true;
		compteurLigne++;
		rogner_espaces(ligneProduitTxt);

		if (ligneProduitTxt.size() > 0 && ligneProduitTxt.at(0) != CARACTERE_COMMENTAIRE)
		{
			itemProduit = separer(ligneProduitTxt, SEPARATEUR_PRODUITS);
			rogner_espaces_vecteur(itemProduit);

			if (itemProduit.size() == NOMBRE_VALEURS_PRODUITS)
			{
				structureProduitTxt produit;
				ajuster_produit(itemProduit, produit);

				if (produit.codeProduit >= 0)
				{

						bool uniteEstValide = false;

						for (int i = 0; i < UNITE_POSSIBLE.size(); i++)
						{
							if (produit.uniteProduit == UNITE_POSSIBLE.at(i))
							{
								uniteEstValide = true;
							}
						}

						if (uniteEstValide == true)
						{
							if (itemProduit.at(5) == "oui" || itemProduit.at(5) == "non")
							{
								if (produit.prixProduit > 0)
								{
									itemProduitEstValide.push_back(produit);
									erreurFichierProduit = false;
								}
							}
						}
					
				}
			}

			if (erreurFichierProduit)
			{
				cout << "Erreur à la ligne " << compteurLigne << endl;
			}

		}
	}
}

void verifier_fichier_inventaire(ifstream& canalLectureFichier, vector<string>& itemInventaire, vector<structureInventaireTxt>& itemInventaireEstValide, string nomFichier)
{
	int compteurLigne = 0;

	string ligneInventaireTxt;

	while (getline(canalLectureFichier, ligneInventaireTxt))
	{
		structureInventaireTxt inventaire;
		compteurLigne++;

		itemInventaire = separer(ligneInventaireTxt, SEPARATEUR_INVENTAIRE);

		if (itemInventaire.size() == NOMBRE_VALEURS_INVENTAIRE)
		{
			ajuster_inventaire(itemInventaire, inventaire);

			if (inventaire.codeProduitInventaire > 0)
			{
				if (inventaire.nombreProduitInventaire > 0)
				{
					itemInventaireEstValide.push_back(inventaire);
				}
			}
		}	
	}
}
