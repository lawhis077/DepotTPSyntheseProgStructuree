#pragma once
#include <string>

using namespace std;

struct structureProduitTxt
{
	int codeProduit;
	string categorieProduit;
	string nomProduit;
	int quantiteProduit;
	string uniteProduit;
	bool estTaxable;
	double prixProduit;
};

struct structureInventaireTxt
{
	int codeProduitInventaire;
	int nombreProduitInventaire;
};