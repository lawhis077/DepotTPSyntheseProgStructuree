#pragma once
// Manipulation de dates et d'heures


// Représentation d'une date et d'une heure
struct horloge
{
   int annee = 0;     // L'année
   int mois = 0;      // Le mois, entre 1 et 12, 1 pour janvier, 2 pour février, ..., 12 pour décembre
   int jour = 0;      // Le jour, entre 1 et le nombre maximum de jour dans le mois
   int heure = 0;     // L'heure, entre 0 et 23
   int minute = 0;    // Les minutes, entre 0 et 59
   int seconde = 0;   // Les secondes, entre 0 et 59
};


// Retourne la date et l'heure actuelles tel que configurées sur l'ordinateur
horloge maintenant();
