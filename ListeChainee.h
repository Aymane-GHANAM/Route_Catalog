/*************************************************************************
	ListeChainee  -  structure de donnée organisée de Trajets
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Aymane GHANAM
    e-mail               : aymane.ghanam@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----
#if !defined(ListeChainee_H)
#define ListeChainee_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Chainon.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// Crée une structure organisée de Trajets de tous types
// Les trajets peuvent être ajoutés en queue (étapes de TrajetCompose)
// ou par ordre alphabétique (pour les ajouts dans le Catalogue)
// En attribut le premierChainon et le dernierChainon qui permettent
// d'ajouter ou accéder rapidement aux informations (départ et arrivée)
//------------------------------------------------------------------------

class ListeChainee
{
	//---------------------------------------------------------- PUBLIC

public:
	//------------------------------------------------ Méthodes publiques

	void Afficher() const;
	// Mode d'emploi :
	// Affiche tous les Trajets de la ListeChainee (usage Catalogue)
	// Contrat :
	// Lecture des éléments de la liste sans écriture

	void AfficherTrajetCompose() const;
	// Mode d'emploi :
	// Affiche tous les trajets étapes d'un TrajetCompose
	// Contrat :
	// Lecture des éléments de la liste sans écriture

	/*
	void AjouterEnTete(Trajet *trajet);
	// Mode d'emploi :
	// 
	// Contrat :
	//
	*/

	void AjouterOrdreAlphabetique(Trajet *trajet);
	// Mode d'emploi :
	// trajet : pointeur vers un Trajet
	// ajoute ce trajet de manière à conserver l'ordre alphabétique
	// Contrat :
	// droits en écriture sur le placement des elements dans la liste

	void AjouterEnQueue(Trajet *trajet);
	// Mode d'emploi :
	// trajet : pointeur vers un Trajet
	// ajoute ce trajet en fin de liste
	// Contrat :
	// droits en écriture sur le placement des elements dans la liste

	const Trajet *const GetPremierTrajet() const;
	// Mode d'emploi :
	// retourne le premier Trajet de la liste (usage TrajetCompose)
	// Contrat :
	// droits en lecture uniquement

	const Trajet *const GetDernierTrajet() const;
	// Mode d'emploi :
	//retourne le dernier Trajet de la liste (usage TrajetCompose)
	// Contrat :
	// droits en lecture uniquement

	const bool EstVide() const;
	// Mode d'emploi :
	// retourne true si la liste est vide, false sinon
	// Contrat :
	// droits en lecture uniquement

	void Rechercher(const char *depart, const char *arrivee) const;
	// Mode d'emploi :
	// depart : chaine de caractère ville de départ
	// arrivee : chaine de caractère ville d'arrivee
	// Contrat :
	// droits en lecture uniquement

	//------------------------------------------ Surcharge d'opérateurs

	//-------------------------------------- Constructeurs - destructeur

	ListeChainee();
	// Mode d'emploi :
	// Crée une liste chainée vide
	// Contrat :
	//

	virtual ~ListeChainee();
	// Mode d'emploi :
	// detruit la liste en appelant le destructeur du premierChainon qui
	// récursivement détruira son suivant
	// Contrat :
	//

	//------------------------------------------------------------- PRIVE

private:
	//------------------------------------------------ Méthodes protégées

	//------------------------------------------------ Attributs protégés
	Chainon *premierChainon;
	Chainon *dernierChainon;
};

//--------------------------- Autres définitions dépendantes de <ListeChainee>

#endif // ListeChainee_H
