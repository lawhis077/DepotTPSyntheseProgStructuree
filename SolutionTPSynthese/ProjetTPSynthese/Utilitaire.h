#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Ouvre le canal vers le fichier portant le nom donn� et initialise la variable filestream donn�e
// Affiche un message d'erreur si le canal est pas ouvert
// Retourne true si le canal est ouvert, false sinon
bool ouvrir_fichier_en_lecture(ifstream& canalLectureFichier, string nomFichier);

// Si ajouterALaFin est vraie, on �crase pas le fichier existant 
bool ouvrir_fichier_en_ecriture(ofstream& canalEcritureFichier, string nomFichier, bool ajouterALaFin);

// Boucle faisant la convertion du string compatible avec le getline � un char qui sp�cifie le choix entr�e
// par l'utilisateur
char convertion_de_string_en_char(string choixUtilisateur);