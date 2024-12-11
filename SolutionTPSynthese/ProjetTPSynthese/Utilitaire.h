#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "StructureFichiers.h"
using namespace std;

// Ouvre le canal vers le fichier portant le nom donné et initialise la variable filestream donnée
// Affiche un message d'erreur si le canal est pas ouvert
// Retourne true si le canal est ouvert, false sinon
bool ouvrir_fichier_en_lecture(ifstream& canalLectureFichier, string nomFichier, vector <structureProduitTxt>& itemProduitEstValide, vector <structureInventaireTxt>& itemInventaireEstValide);
// Si ajouterALaFin est vraie, on écrase pas le fichier existant 
bool ouvrir_fichier_en_ecriture(ofstream& canalEcritureFichier, string nomFichier, bool ajouterALaFin);

// Boucle faisant la convertion du string compatible avec le getline à un char qui spécifie le choix entrée
// par l'utilisateur
char convertion_de_string_en_char(string& choixUtilisateur);

// Fonction qui rogne les espaces d'un vecteur
void rogner_espaces_vecteur(vector<string>& vecteurAvecEspace);

// Fonctions permettant l'ajustement des vecteurs dans l'item, permettant de valider proprement l'information
void ajuster_produit(vector <string> itemProduit, structureProduitTxt& produit);
void ajuster_inventaire(vector <string> itemInventaire, structureInventaireTxt& inventaire);
void ajuster_circulaire(vector <string> itemCirculaire, structureCirculaireTxt& circulaire);

// Fonction permettant la conversion d'une donnée string afin qu'elle puisse être traiter comme char
void entree_utilisateur(string& stringChoix, char& charChoix);