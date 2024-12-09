#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Fichier contenant toutes les constantes du programme

const int NOMBRE_VALEURS_PRODUITS = 7;
const int NOMBRE_VALEURS_INVENTAIRE = 2;
const int ESPACEMENT_AVANT_CODE_PRODUIT = 6;
const int ESPACEMENT_CODE_PRODUIT_ET_MONTANT = 67;
const int ESPACEMENT_MONTANT_ET_INVENTAIRE = 20;
const int DIVISEUR_CONVERSION_ARGENT_ET_POIDS = 100;
const int RUPTURE_DE_STOCK = 0;
const int PRECISION_KILOGRAMME = 3;
const int NOMBRE_DONNEE_AVANT_PAUSE = 10;

const char SEPARATEUR_INVENTAIRE = ':';
const char SEPARATEUR_PRODUITS = ';';
const char CARACTERE_COMMENTAIRE = '#';
const char SIGNE_DOLLAR = '$';
const char QUITTER = 'Q';
const char RETOURNER = 'R';

const string FICHIER_PRODUITS = "Produits.txt";
const string FICHIER_INVENTAIRE = "Inventaire.txt";
const string FICHIER_CIRCULAIRE = "Circulaire.txt";
const string HORS_DE_STOCK = "Aucun produit";
const vector <string> UNITE_POSSIBLE{ "kg", "un", "g", "ml" };

const vector <char> CHOIX_VALIDE_MENU_PRINCIPALE{ 'L','C', 'R' ,'A' , 'Q' };
const vector <char> CHOIX_VALIDE_LISTER_PRODUIT{ '*', 'C'};







