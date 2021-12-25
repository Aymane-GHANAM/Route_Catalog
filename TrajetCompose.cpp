/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const
{
	cout << GetDepart() << " - " << GetArrivee() << " : " << endl;
	etapes->AfficherTrajetCompose();
} //----- Fin de Afficher

const char *const TrajetCompose::GetDepart() const
{
	return etapes->GetPremierTrajet()->GetDepart();
} //----- Fin de GetDepart

const char *const TrajetCompose::GetArrivee() const
{
	return etapes->GetDernierTrajet()->GetArrivee();
} //----- Fin de GetArrivee

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(ListeChainee *lesEtapes) : Trajet()
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	etapes = lesEtapes;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete etapes;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
