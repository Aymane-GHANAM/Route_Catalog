/*************************************************************************
TrajetCompose  -  classe fille de Trajet, décrit un Trajet de plusieurs étapes
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h)
#if !defined(TC_H)
#define TC_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeChainee.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Décrit un trajet composé de plusieurs étapes
// Les étapes sont stockées dans une ListeChainee de TrajetSimple
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
	//---------------------------------------------------------- PUBLIC

public:
	//------------------------------------------------ Méthodes publiques

	void Afficher() const;
	// Mode d'emploi :
	// Affiche le TrajetCompose avec toutes les étapes le composant
	// Contrat :
	// lecture uniquement

	const char *const GetDepart() const;
	// Mode d'emploi :
	// Renvoie un pointeur constant sur une chaine de caractère pointée
	// constante qui est le départ de la premiere étape du trajet
	// Contrat :
	// lecture uniquement

	const char *const GetArrivee() const;
	// Mode d'emploi :
	// Renvoie un pointeur constant sur une chaine de caractère pointée
	// constante qui est l'arrivee de la derniere étape du trajet
	// Contrat :
	// lecture uniquement

	//--------------------------------------- Constructeurs - destructeur
	TrajetCompose(ListeChainee *lesEtapes);
	// Mode d'emploi :
	// construit un TrajetComposé à partir d'une liste d'étapes
	// lesEtapes : liste chainée de TrajetSimple
	// Contrat :
	//

	virtual ~TrajetCompose();
	// Mode d'emploi :
	// appelle le destructeur de la liste etapes
	// Contrat :
	//

	//----------------------------------------------------------- PRIVE

private:
	//-------------------------------------------- Méthodes protégées

	//-------------------------------------------- Attributs protégés
	ListeChainee *etapes;
};

//------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TC_H
