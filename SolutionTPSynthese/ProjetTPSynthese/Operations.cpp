#include "Operations.h"

void operation_lister_produit(string choixListerProduit, char& entreeChoixListerProduit, int choixListerProduitEnInt, vector<string> categorieProduit,
	vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide)
{
	int nombreInventaireProduit = 0;

	if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(0))
	{
		while (entreeChoixListerProduit != RETOURNER)
		{
			// lister_tous_les_produits();
			for (int i = 0; i < itemEstValide.size(); i++)
			{
				for (int ii = 0; ii < itemInventaireEstValide.size(); ii++)
				{
					if (itemEstValide.at(i).codeProduit == itemInventaireEstValide.at(ii).codeProduitInventaire)
					{
						nombreInventaireProduit = itemInventaireEstValide.at(ii).nombreProduitInventaire;
					}
				}
				
				if (nombreInventaireProduit == RUPTURE_DE_STOCK)
				{
					string codeProduitEnChaine = entier_en_chaine(itemEstValide.at(i).codeProduit);
					int espacementCodeProduit = ESPACEMENT_AVANT_CODE_PRODUIT - codeProduitEnChaine.size();
					int nombreEspaceProduitEtMontant = 67 - itemEstValide.at(i).nomProduit.size() - codeProduitEnChaine.size();

					cout << setfill(' ') << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
						<< setfill(' ') << setw(nombreEspaceProduitEtMontant) << itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS << SIGNE_DOLLAR << setfill(' ')
						<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << "[ Rupture de stock ]";
				}
				else
				{
					string codeProduitEnChaine = entier_en_chaine(itemEstValide.at(i).codeProduit);
					int espacementCodeProduit = ESPACEMENT_AVANT_CODE_PRODUIT - codeProduitEnChaine.size();
					int nombreEspaceProduitEtMontant = 67 - itemEstValide.at(i).nomProduit.size() - codeProduitEnChaine.size();

					if (itemEstValide.at(i).uniteProduit == UNITE_POSSIBLE.at(0))
					{
						cout << setfill(' ') << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
							<< setfill(' ') << setw(nombreEspaceProduitEtMontant) << itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS << SIGNE_DOLLAR << setfill(' ')
							<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << "[ Inventaire: " << setprecision(PRECISION_KILOGRAMME) << nombreInventaireProduit << "  " << UNITE_POSSIBLE.at(0) << "  ]";
					}
					else
					{
						cout << setfill(' ') << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
							<< setfill(' ') << setw(nombreEspaceProduitEtMontant) << itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS << SIGNE_DOLLAR << setfill(' ')
							<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << "[ Inventaire: " << nombreInventaireProduit << "    ]";
					}
				}

				// Pause ou i < 10?
				if (i + 1 % 10 == 0)
				{
					system("pause");
					cout << "Entrez 'R' pour retourner, ou autre pour continuer la liste: ";
					getline(cin, choixListerProduit);
				}
			}
		}
	}
	else if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(1))
	{
		// lister_produits_circulaire();
	}
	else
	{
		while (entreeChoixListerProduit != RETOURNER)
		{
			string bonneCategorie = categorieProduit.at(choixListerProduitEnInt - 1);

			// afficher_produits();
			for (int i = 0; i < itemEstValide.size(); i++)
			{
				if (itemEstValide.at(i).categorieProduit == bonneCategorie)
				{
					for (int ii = 0; ii < itemInventaireEstValide.size(); ii++)
					{
						if (itemEstValide.at(i).codeProduit == itemInventaireEstValide.at(ii).codeProduitInventaire)
						{
							nombreInventaireProduit = itemInventaireEstValide.at(ii).nombreProduitInventaire;
						}
					}

				
					if (nombreInventaireProduit == RUPTURE_DE_STOCK)
					{
						string codeProduitEnChaine = entier_en_chaine(itemEstValide.at(i).codeProduit);
						int espacementCodeProduit = ESPACEMENT_AVANT_CODE_PRODUIT - codeProduitEnChaine.size();
						int nombreEspaceProduitEtMontant = 67 - itemEstValide.at(i).nomProduit.size() - codeProduitEnChaine.size();

						cout << setfill(' ') << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
							<< setfill(' ') << setw(nombreEspaceProduitEtMontant) << itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS << SIGNE_DOLLAR << setfill(' ')
							<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << "[ Rupture de stock ]";
					}
					else
					{
						string codeProduitEnChaine = entier_en_chaine(itemEstValide.at(i).codeProduit);
						int espacementCodeProduit = ESPACEMENT_AVANT_CODE_PRODUIT - codeProduitEnChaine.size();
						int nombreEspaceProduitEtMontant = 67 - itemEstValide.at(i).nomProduit.size() - codeProduitEnChaine.size();

						if (itemEstValide.at(i).uniteProduit == UNITE_POSSIBLE.at(0))
						{
							cout << setfill(' ') << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
								<< setfill(' ') << setw(nombreEspaceProduitEtMontant) << itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS << SIGNE_DOLLAR << setfill(' ')
								<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << "[ Inventaire: " << setprecision(PRECISION_KILOGRAMME) << nombreInventaireProduit << "  " << UNITE_POSSIBLE.at(0) << "  ]";
						}
						else
						{
							cout << setfill(' ') << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
								<< setfill(' ') << setw(nombreEspaceProduitEtMontant) << itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS << SIGNE_DOLLAR << setfill(' ')
								<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << "[ Inventaire: " << nombreInventaireProduit << "    ]";
						}
					}

					// Pause ou i < 10?
					if (i + 1 % 10 == 0)
					{
						system("pause");
						cout << "Entrez 'R' pour retourner, ou autre pour continuer la liste: ";
						getline(cin, choixListerProduit);
					}
				}
				
			}
		}

		
	}
	
}
