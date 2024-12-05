#include "Utilitaire.h"
#include "Strings.h"
#include "StructureFichiers.h"
#include "Constante.h"

bool ouvrir_fichier_en_lecture(ifstream& canalLectureFichier, string nomFichier)
{
	vector <structureProduitTxt> itemEstValide;
	vector <string> item;

	vector <structureInventaireTxt> itemInventaireEstValide;
	vector <string> itemInventaire;

	canalLectureFichier.open(nomFichier);

	ifstream canalLectureProduit;

	string ligneProduitTxt;
	string ligneInventaireTxt;

	int compteurLigne = 0;

	if (canalLectureFichier.is_open())
	{
		if (nomFichier == FICHIER_PRODUITS)
		{
			while (getline(canalLectureProduit, ligneProduitTxt))
			{
				compteurLigne++;
				rogner_espaces(ligneProduitTxt);

				if (ligneProduitTxt.at(0) != CARACTERE_COMMENTAIRE)
				{
				 
					item = separer(ligneProduitTxt, SEPARATEUR_PRODUITS);
					structureProduitTxt produit;

					if (item.size() <= 7)
					{
						extraire_entier(item.at(0), produit.codeProduit);

						if (produit.codeProduit > 0)
						{
							rogner_espaces(item.at(1));
							rogner_espaces(item.at(2));
							produit.categorieProduit = item.at(1);
							produit.nomProduit = item.at(2);
							extraire_entier(item.at(3), produit.quantiteProduit);
							rogner_espaces(item.at(4));
							produit.uniteProduit = item.at(4);

							if (produit.quantiteProduit > 0 || (produit.quantiteProduit == 0 &&  produit.uniteProduit  == UNITE_POSSIBLE.at(0)))
							{
								bool uniteEstValide = false;

								for (int i = 0; i < UNITE_POSSIBLE.size(); i++)
								{
									if (produit.uniteProduit == UNITE_POSSIBLE.at(i))
									{
										uniteEstValide == true;
									}
								}

								if (uniteEstValide == true)
								{

									rogner_espaces(item.at(5));
									
									if (item.at(5) == "oui" || item.at(5) == "non")
									{
										if (item.at(5) == "oui")
										{
											produit.estTaxable == true;

										}
										else if (item.at(5) == "non")
										{
											produit.estTaxable == false;
										}
										else
										{
											cout << "Erreur! à la ligne " << compteurLigne;
										}

										extraire_entier(item.at(6), produit.prixProduit);

										if (produit.prixProduit > 0)
										{
											itemEstValide.push_back(produit);
										}
										else
										{
											cout << "Erreur! à la ligne " << compteurLigne;
										}

									}
									else
									{
										cout << "Erreur! à la ligne " << compteurLigne;
									}

								}
								else
								{
									cout << "Erreur! à la ligne " << compteurLigne;
								}

							}
							else
							{
								cout << "Erreur! à la ligne " << compteurLigne;
							}

						}
						else
						{
							cout << "Erreur! à la ligne " << compteurLigne;
						}



					}
					else
					{
						cout << "Erreur! à la ligne " << compteurLigne;
					}





				
				}
				else
				{
					cout << "Erreur! à la ligne " << compteurLigne;
				}


			}
		}
		
		if (nomFichier == FICHIER_INVENTAIRE)
		{
			while (getline(canalLectureProduit, ligneInventaireTxt))
			{
				structureInventaireTxt inventaire;
				compteurLigne++;

				itemInventaire = separer(ligneInventaireTxt, SEPARATEUR_INVENTAIRE);

				if (itemInventaire.size() == 1)
				{
					bool estExtrait;

					estExtrait = extraire_entier(itemInventaire.at(0), inventaire.codeProduitInventaire);

					if (inventaire.codeProduitInventaire >= 0 || estExtrait)
					{
						extraire_entier(itemInventaire.at(1), inventaire.nombreProduitInventaire);

						if (inventaire.nombreProduitInventaire >= 0)
						{
							itemInventaireEstValide.push_back(inventaire);
						}
					}
				}
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
	bool estValide;

	while (!estValide)
	{
	
		if (choixUtilisateur.size() == 0)
		{
			if (!choixUtilisateur.empty())
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
