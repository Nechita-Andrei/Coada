#include <iostream>
#include <stdlib.h>
#include "Coada.h"
#include <exception>


using namespace std;

/*
Constructorul
*/
Coada::Coada()
{
	capacitate = 30;
	nrElem = 0;
	coada = (TElem*)malloc(capacitate * sizeof(TElem));
	prim = 1;
	ultim = 1;
}

int Coada::Ultimul()
{
	return ultim;
}

/*
Adauga elementul e in coada
*/
void Coada::adauga(TElem e)
{
	if (nrElem < capacitate)
	{
		coada[ultim] = e;
		nrElem++;
		if (ultim < capacitate)
			ultim++;
		else if (prim != 1)
			ultim = 1;
	}


	TElem* coadaNoua = (TElem*)malloc(sizeof(TElem) * (capacitate + 30));

	for (int i = 1; i <= capacitate; i++)
	{
		coadaNoua[i] = coada[i];
	}

	free(coada);

	coada = coadaNoua;
	capacitate += 30;


}

/*
Cauta elementul curent in coada
Returneaza elementul sau -1 daca coada e vida
*/
TElem Coada::element() const
{
	if (vida() == true)
		throw exception();
	else
		return TElem(coada[prim]);
}

/*
Sterge elementul curent din coada
Returneaza elementul sters sau -1 daca coada e vida
*/
TElem Coada::sterge()
{
	if (vida() == true)
		throw exception();

	/*else
	{
		TElem e;

		e = coada[prim];

		for (int i = prim; i < ultim - 1; i++)
			{
				coada[i] = coada[i + 1];
			}

		ultim--;

		return TElem(e);
	}*/

	TElem e = coada[prim];

	if (prim < capacitate)
		prim++;
	else
		prim = 1;

	nrElem--;

	return TElem(e);


}

/*
tipareste elementele din coada
*/
void Coada::tiparire()
{
	if (prim < ultim)
		for (int i = prim; i < ultim; i++)
			cout << coada[i] << " ";

	else
	{
		for(int i = prim; i < capacitate; i++)
		{
			cout << coada[i] << " ";
		}

		for (int i = 1; i < ultim; i++)
		{
			cout << coada[i] << " ";
		}
	}
}

/*
Verifica daca coada e vida 
Returneaza true daca coada e vida sau false in caz contrar
*/
bool Coada::vida() const
{
	if (prim == ultim)
		return true;

	return false;
}

/*
Destructor
*/
Coada::~Coada()
{
	free(coada);
}

