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

void choix_lister_produit(string& choixListerProduit, char& entreeChoixListerProduit, vector <string> categorieProduit, vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide);