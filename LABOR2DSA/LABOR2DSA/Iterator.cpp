#include "Iterator.h"
#include "Matrix.h"
#include <exception>

//for kind of
//var a iteratorului indexul curent 
//throw ridica erori 

Iterator::Iterator(const Matrix& m) : matrix(m) 
{
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//constructorul
	i = 0;   //initializez i-ul si j-ul cu 0
	j = 0;	 //ca sa mi-l dea pe primul

}


void Iterator::first() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//primul element din matrice
	
	i = 0;
	j = 0;

}


void Iterator::next() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(1)
	//avg case: O(1)

	//returneaza urmatorul element
	if (j == matrix.spalten-1)
	{
		i++;
		j = 0;

	}
	else
	{
		j++;
	}

	//return matrix.element(i, j);
}

void Iterator::previous() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(1)
	//avg case: O(1)

	// returneaza elementul precedent
	if (j == 0)
	{
		i--;
		j = matrix.spalten - 1;
	}
	else
	{
		j--;
	}

	//return matrix.element(i, j);


}


TElem Iterator::getCurrent()
{
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//returneaza elementul curent
	if (valid())
		return matrix.element(i, j);
	else
	{
		std::exception e;
		throw e;
	}
}

bool Iterator::valid()
{
	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(1)
	//avg case: O(1)

	//verifica daca pozitia e valida
	if (i >= 0 && j >= 0 && i < matrix.zeilen && j < matrix.spalten)
		return true;
	
	
	return false;

}



