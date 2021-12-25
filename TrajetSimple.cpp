/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
{
	cout << depart << " - " << arrivee << " en " << moyenTransport << endl;
} // ----- Fin de Afficher

void TrajetSimple::AfficherEtape() const
{
	cout << "\t" << depart << " - " << arrivee << " en " << moyenTransport << endl;
} // ----- Fin de AfficherEtape

const char *const TrajetSimple::GetDepart() const
{
	return depart;
} // ----- Fin de GetDepart

const char *const TrajetSimple::GetArrivee() const
{
	return arrivee;
} // ----- Fin de GetArrivee

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char *leDepart, const char *lArrivee, const char *moyen) : Trajet()
{
	/* Copie en profondeur et au plus court de chacun des paramètres */
	depart = new char[strlen(leDepart) + 1];
	strcpy(depart, leDepart);

	arrivee = new char[strlen(lArrivee) + 1];
	strcpy(arrivee, lArrivee);

	moyenTransport = new char[strlen(moyen) + 1];
	strcpy(moyenTransport, moyen);
} // ----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	/* Destruction des trois attributs chaines de caractères alloués dans le constructeur */
	delete[] depart;
	delete[] arrivee;
	delete[] moyenTransport;
} // ----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
