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
	string ligneInventaireTxt;

	while (getline(canalLectureFichier, ligneInventaireTxt))
	{
		structureInventaireTxt inventaire;
		bool estInvalide = false;

		itemInventaire = separer(ligneInventaireTxt, SEPARATEUR_INVENTAIRE);

		rogner_espaces_vecteur(itemInventaire);

		for (int i = 0; i < itemInventaire.size(); i++)
		{
			for (int ii = 0; ii < itemInventaire.at(i).size(); ii++)
			{
				if (!isdigit(itemInventaire.at(i).at(ii)))
				{
					estInvalide = true;
				}
			}
		}

		if (itemInventaire.size() == NOMBRE_VALEURS_INVENTAIRE && !estInvalide)
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

void verifier_fichier_circulaire(ifstream& canalLectureFichier, vector<string>& itemCirculaire, vector<structureCirculaireTxt>& itemCirculaireEstValide, string nomFichier, int& compteurEntreeValide)
{
	string ligneCirculaireTxt;
	compteurEntreeValide = 0;
	while (getline(canalLectureFichier, ligneCirculaireTxt))
	{
		structureCirculaireTxt circulaire;

		bool estInvalide = false;

		itemCirculaire = separer(ligneCirculaireTxt, SEPARATEUR_CIRCULAIRE);

		rogner_espaces_vecteur(itemCirculaire);

		for (int i = 0; i < itemCirculaire.size(); i++)
		{
			for (int ii = 0; ii < itemCirculaire.at(i).size(); ii++)
			{
				if (!isdigit(itemCirculaire.at(i).at(ii)))
				{
					estInvalide = true;
				}
			}
		}

		if (itemCirculaire.size() == NOMBRE_VALEURS_CIRCULAIRE && !estInvalide)
		{
			ajuster_circulaire(itemCirculaire, circulaire);

			if (circulaire.codeProduitCirculaire > 0)
			{
				if (circulaire.pourcentageRabaisCirculaire > 0)
				{
					compteurEntreeValide++;
					itemCirculaireEstValide.push_back(circulaire);
				}
			}
		}
	}
}
