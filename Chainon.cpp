/*************************************************************************
Chainon  -  un élement de la liste chainée avec un pointeur sur l'élement
suivant
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Aymane GHANAM
    e-mail               : aymane.ghanam@insa-lyon.fr
*************************************************************************/

//-------- Réalisation de la classe <Chainon> (fichier Chainon.cpp)-------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Chainon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Chainon *Chainon::GetChainonSuivant() const
// Algorithme : aucun
//
{
	return chainonSuivant;
}

void Chainon::SetChainonSuivant(Chainon *suivant)
// Algorithme : simple
//
{
	chainonSuivant = suivant;
}

const Trajet *const Chainon::GetTrajet() const
// Algorithme : basique
//
{
	return trajet;
}

//-------------------------------------------- Constructeurs - destructeur

Chainon::Chainon(Trajet *monTrajet, Chainon *monChainonSuivant)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Chainon>" << endl;
#endif

	trajet = monTrajet;
	chainonSuivant = monChainonSuivant;

} //----- Fin de Chainon

Chainon::~Chainon()
// Algorithme :
// Détruit le Trajet contenu dans le Chainon
// Appelle le destructeur du chainon suivant si celui-ci n'est pas le dernier
{
#ifdef MAP
	cout << "Appel au destructeur de <Chainon>" << endl;
#endif

	delete trajet;
	if (chainonSuivant != nullptr)
	{
		delete chainonSuivant;
	}

} //----- Fin de ~Chainon

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
