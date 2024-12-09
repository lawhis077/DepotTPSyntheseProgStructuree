#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "StructureFichiers.h"
#include "ChoixSousMenu.h"

using namespace std;

void afficher_menu();

void redirection_sous_menu(char entreeChoixUtilisateur, vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide);

void lister_produits(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide);

void charger_circulaire();

void recevoir_marchandise();

void effectuer_achat();
