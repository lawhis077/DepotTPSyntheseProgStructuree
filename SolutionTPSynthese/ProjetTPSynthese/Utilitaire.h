#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Ouvre le canal vers le fichier portant le nom donné et initialise la variable filestream donnée
// Affiche un message d'erreur si le canal est pas ouvert
// Retourne true si le canal est ouvert, false sinon
bool ouvrir_fichier_en_lecture(ifstream& canalLectureFichier, string nomFichier);

// Si ajouterALaFin est vraie, on écrase pas le fichier existant 
bool ouvrir_fichier_en_ecriture(ofstream& canalEcritureFichier, string nomFichier, bool ajouterALaFin);

// Boucle faisant la convertion du string compatible avec le getline à un char qui spécifie le choix entrée
// par l'utilisateur
char convertion_de_string_en_char(string choixUtilisateur);