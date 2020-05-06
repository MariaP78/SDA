#pragma once

#include "SortedMultiMap.h"



class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	//TODO - Representation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	int iter; //iteratorul 
	
public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

