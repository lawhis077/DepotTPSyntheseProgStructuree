#pragma once
#include <string>

using namespace std;

// Structures afin de stocker l'information des lignes des fichiers dans un vecteur du m�me type pour �tre r�utiliser

struct structureProduitTxt
{
	int codeProduit;
	string categorieProduit;
	string nomProduit;
	int quantiteProduit;
	string uniteProduit;
	string estTaxable;
	int prixProduit;
};

struct structureInventaireTxt
{
	int codeProduitInventaire;
	int nombreProduitInventaire;
};

struct structureCirculaireTxt
{
	int codeProduitCirculaire;
	int pourcentageRabaisCirculaire;
};

struct structurePanier
{
	string nomProduitPanier;
	double prixProduitPanier;
	double quantiteProduitPanier;
	double totalPrixPanier;
};