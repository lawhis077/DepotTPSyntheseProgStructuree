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

void operation_lister_produit(string choixListerProduit, char& entreeChoixListerProduit,int choixListerProduitEnInt,  
	vector<string> categorieProduit, vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide);