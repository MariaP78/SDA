#include "SetIterator.h"
#include "Set.h"
#include <exception>

//for kind of
//var a iteratorului indexul curent 
//throw ridica erori 

SetIterator::SetIterator(const Set& m) : set(m) //primeste set ul asta
{
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//constructorul
    i = 0;   //initializez i-ul cu 0
	         //ca sa mi-l dea pe primul
	
}


void SetIterator::first() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//pointeaza catre primul element
	i = 0;

}


void SetIterator::next() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	//avanseaza catre urmatorul element, face acest lucru pana la final

	if (valid()==false)  
	{
		std::exception e;
		throw e;

	}


	i++; //cresc i-ul

	while(set.bitarray[i]==0 && i <= set.maxim - set.minim) //acest while se face cand urmatorul bit e 0
		i++;

}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	
	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)
	
	//returneaza elementul curent

	if (valid() == false)  //daca nu e valid, arunca exceptie
	{
		std::exception e;
		throw e;
	}

	//returneaza elementul curent
	return i + set.minim;


}

bool SetIterator::valid() const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//verifica daca e pe o pozitie valida

	//returneaza un boolean (daca e adevarat sau fals)

	//daca e valid, returneaza true
	if (set.bitarray[i] ==1 && i >= 0 && i <= set.maxim - set.minim)
		return true;

	//daca nu e valid, returneaza false
	return false;
}



