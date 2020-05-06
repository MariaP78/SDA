#pragma once

#include <vector>

using namespace std;

typedef int TElem;


// computes the product of the k greatest elements from the vector
// if k <= 0, throws an exception
// n is the number of descendants for the heap
long long computeProduct(vector<TElem> vector, int k, int n);

class MaxHeap {
private:
	//Heap
	int kap; //capacitatea
	int len; //lungimea array-ului
	TElem* heap; //array ul meu

public:
	//constructor
	MaxHeap();

	//bubble up
	void bubble_up(int p,int n);

	// adauga un element nou in array
	bool add(TElem el,int n);

	//bubble down 
	void bubble_down(int p,int n);

	// sterge un element din array, acel element fiind radacina
	// in MaxHeap functia de remove sterge radacina (in cazul nostru fiind MaxHeap sterge maximul din array)
	// in MaxHeap, radacina este maximul din array
	TElem remove(int n);

	// returneaza numarul de elemente din array
	int size() const;

	// verifica daca array-ul e gol sau nu
	bool isEmpty() const;

	//destructor
	~MaxHeap();
};



