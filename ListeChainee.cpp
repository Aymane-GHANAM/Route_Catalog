/*************************************************************************
	ListeChainee  -  structure de donnée organisée de Trajets
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Aymane GHANAM
    e-mail               : aymane.ghanam@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeChainee::Afficher(void) const
{
	cout << endl
	     << "--------------------------------------" << endl;
	cout << "        CATALOGUE DES TRAJETS" << endl;
	cout << "--------------------------------------" << endl;

	Chainon *courant = premierChainon;
	int nbResultats = 0;

	// Tant que l'on atteint pas la fin de la liste on affiche le trajet
	while (courant != nullptr)
	{
		nbResultats++;
		courant->GetTrajet()->Afficher();
		courant = courant->GetChainonSuivant();
	}

	/* Affichage du nombre de trajets stockés dans la liste, algorithme très compliqué car très dépendant de l'orthographe de la langue française */
	if (nbResultats == 0)
	{
		cout << "Il n'y a aucun trajet dans le catalogue :/" << endl;
	}
	else if (nbResultats == 1)
	{
		cout << "--------------------------------------" << endl;
		cout << "1 trajet stocké" << endl;
	}
	else
	{
		cout << "--------------------------------------" << endl;
		cout << nbResultats << " trajets stockés" << endl;
	}
	cout << "--------------------------------------" << endl;
} // ----- Fin de Afficher

void ListeChainee::AfficherTrajetCompose() const
{
	Chainon *courant = premierChainon;

	while (courant != nullptr)
	{
		courant->GetTrajet()->AfficherEtape();
		courant = courant->GetChainonSuivant();
	}
	cout << endl;
} // ----- Fin de AfficherTrajetCompose

/*
void ListeChainee::AjouterEnTete(Trajet *trajet)
{
	Chainon *nouveau = new Chainon(trajet, premierChainon);
	premierChainon = nouveau;
	if (premierChainon->get_chainonSuivant() == NULL){
		dernierChainon = nouveau;
	}
} // ----- Fin de AjouterEnTete
*/

void ListeChainee::AjouterOrdreAlphabetique(Trajet *montrajet)
// Algorithme :
// recherche la position dans la liste chainée pour insérer un nouveau trajet
// en fonction de l'ordre alphabétique. On compare d'abord les départs puis
// ensuite les arrivées
{
	Chainon *nouveau = new Chainon(montrajet, nullptr);

	if (premierChainon == nullptr)
	{
		premierChainon = nouveau;
		dernierChainon = nouveau;
	}
	else if ((strcmp(montrajet->GetDepart(), premierChainon->GetTrajet()->GetDepart()) < 0) || ((strcmp(montrajet->GetDepart(), premierChainon->GetTrajet()->GetDepart()) == 0) && (strcmp(montrajet->GetArrivee(), premierChainon->GetTrajet()->GetArrivee()) <= 0)))
	{
		nouveau->SetChainonSuivant(premierChainon);
		premierChainon = nouveau;
	}
	else
	{
		Chainon *precedent = premierChainon;
		Chainon *courant = precedent->GetChainonSuivant();

		while (courant != nullptr)
		{
			if ((strcmp(montrajet->GetDepart(), courant->GetTrajet()->GetDepart()) < 0) || ((strcmp(montrajet->GetDepart(), courant->GetTrajet()->GetDepart()) == 0) && (strcmp(montrajet->GetArrivee(), courant->GetTrajet()->GetArrivee()) <= 0)))
			{
				nouveau->SetChainonSuivant(courant);
				precedent->SetChainonSuivant(nouveau);
				break;
			}
			else
			{
				precedent = courant;
				courant = precedent->GetChainonSuivant();
			}
		}

		if (courant == nullptr)
		{
			precedent->SetChainonSuivant(nouveau);
			dernierChainon = nouveau;
		}
	}
} // ----- Fin de AjouterOrdreAlphabetique

void ListeChainee::AjouterEnQueue(Trajet *trajet)
// Algorithme : ajoute un chainondSuivant au dernierChainon
{
	Chainon *nouveau = new Chainon(trajet, nullptr);

	if (dernierChainon == nullptr)
	{
		premierChainon = nouveau;
		dernierChainon = nouveau;
	}
	else
	{
		dernierChainon->SetChainonSuivant(nouveau);
		dernierChainon = nouveau;
	}
} // ----- Fin de AjouterEnQueue

const Trajet *const ListeChainee::GetPremierTrajet() const
// Algorithme : retourne le premier trajet, contenu par le premierChainon
{
	return premierChainon->GetTrajet();
} // ----- Fin de GetPremierTrajet

const Trajet *const ListeChainee::GetDernierTrajet() const
// Algorithme : retourne le trajet du dernierChainon de la liste chainée
// très utile pour les trajets composés
{
	return dernierChainon->GetTrajet();
} // ----- Fin de GetDernierTrajet

const bool ListeChainee::EstVide() const
// Algorithme :
// si le premierChainon de la liste est nullptr alors la liste est vide
{
	if (premierChainon == nullptr)
		return true;
	else
		return false;
} // ----- Fin de EstVide

void ListeChainee::Rechercher(const char *depart, const char *arrivee) const
// Algorithme :
// Recherche les trajets qui ont le depart et l'arrivée rentrés en paramètre et
// les affiche
{
	Chainon *courant = premierChainon;
	int nbResultats = 0;

	cout << endl
	     << "--------------------------------------" << endl;
	cout << "       RESULTAT DE LA RECHERCHE" << endl;
	cout << "--------------------------------------" << endl;

	while (courant != nullptr)
	{
		/* On parcours la ListeChainee pour trouver des trajets ou le depart et l'arrivée coincident afin de les afficher */

		if (!strcmp(courant->GetTrajet()->GetDepart(), depart) && !strcmp(courant->GetTrajet()->GetArrivee(), arrivee))
		{
			courant->GetTrajet()->Afficher();
			nbResultats++;
		}
		courant = courant->GetChainonSuivant();
	}

	/* Similaire à la fonction Afficher */
	if (nbResultats == 0)
	{
		cout << "Aucun résultat pour votre recherche" << endl;
	}
	else if (nbResultats == 1)
	{
		cout << "--------------------------------------" << endl;
		cout << "1 résultat pour votre recherche" << endl;
	}
	else
	{
		cout << "--------------------------------------" << endl;
		cout << nbResultats << " résultats pour votre recherche" << endl;
	}
	cout << "--------------------------------------" << endl;
} // ----- Fin de Rechercher

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ListeChainee::ListeChainee()
// Algorithme :
// initialise les chainons à nullptr
{
#ifdef MAP
	cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
	premierChainon = nullptr;
	dernierChainon = nullptr;

} //----- Fin de ListeChainee

ListeChainee::~ListeChainee()
// Algorithme :
// appelle le destructeur du premierChainon qui se chargera de supprimer tous
// les chainons de la liste récursivement
{
#ifdef MAP
	cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
	delete premierChainon;
} //----- Fin de ~ListeChainee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
