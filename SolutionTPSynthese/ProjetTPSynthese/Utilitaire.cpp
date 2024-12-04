#include "Utilitaire.h"

bool ouvrir_fichier_en_lecture(ifstream& canalLectureFichier, string nomFichier)
{
	canalLectureFichier.open(nomFichier);

	ifstream canalLectureProduit;

	string ligneProduitTxt;
	string ligneInventaireTxt;

	int compteurLigne = 0;

	if (canalLectureFichier.is_open())
	{
		
		if (nomFichier == "Produits.txt")
		{
			while (getline(canalLectureProduit, ligneProduitTxt))
			{
				if (ligneProduitTxt.at(0) != '#')
				{
					compteurLigne++;
				}

				// Ligne invalide?
			}
		}
		
		if (nomFichier == "Inventaire.txt")
		{
			while (getline(canalLectureProduit, ligneInventaireTxt))
			{
				if (ligneInventaireTxt.at(0) != '#')
				{
					compteurLigne++;
				}

				// Ligne invalide?
			}
		}

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

char convertion_de_string_en_char(string choixUtilisateur)
{
	char entreeChoixUtilisateur;

	entreeChoixUtilisateur = choixUtilisateur.at(0);

	entreeChoixUtilisateur = toupper(entreeChoixUtilisateur);

	return entreeChoixUtilisateur;
}
