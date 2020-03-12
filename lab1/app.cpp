#include <iostream>
#include "Coada.h"
#include "testScurt.h"
#include "testLung.h"

using namespace std;

int main()
{
	//testAll();
	testAllExtins();
	cout << "Merge";

	bool conditie = true;
	int comanda;

	Coada c;

	while (conditie)
	{
		printf("........................Meniu.........................\n");
		printf("| [1] Adauga                                          |\n");
		printf("| [2] Sterge                                          |\n");
		printf("| [3] Element                                         |\n");
		printf("| [4] Vida                                            |\n");
		printf("| [5] Afisare                                         |\n");
		printf("| [0] Exit                                            |\n");
		printf("......................................................\n");

		cout << "\nIntroduceti comanda: ";
		cin >> comanda;
		cout << "\n";

		if (comanda == 0)
		{
			conditie = false;
		}

		else if (comanda == 1)
		{
			TElem e;
			
			cout << "Introduceti elementul: ";
			cin >> e;
			cout << "\n";
			c.adauga(e);
		}

		else if (comanda == 2)
		{
			TElem ok;

			try
			{
				ok = c.sterge();
				cout << "Elementul " << ok << " a fost sters cu succes\n";
			}
			catch (exception&)
			{
				cout << "Nu exista elemente de sters\n";
			}

		}

		else if (comanda == 3)
		{
			TElem e;

			try
			{
				e = c.element();
				cout << "Elementul curent este: " << e << "\n";
			}
			catch (exception&)
			{
				cout << "Nu exista elemente in coada!\n";
			}

		}

		else if (comanda == 4)
		{
			bool ok;

			ok = c.vida();

			if (ok == true)
			{
				cout << "Coada este vida\n";
			}

			else
			{
				cout << "Coada nu este vida\n";
			}
		}

		else if (comanda == 5)
		{
			printf("Elementele din coada sunt: ");

			/*bool ok;

			ok = c.vida();

			while (ok == false)
			{
				TElem e = c.element();

				cout << e << " ";

				c.sterge();

				ok = c.vida();
			}*/

			if (c.vida() == true) cout << "Nu exista elemente";
			else
				c.tiparire();

			cout << '\n' << '\n';
		}

		else
		{
			cout << "Comanda invalida!\n\n";
		}
	}


	return 0;
}