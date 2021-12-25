/*************************************************************************
TrajetSimple  -  classe fille de Trajet, décrit un Trajet d'une seule étape
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if !defined(TS_H)
#define TS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Décrit un trajet d'une seule étape (un départ, une arrivée et un moyen
// de transport)
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
	//---------------------------------------------------------- PUBLIC

public:
	//--------------------------------------------- Méthodes publiques

	void Afficher() const;
	// Mode d'emploi :
	// Affiche le TrajetSimple sur une ligne
	// Contrat :
	// lecture uniquement

	void AfficherEtape() const;
	// Mode d'emploi :
	// dans le parcours des étapes d'un TrajetCompose pour affichage des
	// étapes
	// Contrat :
	// lecture uniquement

	const char *const GetDepart() const;
	// Mode d'emploi :
	// Renvoie un pointeur constant sur une chaine de caractère pointée
	// constante qui est le départ du trajet
	// Contrat :
	// lecture uniquement

	const char *const GetArrivee() const;
	// Mode d'emploi :
	// Renvoie un pointeur constant sur une chaine de caractère pointée
	// constante qui est l'arrivée du trajet
	// Contrat :
	// lecture uniquement

	//------------------------------------ Constructeurs - destructeur

	TrajetSimple(const char *leDepart, const char *lArrivee, const char *moyen);
	// Mode d'emploi :
	// copie en profondeur les paramètres dans des attributs alloués au
	// plus court
	// Contrat :
	//

	virtual ~TrajetSimple();
	// Mode d'emploi :
	// detruit les trois attributs (chaines de caractères)
	// Contrat :
	//

	//---------------------------------------------------------- PRIVE

private:
	//----------------------------------------------- Méthodes protégées

	//----------------------------------------------- Attributs protégés
	char *depart;
	char *arrivee;
	char *moyenTransport;
};

//------------------------ Autres définitions dépendantes de <TrajetSimple>

#endif // TS_H
