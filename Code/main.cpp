using namespace std;
#include <iostream>

#include "Catalogue.h"

int main()
{
	Catalogue *catalogue = new Catalogue();
	int entree = 0;

	while (entree != 4)
	{
		cout << "--------------------Catalogue de trajets-------------------- " << endl
		     << endl;
		cout << "Veuillez entrer le chiffre correspondant à l'action souhaitée" << endl
		     << endl;
		cout << "\t1 - Afficher tous les trajets du catalogue" << endl;
		cout << "\t2 - Insérer un nouveau trajet" << endl;
		cout << "\t3 - Rechercher un trajet" << endl;
		cout << "\t4 - Sortir du programme" << endl
		     << endl;

		cout << ">> : ";
		cin >> entree;
		getchar();
		while (entree < 1 || entree > 4)
		{
			cout << "Votre entrée est invalide. Veuillez retaper." << endl;
			cout << ">> : ";
			cin >> entree;
			getchar();
		}

		switch (entree)
		{
		case 1:
			catalogue->Afficher();
			break;
		case 2:
			catalogue->Inserer();
			break;
		case 3:
			catalogue->Rechercher();
			break;
		case 4:
			cout << "Au revoir" << endl;
			break;
		default:
			cout << "Votre entrée est invalide. Veuillez reessayer." << endl;
			break;
		}
		cout << "-- Appuyer sur ENTREE pour continuer" << endl;
		getchar();
	}

	delete catalogue;
	return 0;
}