#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	//TODO - Implementation

	//constructorul

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	iter = map.head; // iter primeste head-ul map-ului
}

void SMMIterator::first(){
	//TODO - Implementation

	//returneaza primul 

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	iter = map.head; // iter primeste head-ul map ului
}

void SMMIterator::next(){
	//TODO - Implementation

	// trece la urmatorul

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	iter = map.nodes[iter].next;
}

bool SMMIterator::valid() const{
	//TODO - Implementation

	// verifica daca pozitia e valida

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(1)
	//avg case: O(1)

	if (iter != -1)
		return true;

	return false;
}

TElem SMMIterator::getCurrent() const{
	//TODO - Implementation

	//returneaza valoarea curenta

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	return map.nodes[iter].info;
}


