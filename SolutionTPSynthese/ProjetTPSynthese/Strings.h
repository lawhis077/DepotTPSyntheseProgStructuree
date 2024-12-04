#pragma once
// Manipulation de chaines de caract�res
#include <string>
#include <vector>


// Supprime toutes les espaces au d�but et � la fin de la chaine donn�e
// Ne modifie pas les espaces entre d'autres caract�res
void rogner_espaces(std::string& chaine);


// Retourne le nombre donn� converti en chaine de caract�res
std::string entier_en_chaine(int entier);
std::string reel_en_chaine(double reel);


// Convertit une chaine de caract�res en nombre entier
//
// chaine est une r�f�rence sur la chaine � convertir.
// entier est une r�f�rence sur la variable dans laquelle mettre la valeur convertie.
//
// Si la chaine d�bute par un nombre entier (il peut y avoir des espaces au d�but de la chaine),
// ce nombre est extrait de la chaine et assign� au param�tre 'entier'. La chaine est modifi�e
// pour enlever le nombre, et les espaces avant ce nombre si pr�sentes. La fonction retourne alors vrai.
//
// Si la chaine ne d�bute pas par un nombre entier, 'chaine' et 'entier' sont inchang�s.
// La fonction retourne alors faux.
bool extraire_entier(std::string& chaine, int& entier);


// M�me comportement que convertirEntier ci-dessus, mais pour un nombre r�el.
bool extraire_reel(std::string& chaine, double& reel);


// S�pare la chaine donn�e en une suite de sous-chaines selon le s�parateur donn�
// Retourne un vecteur contenant toutes les sous-chaines s�par�es
std::vector<std::string> separer(std::string chaine, char sep);
