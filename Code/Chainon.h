/*************************************************************************
Chainon  -  un élement de la liste chainée avec un pointeur sur l'élement
suivant
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Aymane GHANAM
    e-mail               : aymane.ghanam@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Chainon> (fichier Chainon.h) ----------------
#if !defined(Chainon_H)
#define Chainon_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Chainon>
// Element d'une ListeChainee
// Contient un pointeur de Trajet et un pointeur de Chainon pointant vers le
// prochain élément de la liste chainée dans laquelle il est située. Si c'est
// le dernier chainon, il pointe vers nullptr.
//------------------------------------------------------------------------

class Chainon
{
	//----------------------------------------------------------------- PUBLIC
public:
	//-------------------------------- Méthodes publiques

	Chainon *GetChainonSuivant() const;
	// Mode d'emploi :
	// Renvoie un pointeur vers le Chainon suivant de la ListeChainee
	// à partir de la position du Chianon courant
	// Contrat :
	// La méthode n'agit pas sur les attributs du Chainon

	void SetChainonSuivant(Chainon *suivant);
	// Mode d'emploi :
	// Attribue le chainonSuivant du chainon courant
	// suivant : pointeur vers un Chainon qui sera placé comme le suivant
	// Contrat :
	// L'attribut chainonSuivant est modifié

	const Trajet *const GetTrajet() const;
	// Mode d'emploi :
	// Renvoie un pointeur de Trajet pointé constant sur le trajet du Chainon
	// Contrat :
	// Ne permet surtout pas de modifier le trajet stocké

	// ----------------------------- Constructeurs - destructeur

	Chainon(Trajet *monTrajet, Chainon *monChainonSuivant);
	// Mode d'emploi :
	// monTrajet : pointeur sur le trajet qui sera stocké par le Chainon
	// monChainonSuivant : pointeur vers le chainonSuivant
	// Contrat :
	//

	virtual ~Chainon();
	// Mode d'emploi :
	// Destructeur du Chainon, détruit le trajet et appelle les
	// destructeurs de tous les chainons qui le suivent
	// Contrat :
	//

	//----------------------------------------------------------- PRIVE

private:
	//-------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	Trajet *trajet;		 // le trajet stocké par le chainon
	Chainon *chainonSuivant; // le pointeur vers le chainonSuivant
};

//-------------------------------- Autres définitions dépendantes de <Chainon>

#endif // Chainon_H
