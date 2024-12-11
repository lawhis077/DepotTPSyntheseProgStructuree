#include "Operations.h"

using namespace std;

void afficher_produits(vector<string> categorieProduit, vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide, string choixListerProduit, char& entreeChoixListerProduit, int choixListerProduitEnInt, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
	ifstream canalLectureFichierCirculaire;
	double nombreInventaireProduit = 0;
	int compteurEntrees = 0;

	while (entreeChoixListerProduit != RETOURNER)
	{
		cout << "-----------------------------------\n";
		cout << " Afficher la liste de produits\n";
		cout << "-----------------------------------\n" << endl << endl;

		if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(1) && itemCirculaireEstValide.size() == 0)
		{
			cout << "\n\nAucun Produit\n\n";
			entreeChoixListerProduit = RETOURNER;
		}
		else
		{
			
			for (int i = 0; i < itemEstValide.size(); i++)
			{
				if (entreeChoixListerProduit != RETOURNER)
				{
					bool estDansCirculaire = false;
					int pourcentageRabaisProduit = 0;

					associer_produit_avec_inventaire_et_circulaire(itemEstValide, itemInventaireEstValide, nombreInventaireProduit, estDansCirculaire, pourcentageRabaisProduit, i, itemCirculaireEstValide);

					string codeProduitEnChaine = entier_en_chaine(itemEstValide.at(i).codeProduit);
					int espacementCodeProduit = ESPACEMENT_AVANT_CODE_PRODUIT - codeProduitEnChaine.size();
					int nombreEspaceProduitEtMontant = ESPACEMENT_CODE_PRODUIT_ET_MONTANT - itemEstValide.at(i).nomProduit.size() - codeProduitEnChaine.size();
					double montantALAffichage = itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS;
					
					if (estDansCirculaire && entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(1))
					{
						compteurEntrees++;
						affichage_ligne_avec_circulaire(codeProduitEnChaine, espacementCodeProduit, nombreEspaceProduitEtMontant, nombreInventaireProduit, itemEstValide, i, choixListerProduit, itemCirculaireEstValide);
					}

					if ((entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(0)) || (choixListerProduitEnInt > 0 && itemEstValide.at(i).categorieProduit == categorieProduit.at(choixListerProduitEnInt - 1)))
					{
						compteurEntrees++;
						affichage_ligne_lister_produit(codeProduitEnChaine, espacementCodeProduit, nombreEspaceProduitEtMontant, nombreInventaireProduit, itemEstValide, i, choixListerProduit, itemCirculaireEstValide);
					}

					if (compteurEntrees == 10) 
					{
						cout << "Entrez 'R' pour retourner, ou autre pour continuer la liste: ";
						getline(cin, choixListerProduit);
						system("cls");
						compteurEntrees = 0;

						if (!choixListerProduit.empty())
						{ 
							entreeChoixListerProduit = choixListerProduit.at(0);
							entreeChoixListerProduit = toupper(entreeChoixListerProduit);

							if (isdigit(entreeChoixListerProduit)) 
							{
								entreeChoixListerProduit = 'X';
							}

							if (choixListerProduit.at(0) != RETOURNER) 
							{
								cout << "-----------------------------------\n";
								cout << " Afficher la liste de produits\n";
								cout << "-----------------------------------\n"
									<< endl
									<< endl;
							}
						}
						else 
						{
							cout << "-----------------------------------\n";
							cout << " Afficher la liste de produits\n";
							cout << "-----------------------------------\n"
								<< endl
								<< endl;
							entreeChoixListerProduit = 'X';
						}
					}
				}
				
			}
			entreeChoixListerProduit = RETOURNER;
		}
	}
	
}



void associer_produit_avec_inventaire_et_circulaire(vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide, double& nombreInventaireProduit, bool& estDansCirculaire, int& pourcentageRabaisProduit, int i, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
	bool estTrouver = false;
	for (int ii = 0; ii < itemInventaireEstValide.size(); ii++)
	{
		if (itemEstValide.at(i).codeProduit == itemInventaireEstValide.at(ii).codeProduitInventaire)
		{
			nombreInventaireProduit = itemInventaireEstValide.at(ii).nombreProduitInventaire;
			estTrouver = true;
		}
	}

	if (!estTrouver)
	{
		nombreInventaireProduit = 0;
	}

	for (int j = 0; j < itemCirculaireEstValide.size(); j++)
	{
		if (itemEstValide.at(i).codeProduit == itemCirculaireEstValide.at(j).codeProduitCirculaire)
		{
			estDansCirculaire = true;
			pourcentageRabaisProduit = itemCirculaireEstValide.at(j).pourcentageRabaisCirculaire;
		}
	}
}

void affichage_ligne_lister_produit(string codeProduitEnChaine, int espacementCodeProduit, int nombreEspaceProduitEtMontant, double nombreInventaireProduit, vector<structureProduitTxt> itemEstValide, int i, string& choixListerProduit,vector <structureCirculaireTxt>& itemCirculaireEstValide)
{	

	if (nombreInventaireProduit == RUPTURE_DE_STOCK)
	{
		double prixProduit = itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS;
		cout << setfill(ESPACE) << fixed << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
			<< setfill(ESPACE) << setw(nombreEspaceProduitEtMontant) << setprecision(2) << fixed << prixProduit << SIGNE_DOLLAR << setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) 
			<< setfill(ESPACE) << fixed << "      [ Rupture de Stock ]" << endl << endl;
	}
	else
	{
		if (itemEstValide.at(i).uniteProduit == UNITE_POSSIBLE.at(0))
		{
			double prixProduit = itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS;
			cout << setfill(ESPACE) << fixed << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
				<< setfill(ESPACE) << setw(nombreEspaceProduitEtMontant) <<setprecision(2) << fixed << prixProduit << SIGNE_DOLLAR << setfill(ESPACE)
				<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << setfill(ESPACE) << "[ Inventaire: " << setprecision(PRECISION_KILOGRAMME) << fixed << nombreInventaireProduit << "  " << UNITE_POSSIBLE.at(0) << "  ]" << endl << endl;
		}
		else
		{
			int nombreProduitInventaires = nombreInventaireProduit;
			double prixProduit = itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS;
			cout << setfill(ESPACE) << fixed << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
				<< setfill(ESPACE) << setw(nombreEspaceProduitEtMontant) << setprecision(2) << fixed << prixProduit << SIGNE_DOLLAR << setfill(ESPACE)
				<< setw(ESPACEMENT_MONTANT_ET_INVENTAIRE) << setfill(ESPACE) << "[ Inventaire: " << nombreProduitInventaires << "  ]" << endl << endl;
		}
	}
}

void affichage_ligne_avec_circulaire(string codeProduitEnChaine, int espacementCodeProduit, int nombreEspaceProduitEtMontant, double nombreInventaireProduit, vector<structureProduitTxt> itemEstValide, int i, string& choixListerProduit, vector<structureCirculaireTxt>& itemCirculaireEstValide)
{
	double prixProduit = itemEstValide.at(i).prixProduit / DIVISEUR_CONVERSION_ARGENT_ET_POIDS;
	double prixProduitAvecRabais = prixProduit - (prixProduit * (itemCirculaireEstValide.at(i).pourcentageRabaisCirculaire / DIVISEUR_CONVERSION_ARGENT_ET_POIDS));
	int nombreProduitInventaires = nombreInventaireProduit;
	int espacementEntreMontantEtRabais = 3;

	if (itemCirculaireEstValide.at(i).pourcentageRabaisCirculaire >= 10)
	{
		espacementEntreMontantEtRabais = 2;
	}

	if (nombreInventaireProduit == RUPTURE_DE_STOCK)
	{
		
		cout << setfill(ESPACE) << fixed << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
			<< setfill(ESPACE) << setw(nombreEspaceProduitEtMontant) << setprecision(2) << fixed << prixProduit << SIGNE_DOLLAR
			<< setw(ESPACEMENT_AVANT_ET_APRES_RABAIS_CIRCULAIRE) << setfill(ESPACE) << "( " << prixProduitAvecRabais << ESPACE << SIGNE_DOLLAR << "  -"
			<< itemCirculaireEstValide.at(i).pourcentageRabaisCirculaire << " %)" << setw(ESPACEMENT_AVANT_ET_APRES_RABAIS_CIRCULAIRE) << setfill(ESPACE)
			<< "[Rupture de Stock]" << endl << endl;
	}
	else
	{
		if (itemEstValide.at(i).uniteProduit == UNITE_POSSIBLE.at(0))
		{
			
			cout << setfill(ESPACE) << fixed << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
				<< setfill(ESPACE) << setw(nombreEspaceProduitEtMontant) << setprecision(2) << fixed << prixProduit << SIGNE_DOLLAR
				<< setw(ESPACEMENT_AVANT_ET_APRES_RABAIS_CIRCULAIRE) << setfill(ESPACE) << "( " << prixProduitAvecRabais << ESPACE << SIGNE_DOLLAR << "  -"
				<< itemCirculaireEstValide.at(i).pourcentageRabaisCirculaire << " %)" << setw(ESPACEMENT_AVANT_ET_APRES_RABAIS_CIRCULAIRE) << setfill(ESPACE)
				<< "[ Inventaire: " << setprecision(PRECISION_KILOGRAMME) << fixed << nombreInventaireProduit / DIVISEUR_CONVERSION_GRAMMES_ET_KILOGRAMMES << "  " << UNITE_POSSIBLE.at(0) << "  ]" << endl << endl;
		}
		else
		{
			
			
			cout << setfill(ESPACE) << fixed << setw(espacementCodeProduit) << codeProduitEnChaine << ":" << itemEstValide.at(i).nomProduit
				<< setfill(ESPACE) << setw(nombreEspaceProduitEtMontant) << setprecision(2) << fixed << prixProduit << SIGNE_DOLLAR
				<< setw(ESPACEMENT_AVANT_ET_APRES_RABAIS_CIRCULAIRE) << setfill(ESPACE) << "( " << prixProduitAvecRabais << ESPACE << SIGNE_DOLLAR << "  -" 
				<< itemCirculaireEstValide.at(i).pourcentageRabaisCirculaire << " %)" << setw(ESPACEMENT_AVANT_ET_APRES_RABAIS_CIRCULAIRE) << setfill(ESPACE)
				<< "[ Inventaire: " << nombreProduitInventaires << "  ]" << endl << endl;
		}
	}

}
