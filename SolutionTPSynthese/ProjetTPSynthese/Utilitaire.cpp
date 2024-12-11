#include "Utilitaire.h"
#include "Strings.h"
#include "StructureFichiers.h"
#include "Constante.h"
#include "VerfierErreurFichier.h"

bool ouvrir_fichier_en_lecture(ifstream& canalLectureFichier, string nomFichier, vector <structureProduitTxt>& itemProduitEstValide, vector <structureInventaireTxt>& itemInventaireEstValide)
{
	
	vector <string> itemProduit;
	vector <string> itemInventaire;

	canalLectureFichier.open(nomFichier);

	if (canalLectureFichier.is_open())
	{

		if (nomFichier == FICHIER_PRODUITS)
		{
			verifier_fichier_produit(canalLectureFichier, itemProduit, itemProduitEstValide, nomFichier);
		}

		if (nomFichier == FICHIER_INVENTAIRE)
		{
			verifier_fichier_inventaire(canalLectureFichier, itemInventaire, itemInventaireEstValide, nomFichier);
			
		}

		canalLectureFichier.close();
		return true;
	}
	else
	{
		
		return false;

	}
}


bool ouvrir_fichier_en_ecriture(ofstream& canalEcritureFichier, string nomFichier, bool ajouterALaFin)
{
	if (ajouterALaFin)
	{
		canalEcritureFichier.open(nomFichier, ofstream::app);
	} 
	else
	{
		canalEcritureFichier.open(nomFichier);
	}

	if (canalEcritureFichier.is_open())
	{
		return true;
	}
	else
	{
		cout << "ERREUR: Fichier non-disponible!!\n";
		return false;
	}

}

char convertion_de_string_en_char(string& choixUtilisateur)
{
	char entreeChoixUtilisateur;
	bool estValide = false;

	while (!estValide)
	{
		if (!choixUtilisateur.empty())
		{
			if (choixUtilisateur.size() == 1)
			{
				entreeChoixUtilisateur = choixUtilisateur.at(0);
				entreeChoixUtilisateur = toupper(entreeChoixUtilisateur);
				estValide = true;
			}
		
		}
		else
		{
			cout << "Erreur de l'entrée de donnée, veuillez entrer un seul caractère!! \n";
			getline(cin, choixUtilisateur);
		}
	}
	return entreeChoixUtilisateur;
}

void rogner_espaces_vecteur(vector<string>& vecteurAvecEspace)
{
	for (int i = 0; i < vecteurAvecEspace.size(); i++)
	{
		rogner_espaces(vecteurAvecEspace.at(i));
	}
}

void ajuster_produit(vector <string> itemProduit, structureProduitTxt& produit)
{
	extraire_entier(itemProduit.at(0), produit.codeProduit);
	produit.categorieProduit = itemProduit.at(1);
	produit.nomProduit = itemProduit.at(2);
	extraire_entier(itemProduit.at(3), produit.quantiteProduit);
	produit.uniteProduit = itemProduit.at(4);
	produit.estTaxable = itemProduit.at(5);
	extraire_entier(itemProduit.at(6), produit.prixProduit);
}

void ajuster_inventaire(vector<string> itemInventaire, structureInventaireTxt& inventaire)
{
	extraire_entier(itemInventaire.at(0), inventaire.codeProduitInventaire);
	extraire_entier(itemInventaire.at(1), inventaire.nombreProduitInventaire);
}

void ajuster_circulaire(vector<string> itemCirculaire, structureCirculaireTxt& circulaire)
{
	extraire_entier(itemCirculaire.at(0), circulaire.codeProduitCirculaire);
	extraire_entier(itemCirculaire.at(1), circulaire.pourcentageRabaisCirculaire);
}

void entree_utilisateur(string& stringChoix, char& charChoix)
{
	charChoix = convertion_de_string_en_char(stringChoix);

	stringChoix.clear();

	stringChoix.push_back(charChoix);
}

