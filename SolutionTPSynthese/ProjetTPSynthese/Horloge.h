#pragma once
// Manipulation de dates et d'heures


// Repr�sentation d'une date et d'une heure
struct horloge
{
   int annee = 0;     // L'ann�e
   int mois = 0;      // Le mois, entre 1 et 12, 1 pour janvier, 2 pour f�vrier, ..., 12 pour d�cembre
   int jour = 0;      // Le jour, entre 1 et le nombre maximum de jour dans le mois
   int heure = 0;     // L'heure, entre 0 et 23
   int minute = 0;    // Les minutes, entre 0 et 59
   int seconde = 0;   // Les secondes, entre 0 et 59
};


// Retourne la date et l'heure actuelles tel que configur�es sur l'ordinateur
horloge maintenant();
