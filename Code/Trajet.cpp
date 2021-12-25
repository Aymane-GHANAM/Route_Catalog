/*************************************************************************
                           Trajet  -  classe abstraite
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher() const
{
	cout << "Afficher de Trajet (erreur)" << endl;
} //----- Fin de Afficher

void Trajet::AfficherEtape() const
{
	cout << "AfficherEtape de Trajet (erreur)" << endl;
} //----- Fin de AfficherEtape

const char *const Trajet::GetDepart() const
{
	return "GetDepart de Trajet (erreur)";
} //----- Fin de GetDepart

const char *const Trajet::GetArrivee() const
{
	return "GetArrivee de Trajet (erreur)";
} //----- Fin de GetArrivee

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet()
{
#ifdef MAP
	cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

Trajet::~Trajet()
{
#ifdef MAP
	cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
