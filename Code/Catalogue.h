/*************************************************************************
      Catalogue  -  la liste de trajets manipulable par l'utilisateur
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ---
#if !defined(CAT_H)
#define CAT_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeChainee.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes
static const int TAILLE_MAX_STRING = 256;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Liste des trajets rentrés par l'utilisateur
// L'utilisateur peut afficher les trajets, en insérer de nouveau ou en rechercher à partir d'un depart et une arrivée
//------------------------------------------------------------------------

class Catalogue
{
	//--------------------------------------------------------- PUBLIC

public:
	//-------------------------------------------- Méthodes publiques
	void Afficher() const;
	// Mode d'emploi :
	// affiche l'ensemble des trajets du catalogue
	// maVariableCatalogue.Afficher(); -> pour un pointeur

	void Inserer();
	// Mode d'emploi :
	// affiche les instructions d'insertion pour l'utilisateur, si tout est correct, l'insertion d'un trajet dans le catalogue est effectuée

	void Rechercher() const;
	// Mode d'emploi :
	// affiche les instructions de recherche pour l'utilsateur si le catalogue n'est pas vide. La méthode appelle la méthode rechercher de ListeChainee qui demande un depart et une arrivee en parametres

	//--------------------------------- Constructeurs - destructeur
	Catalogue();
	// Mode d'emploi :
	// Construit un catalogue vide (sans Trajets : liste vide)
	// Contrat : aucun
	//

	virtual ~Catalogue();
	// Mode d'emploi :
	// aucun paramètres, appelle le destructeur de ListeChainee

	//--------------------------------------------------------- PRIVE

private:
	//----------------------------------------------- Méthodes protégées
	int ajouterTrajet(Trajet *trajet);
	// Mode d'emploi :
	// trajet : pointeur sur un trajet (Simple ou Compose)
	// ajoute dans le catalogue dans l'ordre alphabetique (méthode ListeChainee)

	//--------------------------------------------- Attributs protégés
	/* La liste chainée qui continent les Trajets du Catalogue */
	ListeChainee *liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CAT_H
