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
// Fonctions permettant la vériffication d'erreur des fichiers, ainsi que mettre les données valides dans un vecteur
void verifier_fichier_produit(ifstream& canalLectureFichier, vector <string>& itemProduit, vector <structureProduitTxt>& itemProduitEstValide, string nomFichier);
void verifier_fichier_inventaire(ifstream& canalLectureFichier, vector<string>& itemInventaire, vector<structureInventaireTxt>& itemInventaireEstValide, string nomFichier);
void verifier_fichier_circulaire(ifstream& canalLectureFichier, vector<string>& itemCirculaire, vector<structureCirculaireTxt>& itemCirculaireEstValide, string nomFichier, int& compteurEntreeValide);