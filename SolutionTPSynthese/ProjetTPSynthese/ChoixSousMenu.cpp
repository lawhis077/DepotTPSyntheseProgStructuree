#include "ChoixSousMenu.h"

// Fonction qui g�re la s�lection du produit � lister selon la cat�gorie choisie.
void choix_lister_produit(string& choixListerProduit, char& entreeChoixListerProduit, vector<string> categorieProduit, vector<structureProduitTxt>& itemEstValide, vector<structureInventaireTxt>& itemInventaireEstValide, vector <structureCirculaireTxt>& itemCirculaireEstValide)
{
    int choixUtilisateurEnInt = 0;
    int repetitionErreur = 0;
    bool choixValide = false;

    // Boucle pour s'assurer que l'entr�e utilisateur est valide.
    while (!choixValide && entreeChoixListerProduit != QUITTER)
    {
        repetitionErreur++;
        if (repetitionErreur > 1)
        {
            cout << "Erreur!! Mauvaise entr�e de donn�e\n" << endl; // Affiche une erreur si l'utilisateur entre une valeur incorrecte.
        }

        getline(cin, choixListerProduit);  // Demande � l'utilisateur d'entrer son choix.
        cout << endl << endl;

        entree_utilisateur(choixListerProduit, entreeChoixListerProduit);  // Convertit l'entr�e en char.

        // Si l'entr�e est un nombre, on l'extrait en entier.
        if (isdigit(entreeChoixListerProduit))
        {
            extraire_entier(choixListerProduit, choixUtilisateurEnInt);
        }

        // V�rifie si l'entr�e est un choix valide parmi les options.
        for (int i = 0; i < CHOIX_VALIDE_LISTER_PRODUIT.size(); i++)
        {
            if (entreeChoixListerProduit == CHOIX_VALIDE_LISTER_PRODUIT.at(i) || choixUtilisateurEnInt <= categorieProduit.size() - 1)
            {
                choixValide = true;  // L'entr�e est valide.
            }
        }
    }

    system("cls");  // Efface l'�cran.

    // Si l'utilisateur n'a pas choisi de quitter, on affiche les produits.
    if (entreeChoixListerProduit != QUITTER)
    {
        afficher_produits(categorieProduit, itemEstValide, itemInventaireEstValide, choixListerProduit, entreeChoixListerProduit, choixUtilisateurEnInt, itemCirculaireEstValide);
    }
}

// Fonction qui g�re l'�criture des modifications dans le fichier d'inventaire lors de la r�ception de marchandises.
void ecriture_recevoir_marchandise(string codeProduitAAjouterEnString, int quantiteChoisiEnInt, int codeProduitAAjouterEnInt, int i, vector <structureInventaireTxt>& itemInventaireEstValide)
{
    ifstream canalFichierLectureInventaire;  // Ouverture du fichier d'inventaire en lecture.
    canalFichierLectureInventaire.open(FICHIER_INVENTAIRE);

    vector<string> vectorLignesFichierInventaire;  // Contient toutes les lignes du fichier d'inventaire.
    string ligneFichierInventaire;
    bool changementFait = false;  // Indique si un changement a �t� effectu�.

    // Lecture du fichier ligne par ligne.
    while (getline(canalFichierLectureInventaire, ligneFichierInventaire))
    {
        vectorLignesFichierInventaire.push_back(ligneFichierInventaire);
    }

    canalFichierLectureInventaire.close();  // Fermeture du fichier apr�s lecture.

    ofstream canalFichierEcritureInventaire;  // Ouverture du fichier en mode �criture.
    canalFichierEcritureInventaire.open(FICHIER_INVENTAIRE);

    // Parcours de chaque ligne pour v�rifier si c'est le produit qu'on veut ajouter.
    for (int j = 0; j < vectorLignesFichierInventaire.size(); j++)
    {
        vector <string> itemInventaire = separer(vectorLignesFichierInventaire.at(j), SEPARATEUR_INVENTAIRE);  // S�pare la ligne par le s�parateur.

        // Si on trouve le produit correspondant, on met � jour sa quantit� dans le fichier.
        if (itemInventaire.at(0) == codeProduitAAjouterEnString)
        {
            canalFichierEcritureInventaire << codeProduitAAjouterEnInt << SEPARATEUR_INVENTAIRE << itemInventaireEstValide.at(i).nombreProduitInventaire + quantiteChoisiEnInt << endl;
            itemInventaireEstValide.at(i).nombreProduitInventaire += quantiteChoisiEnInt;  // Met � jour l'inventaire local.
            changementFait = true;
        }
        else
        {
            canalFichierEcritureInventaire << vectorLignesFichierInventaire.at(j) << endl;  // Si ce n'est pas le bon produit, on �crit la ligne sans modification.
        }
    }

    canalFichierEcritureInventaire.close();  // Fermeture du fichier apr�s �criture.

    // Si un changement a �t� effectu�, affiche un message de succ�s.
    if (changementFait)
    {
        cout << "Le changement � �t� fait avec succ�s !! " << endl << endl;
    }
}

// Fonction qui v�rifie la validit� de la r�ception de marchandise (si le code produit est valide, si la quantit� est correcte, etc.).
void verification_recevoir_marchandise(string codeProduitAAjouterEnString, int codeProduitAAjouterEnInt, vector<structureInventaireTxt>& itemInventaireEstValide, bool estExtractable, vector<structureProduitTxt>& itemEstValide)
{
    string quantiteChoisiEnString;
    int quantiteChoisiEnInt;
    bool pasDErreur = false;

    // Si le produit est valide (le code est extractible), on continue.
    if (estExtractable)
    {
        bool codeTrouve = false;

        // Parcours de l'inventaire pour trouver le produit.
        for (int i = 0; i < itemInventaireEstValide.size(); i++)
        {
            if (itemInventaireEstValide.at(i).codeProduitInventaire == codeProduitAAjouterEnInt)
            {
                // Si le produit est trouv�, on le cherche �galement dans la liste des produits valides.
                for (int ii = 0; ii < itemEstValide.size(); ii++)
                {
                    if (itemEstValide.at(ii).codeProduit == itemInventaireEstValide.at(i).codeProduitInventaire)
                    {
                        int quantiteCodeChoisi = itemEstValide.at(ii).quantiteProduit;

                        cout << itemEstValide.at(ii).nomProduit << endl;  // Affiche le nom du produit.
                        // Si l'unit� n'est pas celle attendue, demande la quantit�.
                        if (itemEstValide.at(ii).uniteProduit != UNITE_POSSIBLE.at(0))
                        {
                            cout << itemEstValide.at(ii).quantiteProduit << ESPACE << itemEstValide.at(ii).uniteProduit << endl << endl;
                            cout << "Indiquez la quantit�: ";
                            getline(cin, quantiteChoisiEnString);

                            // V�rifie si la quantit� entr�e est valide.
                            bool quantiteEstExtractable = extraire_entier(quantiteChoisiEnString, quantiteChoisiEnInt);
                            if (quantiteEstExtractable)
                            {
                                ecriture_recevoir_marchandise(codeProduitAAjouterEnString, quantiteChoisiEnInt, codeProduitAAjouterEnInt, i, itemInventaireEstValide);  // Enregistre la modification.
                                pasDErreur = true;
                            }
                            else
                            {
                                cout << "Quantit� de produit invalide!" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "Code de produit invalide!" << endl;  // Affiche une erreur si le code produit est invalide.
    }
}

