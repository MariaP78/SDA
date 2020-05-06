#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -11111
#define NULL_TELEM pair<TKey, TValue>(-11111, -11111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


struct DLLANode
{
    TElem info;
    int prev;
    int next;
};


class SortedMultiMap {

	friend class SMMIterator;

    private:
		//TODO - Representation

        //COMPLEXITATE:
        //best case: Θ(1)
        //worst case: Θ(1)
        //avg case: Θ(1)

        DLLANode* nodes; //array de noduri
        int kapazitat; // capacitatea
        int firstEmpty; // firstEmpty, prima pozitie goala
        int head; // head-ul care e un index
        int tail; // tail-ul care e un index
        Relation rel; // relatia 
        int nr_pairs; // nr perechi de tip <key,value>
  

    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    //Der Bag aller Schlüssel, räpresentiert als Paare der form (Element, Frequenz)
    vector<TValue> key_pairs() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};
