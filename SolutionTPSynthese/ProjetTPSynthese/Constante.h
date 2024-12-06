#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Fichier contenant toutes les constantes du programme

const char SEPARATEUR_INVENTAIRE = ':';
const char SEPARATEUR_PRODUITS = ';';
const string FICHIER_PRODUITS = "Produits.txt";
const string FICHIER_INVENTAIRE = "Inventaire.txt";
const vector <string> UNITE_POSSIBLE{ "kg", "un", "g", "ml" };
const int NOMBRE_VALEURS_PRODUITS = 7;
const int NOMBRE_VALEURS_INVENTAIRE = 2;
const char CARACTERE_COMMENTAIRE = '#';
const vector <char> CHOIX_VALIDE_LISTER_PRODUIT{ '*', 'C', '1', '2', '3' };


