#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -11111
typedef int TElem;
class SetIterator;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

private:
	//TODO - Representation

	int* bitarray; //declar bitarray-ul
	int lange; //lungimea bitarray-ului
	int minim; //nr minim din set
	int maxim; //nr maxim din set

	int elem_num; //numar de biti de 1(numara cati biti de 1 am)

public:
	//implicit constructor
	Set();

	//adds an element to the set
	//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
	bool add(TElem e);

	//removes an element from the set
	//returns true if e was removed, false otherwise
	bool remove(TElem e);

	//checks whether an element belongs to the set or not
	bool search(TElem elem) const;

	//returns the number of elements;
	int size() const;

	//check whether the set is empty or not;
	bool isEmpty() const;

	//return an iterator for the set
	SetIterator iterator() const;

	// destructor
	~Set();

};