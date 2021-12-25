/*************************************************************************
      Catalogue  -  la liste de trajets manipulable par l'utilisateur
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Alexis REIS
    e-mail               : alexis.reis@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
{
	liste->Afficher();
} //----- Fin de Afficher

void Catalogue::Inserer()
{
	int entree;

	// Necessaire à la fabrication d'un TrajetSimple
	char depart[TAILLE_MAX_STRING];
	char arrivee[TAILLE_MAX_STRING];
	char transport[TAILLE_MAX_STRING];

	// Necessaire à la fabrication d'un TrajetCompose
	int nEtapes = 1;
	ListeChainee *lesTrajets;

	cout << endl
	     << "--------------------------------------" << endl;
	cout << "        INSERTION D'UN TRAJET" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Choix du type de trajet à insérer" << endl;
	cout << "1 - Sans etapes intermediares" << endl;
	cout << "2 - En plusieurs etapes" << endl
	     << endl;

	/* L'utilisateur rentre le chiffre correspondant à son action */
	cout << ">> : ";
	cin >> entree;
	/* On vide le buffer pour éviter de prendre une chaine vide plus tard dans une entrée de chaine de caractère */
	getchar();

	/* Tant que l'entrée est invalide on redemande une entrée */
	while (entree < 1 || entree > 2)
	{
		cout << "Votre entrée est invalide. Veuillez retaper." << endl;
		cin >> entree;
		getchar();
	}

	/* Création d'un trajet selon le choix de l'utilisateur */
	switch (entree)
	{
	case 1:
		/* INSERTION D'UN TRAJET SIMPLE */
		cout << endl
		     << "--------------------------------------" << endl;
		cout << "Insertion d'un trajet sans etapes :" << endl;

		/* Entrée ville de départ, arrivée et moyen de transport : utilisation de la fonction cin.getline pour pouvoir rentrer des noms de villes à plusieurs mots sans erreurs... */
		cout << "Insérer le lieu de départ : ";
		cin.getline(depart, TAILLE_MAX_STRING);

		cout << "Inserer le lieu d'arrivée : ";
		cin.getline(arrivee, TAILLE_MAX_STRING);

		cout << "Insérer le type de transport : ";
		cin.getline(transport, TAILLE_MAX_STRING);

		/* Ajout d'un nouveau trajet simple créé à partir des paramètres rentrés */
		ajouterTrajet(new TrajetSimple(depart, arrivee, transport));
		break;

	case 2:
		/* INNSERTION D'UN TRAJET COMPOSÉ */
		lesTrajets = new ListeChainee();
		cout << endl
		     << "--------------------------------------" << endl;
		cout << "Insertion d'un trajet composé de plusieurs etapes" << endl;

		cout << "Insérer le lieu de départ : ";
		cin.getline(depart, TAILLE_MAX_STRING);

		/* Tant que l'utilisateur n'indique pas la fin de son trajet */
		while (entree)
		{
			cout << endl
			     << "--------------------------------------" << endl;
			cout << "Etape n°" << (nEtapes) << endl;

			cout << "Inserer le lieu d'arrivée pour cette étape: ";
			cin.getline(arrivee, TAILLE_MAX_STRING);

			cout << "Insérer le type de transport pour ce trajet : ";
			cin.getline(transport, TAILLE_MAX_STRING);

			lesTrajets->AjouterEnQueue(new TrajetSimple(depart, arrivee, transport));

			/* Si deux étapes sont déjà rentrées on peut demander si le Trajet est terminé à l'utilisateur (TrajetCompose correct à partir de deux étapes sinon c'est un TrajetSimple...) */

			if (nEtapes >= 2)
			{
				cout << "Voulez-vous ajoutez une nouvelle étape à votre trajet ?\n1 - Oui\n0 - Non" << endl;
				cout << ">> : ";
				cin >> entree;
				getchar();

				while (entree < 0 || entree > 1)
				{
					cout << "Entrée invalide veuillez retaper" << endl;
					cin >> entree;
					getchar();
				}
			}

			nEtapes++;

			/* L'arrivée du premier TrajetSimple d'un TrajetCompose est le départ du prochain, on effectue donc une copie de façon à ne pas avoir à rentrer manuellement les départs intermédiaires */
			strcpy(depart, arrivee);
		}
		ajouterTrajet(new TrajetCompose(lesTrajets));
		break;
	default:
		cout << "Erreur dans la saisie" << endl;
	}

	cout << "Trajet inséré" << endl;
}

void Catalogue::Rechercher() const
{
	cout << endl
	     << "--------------------------------------" << endl;
	cout << "       RECHERCHE D'UN TRAJET" << endl;
	cout << "--------------------------------------" << endl;

	/* La recherche dans le catalogue n'a de sens que si la liste qu'il contient n'est pas vide */
	if (!liste->EstVide())
	{
		/* Entrée de la ville de départ et d'arrivée souhaitée */
		char depart[TAILLE_MAX_STRING];
		char arrivee[TAILLE_MAX_STRING];

		cout << "Insérer le lieu de départ : ";
		cin.getline(depart, TAILLE_MAX_STRING);

		cout << "Inserer le lieu d'arrivée : ";
		cin.getline(arrivee, TAILLE_MAX_STRING);

		/* On recherche dans la liste les trajets dont les départs et arrivées correspondent */
		liste->Rechercher(depart, arrivee);
	}
	else
	{
		cout << "Il n'y a aucun trajet dans le catalogue :/" << endl;
		cout << "--------------------------------------" << endl;
	}
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
	/* Appel au constructeur d'une liste chainée vide */
	liste = new ListeChainee;
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	/* Appel au destructeur de ListeChainee */
	delete liste;
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int Catalogue::ajouterTrajet(Trajet *trajet)
{
	liste->AjouterOrdreAlphabetique(trajet);
	return 0;
} //----- Fin de AjouterTrajet