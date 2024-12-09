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
	string estTaxable;
	int prixProduit;
};

struct structureInventaireTxt
{
	int codeProduitInventaire;
	int nombreProduitInventaire;
};