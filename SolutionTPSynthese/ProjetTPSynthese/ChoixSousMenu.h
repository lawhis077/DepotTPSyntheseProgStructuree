#pragma once
#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Constante.h"
#include "Strings.h"
#include "Operations.h"

void choix_lister_produit(string& choixListerProduit, char& entreeChoixListerProduit, vector <string> categorieProduit, vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide);
void ecriture_recevoir_marchandise(string codeProduitAAjouterEnString, int quantiteChoisiEnInt, int codeProduitAAjouterEnInt, int i, vector <structureInventaireTxt>& itemInventaireEstValide);
void verification_recevoir_marchandise(string codeProduitAAjouterEnString, int codeProduitAAjouterEnInt, vector<structureInventaireTxt>& itemInventaireEstValide, bool estExtractable, vector<structureProduitTxt>& itemEstValide);