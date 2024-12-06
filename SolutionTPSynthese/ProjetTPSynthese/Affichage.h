#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "StructureFichiers.h"

using namespace std;

void afficher_menu();

void lister_produits(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide);

void charger_circulaire();

void recevoir_marchandise();

void effectuer_achat();
