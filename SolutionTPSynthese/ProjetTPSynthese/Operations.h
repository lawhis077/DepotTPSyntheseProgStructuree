#pragma once
#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Constante.h"
#include "Strings.h"
#include <iomanip>

// Fonction
void afficher_produits(vector<string> categorieProduit, vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide, string choixListerProduit, char& entreeChoixListerProduit, int choixListerProduitEnInt, vector <structureCirculaireTxt>& itemCirculaireEstValide);
void associer_produit_avec_inventaire_et_circulaire(vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide, double& nombreInventaireProduit,bool& estDansCirculaire,int& pourcentageRabaisProduit, int i, vector <structureCirculaireTxt>& itemCirculaireEstValide);

void affichage_ligne_lister_produit(string codeProduitEnChaine, int espacementCodeProduit, int nombreEspaceProduitEtMontant, double nombreInventaireProduit, vector<structureProduitTxt> itemEstValide, int i, string& choixListerProduit, vector <structureCirculaireTxt>& itemCirculaireEstValide);

void affichage_ligne_avec_circulaire(string codeProduitEnChaine, int espacementCodeProduit, int nombreEspaceProduitEtMontant, double nombreInventaireProduit, vector<structureProduitTxt> itemEstValide, int i, string& choixListerProduit, vector <structureCirculaireTxt>& itemCirculaireEstValide);