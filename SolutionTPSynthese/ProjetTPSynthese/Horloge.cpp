// Manipulation de dates et d'heures
#include <ctime>
#include "Horloge.h"

using namespace std;


horloge maintenant()
{
   time_t tempsSysteme = time(0);
   tm tempsDecompose;
   localtime_s(&tempsDecompose, &tempsSysteme);
   
   horloge dateEtHeureActuelles;
   dateEtHeureActuelles.annee = tempsDecompose.tm_year + 1900;
   dateEtHeureActuelles.mois = tempsDecompose.tm_mon + 1;
   dateEtHeureActuelles.jour = tempsDecompose.tm_mday;
   dateEtHeureActuelles.heure = tempsDecompose.tm_hour;
   dateEtHeureActuelles.minute = tempsDecompose.tm_min;
   dateEtHeureActuelles.seconde = tempsDecompose.tm_sec;

   return dateEtHeureActuelles;
}
