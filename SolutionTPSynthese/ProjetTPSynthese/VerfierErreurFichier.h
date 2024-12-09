#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Affichage.h"
#include "StructureFichiers.h"
#include "Constante.h"

using namespace std;

void verifier_fichier_produit(ifstream& canalLectureFichier, vector <string>& itemProduit, vector <structureProduitTxt>& itemProduitEstValide, string nomFichier);
void verifier_fichier_inventaire(ifstream& canalLectureFichier, vector<string>& itemInventaire, vector<structureInventaireTxt>& itemInventaireEstValide, string nomFichier);
// verifier_fichier_circulaire();