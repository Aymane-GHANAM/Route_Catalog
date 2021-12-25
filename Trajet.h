/*************************************************************************
                        Trajet  -  classe abstraite
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#if !defined(T_H)
#define T_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Le type Trajet recouvre les deux types de Trajet que nous manipulons
// Ainsi une ListeChainee de Trajet peut contenir aussi bien des TrajetSimple
// que des TrajetCompose par relation d'héritage
// Trajet est la classe mère abstraite de TrajetSimple et TrajetCompose
//------------------------------------------------------------------------

class Trajet
{
	//---------------------------------------------------------- PUBLIC

public:
	//---------------------------------------------- Méthodes publiques

	virtual void Afficher() const = 0;
	// Mode d'emploi :
	// Appelle la methode Afficher du type associé à l'appelant
	// Contrat :
	// méthode virtuelle pure

	virtual void AfficherEtape() const;
	// Mode d'emploi :
	// Affichage d'un étape d'un TrajetCompose
	// Appelle la methode AfficherEtape du type associé à l'appelant (TrajetSimple)
	// Contrat :
	// lecture

	virtual const char *const GetDepart() const;
	// Mode d'emploi :
	// Renvoie un pointeur constant sur une chaine de caractère pointée
	// constante qui est le départ
	// Appelle la methode getDepart du type associé à l'appelant
	// Contrat :
	// lecture uniquement

	virtual const char *const GetArrivee() const;
	// Mode d'emploi :
	// Renvoie un pointeur constant sur une chaine de caractère pointée
	// constante qui est l'arrivée
	// Appelle la methode getArrivee du type associé à l'appelant
	// Contrat :
	// lecture uniquement

	//------------------------------------ Constructeurs - destructeur

	Trajet();
	// Mode d'emploi :
	// Jamais utilisé, la classe étant abstraite le type Trajet ne peut être instancié
	// Contrat :
	//

	virtual ~Trajet();
	// Mode d'emploi :
	// Appelle le destructeur du type associé à l'appelant (relation d'héritage)
	// Contrat :
	//

	//------------------------------------------------------------- PRIVE

protected:
	//------------------------------------------------ Méthodes protégées

	//----------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // T_H
