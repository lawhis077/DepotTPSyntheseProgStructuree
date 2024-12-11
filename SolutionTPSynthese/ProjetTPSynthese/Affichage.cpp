#include "Affichage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utilitaire.h"
#include "Constante.h"
#include "Strings.h"
#include "ChoixSousMenu.h"
using namespace std;

// Fonction qui gère le menu principal de l'application.
void menu_principale(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
    string choixUtilisateur;
    char entreeChoixUtilisateur = 'X';

    // Boucle qui continue tant que l'utilisateur ne choisit pas 'Q' pour quitter.
    while (entreeChoixUtilisateur != 'Q')
    {
        afficher_menu();  // Affiche le menu principal.

        getline(cin, choixUtilisateur);  // Prend le choix de l'utilisateur.

        entreeChoixUtilisateur = convertion_de_string_en_char(choixUtilisateur);  // Convertit le choix de l'utilisateur en caractère.

        bool entreeMenuValide = false;

        // Vérifie si le choix de l'utilisateur est valide en comparant avec les options valides.
        for (int i = 0; i < CHOIX_VALIDE_MENU_PRINCIPALE.size(); i++)
        {
            if (entreeChoixUtilisateur == CHOIX_VALIDE_MENU_PRINCIPALE.at(i))
            {
                entreeMenuValide = true;
            }
        }

        // Si le choix n'est pas valide, redemande à l'utilisateur de choisir un choix valide.
        while (!entreeMenuValide)
        {
            afficher_menu();  // Affiche de nouveau le menu.

            cout << "Entrez un choix valide!!" << endl;  // Message d'erreur.

            getline(cin, choixUtilisateur);  // Prend à nouveau le choix de l'utilisateur.

            entreeChoixUtilisateur = choixUtilisateur.at(0);  // Prend le premier caractère.

            entreeChoixUtilisateur = toupper(entreeChoixUtilisateur);  // Convertit le choix en majuscule.
        }

        // Si l'utilisateur choisit autre que 'Q', on redirige vers le sous-menu correspondant.
        if (entreeChoixUtilisateur != 'Q')
        {
            redirection_sous_menu(entreeChoixUtilisateur, itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
        }
    }
}

// Fonction pour afficher le menu principal.
void afficher_menu()
{
    system("pause");
    system("cls");
    cout << "-----------------------------------\n";
    cout << " Marché d'alimentation L.Lamonde\n";
    cout << "-----------------------------------\n";
    cout << endl;
    cout << "L) Lister Produits\n";
    cout << "C) Charger Circulaire\n";
    cout << "R) Recevoir Marchandise\n";
    cout << "A) Effectuer Achats\n";
    cout << "Q) Quitter\n" << endl;
    cout << "Choix : ";
}

// Fonction qui permet de lister les produits disponibles dans l'inventaire.
void lister_produits(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
    string choixListerProduits;
    char entreeChoixListerProduits;
    vector <string> categoriesProduits;

    cout << endl;
    system("cls");

    cout << "-----------------------------------\n";
    cout << " Afficher la liste de produits\n";
    cout << "-----------------------------------\n";
    cout << endl;
    cout << "*) Tous les produits\n";
    cout << "C) Circulaire\n " << endl;
    cout << "Catégorie\n" << endl;

    bool categorieSemblable = false;

    // On crée une liste de catégories de produits uniques.
    for (int i = 0; i < itemEstValide.size(); i++)
    {
        categorieSemblable = false;

        for (int ii = 0; ii < categoriesProduits.size(); ii++)
        {
            // Vérifie si la catégorie est déjà dans la liste.
            if (itemEstValide.at(i).categorieProduit == categoriesProduits.at(ii))
            {
                categorieSemblable = true;
            }
        }

        // Si la catégorie n'est pas dans la liste, on l'ajoute.
        if (!categorieSemblable)
        {
            categoriesProduits.push_back(itemEstValide.at(i).categorieProduit);
        }
    }

    // Affiche les catégories disponibles.
    for (int i = 0; i < categoriesProduits.size(); i++)
    {
        cout << i + 1 << ") " << categoriesProduits.at(i) << endl;
    }

    cout << "Choix : ";

    // Appelle la fonction pour traiter le choix de l'utilisateur concernant la liste des produits.
    choix_lister_produit(choixListerProduits, entreeChoixListerProduits, categoriesProduits, itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
}

// Fonction pour charger une circulaire depuis un fichier.
void charger_circulaire(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
    system("cls");
    cout << "--------------------------" << endl;
    cout << " Charger une circulaire" << endl;
    cout << "--------------------------" << endl << endl;

    cout << "Indiquer le nom du fichier de la circulaire :";
    string nomFichierCirculaire;
    getline(cin, nomFichierCirculaire);

    ifstream canalLectureCirculaire;

    // Ouvre le fichier de la circulaire.
    canalLectureCirculaire.open(nomFichierCirculaire);

    // Si le fichier ne peut pas être ouvert, affiche un message d'erreur.
    if (!canalLectureCirculaire.is_open())
    {
        cout << "Impossible d'ouvrir le fichier \"" << nomFichierCirculaire << "\" en lecture" << endl << endl;
    }
    else
    {
        vector<string> itemCirculaire;

        int compteurEntreeValide = 0;

        // Vérifie les données du fichier de circulaire et charge les rabais.
        verifier_fichier_circulaire(canalLectureCirculaire, itemCirculaire, itemCirculaireEstValide, nomFichierCirculaire, compteurEntreeValide);
        cout << compteurEntreeValide << " rabais chargés du fichier" << nomFichierCirculaire << endl << endl;
    }
}

// Fonction pour recevoir de la marchandise dans l'inventaire.
void recevoir_marchandise(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
    cout << endl;
    system("cls");

    cout << "-----------------------------------\n";
    cout << " Recevoir Marchandise\n";
    cout << "-----------------------------------\n";
    cout << endl;
    cout << "Entrez le code du produit" << endl << endl;
    cout << "Choix : ";

    string codeProduitAAjouterEnString;
    int codeProduitAAjouterEnInt;
    int quantiteChoisiEnInt;
    string codeProduitTemp;

    // Prend le code du produit en entrée.
    getline(cin, codeProduitAAjouterEnString);

    codeProduitTemp = codeProduitAAjouterEnString;
    bool estExtractable = extraire_entier(codeProduitAAjouterEnString, codeProduitAAjouterEnInt);
    codeProduitAAjouterEnString = codeProduitTemp;

    // Vérifie la validité du produit et de la quantité.
    verification_recevoir_marchandise(codeProduitAAjouterEnString, codeProduitAAjouterEnInt, itemInventaireEstValide, estExtractable, itemEstValide);
}

// Fonction pour effectuer un achat.
void effectuer_achat(vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
    char entreeChoixAchats = 'X';
    double sousTotal = 0.00;
    cout << endl;
    bool estUnNumero = false;
    bool produitInconnu;
    int codeProduitAAjouter;
    int quantiteExtraite;
    double prix;
    double prixProduit = 0;
    string choixAchatEnString;
    string confirmationQuitter;
    string quantiteProduitVoulue;
    vector<string> nomProduitAjoute;
    vector<structurePanier> elementsPanier;
    structurePanier panier;

    // Boucle qui continue jusqu'à ce que l'utilisateur choisisse de quitter ou de passer à la caisse.
    while (entreeChoixAchats != CHOIX_VALIDE_MENU_ACHAT.at(1))
    {
        system("cls");

        cout << "-----------------------------------\n";
        cout << "       Effectuer des achats\n";
        cout << "-----------------------------------\n";
        cout << endl;
        cout << "Sous total: " << setprecision(2) << fixed << sousTotal << ESPACE << SIGNE_DOLLAR << endl << endl;
        cout << "Indiquez le code du produit, ou" << endl;

        // Si un achat a été effectué, propose des options comme passer à la caisse ou annuler.
        if (sousTotal > 0)
        {
            cout << "- 'P' pour passer à la caisse" << endl;
            cout << "- 'R' pour retirer le dernier produit ajouté" << endl;
        }
        cout << "- 'L' pour lister les produits" << endl;
        cout << "- 'A' pour annuler la facture" << endl;
        cout << ">";

        // Prend le choix de l'utilisateur.
        getline(cin, choixAchatEnString);

        if (choixAchatEnString.size() == 1)
        {
            entreeChoixAchats = convertion_de_string_en_char(choixAchatEnString);
        }

        // Ajoutez des fonctionnalités supplémentaires en fonction des choix de l'utilisateur (annuler transaction, passer à la caisse, etc.).
    }
}

// Fonction qui redirige vers les sous-menus en fonction du choix de l'utilisateur.
void redirection_sous_menu(char entreeChoixUtilisateur, vector <structureProduitTxt>& itemEstValide, vector <structureInventaireTxt>& itemInventaireEstValide, vector<structureCirculaireTxt>& itemCirculaireEstValide)
{
    switch (entreeChoixUtilisateur)
    {
    case 'L':  // Liste les produits.
        lister_produits(itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
        break;

    case 'C':  // Charge une circulaire.
        charger_circulaire(itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
        break;

    case 'R':  // Réceptionne de la marchandise.
        recevoir_marchandise(itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
        break;

    case 'A':  // Effectue un achat.
        effectuer_achat(itemEstValide, itemInventaireEstValide, itemCirculaireEstValide);
        break;
    }
}
