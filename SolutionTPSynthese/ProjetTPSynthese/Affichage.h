#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "StructureFichiers.h"
#include "ChoixSousMenu.h"
#include "VerfierErreurFichier.h"

using namespace std;
void menu_principale(vector <structureProduitTxt>& itemEstValide,vector <structureInventaireTxt>& itemInventaireEstValide,vector <structureCirculaireTxt>& itemCirculaireEstValide);

void afficher_menu();

void redirection_sous_menu(char entreeChoixUtilisateur, vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector<structureCirculaireTxt>& itemCirculaireEstValide);

void lister_produits(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide);

void charger_circulaire(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide);

void recevoir_marchandise(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide);

void effectuer_achat(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide);
