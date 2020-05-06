#include "Set.h"
#include "SetITerator.h"

#include <iostream>


Set::Set() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//constructor

	minim = INT_MAX; //initializez minimul cu cea mai mare valoare
	maxim = INT_MIN; //initializez maximul cu cea mai mica valoare
	lange = 1; //initializez lungimea bitarray-ului cu 1
	           // acest lucru inseamna ca mi-am pregatit loc liber cand adaug prima data, am doar pozitia 0 in bitarray

	bitarray = new int[lange]; //initializez bitarray-ul
	elem_num = 0;  //numarul bitilor de 1 il initializez cu 0
}


bool Set::add(TElem elem) {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	//adauga element la set
	//verifica daca exista elementul pe care vreau sa il adaug
	//daca nu exista mi-l adauga

	//cand adaug primul element, el(elem) e atat min, cat si maxim
	if (minim == INT_MAX || maxim == INT_MIN) //Θ(1)
	{ 
		minim = elem; 
		maxim = elem;
	}

	if (elem > maxim) //daca elementul este mai mare ca maximul //O(n)  //face for doar cand sch dimensiunea
	{
		int differenz = elem - maxim; //diferenta dintre element si maxim
		//maresc dimensiunea bitarray-ului
		int* newbitarray = new int[lange + differenz];
		//copiez in newbitarray
		for (int i = 0; i < lange; i++)
			newbitarray[i] = bitarray[i];
		//cate locatii mai raman ca diferenta, le fac 0
		for (int i = lange; i < lange + differenz; i++)
			newbitarray[i] = 0;

		lange += differenz; //cresc lange cu diferenta dintre element si maxim
		delete[] bitarray;  //dealoc spatiul
		bitarray = newbitarray; //pun newbitarray-ul in bitarray
		maxim = elem;  //maximul primeste elementul elem

	}

	if (elem < minim) //daca elementul este mai mic ca minimul  //O(n)
	{
		int differenz = minim - elem; //dif dintre minim si element
		//maresc dimensiunea bitarray-ului
		int* newbitarray = new int[lange + differenz];
		
		//cate locatii mai raman ca diferenta, le fac 0
		for (int i = 0; i < differenz + 1 ; i++) //!!!!
			newbitarray[i] = 0;

		//copiez in newbitarray ce a mai ramas
		for (int i = differenz; i < lange+differenz; i++)
			newbitarray[i] = bitarray[i-differenz];  

		lange += differenz; //cresc lange cu diferenta dintre element si maxim
		delete[] bitarray; //dealoc spatiul
		bitarray = newbitarray; //pun newbitarray-ul in bitarray
		minim = elem; //maximul primeste elementul elem
	}


	int elemposition = elem - minim; //pozitia elementului in bitarray

	if (bitarray[elemposition] == 1)     //Θ(1)
		return false;         //este deja in bitarray

	bitarray[elemposition] = 1; //daca nu exista in bitarray il face 1
	elem_num++; //cresc numarul de biti de 1

	return true;

}

bool Set::remove(TElem elem) {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	//elimina elementul dorit

	int elemposition = elem - minim ; //pozitia elementului in bitarray
	
	if (elemposition >= 0) //daca pozitia elem in bitarray e mai mare sau egala cu 0
	{
		if (elemposition <= maxim - minim) //daca pozitia elem in bitarray e mai mica sau egala cu 0 
		{
			if (bitarray[elemposition] == 1) //daca elementul este in bitarray(are valoarea 1)
			{
				
				bitarray[elemposition] = 0; //il fac 0 pentru ca vreau sa il elimin
				elem_num--; //scad numarul bitilor de 1
				//cazul in care elimin minimul sau maximul
				if(elem_num != 0)
				{
					if (elem == minim) //daca vreau sa elimin minimul
					{
						int i = 1;
						while (bitarray[i] == 0)   //gaseste urmatorul minim
							i++;       
						//cand l-a gasit
						for (int j = 0; j < lange; j++)
							bitarray[j]= bitarray[j+i]; //shifteaza la stanga cu i pozitii
						lange -= i; //lungimea scade cu i
						minim += i; //minimul creste cu i
					}
					if (elem == maxim) ////daca vreau sa elimin maximul
					{
						int i = maxim - minim; //i= diferenta dintre maxim si minim
						while (bitarray[i] == 0)  //gaseste urmatorul maxim
							i++;

						maxim = maxim - lange + i + 1; //maximul devine maxim-lange+i+1
						lange = i + 1; //lange devine i+1
					}
				}
				else
				{
					//minim si maxim revin la valorile cu care le-am initializat
					minim = INT_MAX;  
					maxim = INT_MIN;
				}
				
				return true;

			}
		}
	}



	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)


	//returneaza true cand elementul e in bitarray
	// returneaza false, altfel(cand nu e)
	
	int elemposition = elem - minim;  //pozitia elementului in bitarray
	if (bitarray[elemposition] == 1 && elemposition >= 0 && elemposition <= maxim - minim)
		return true;

	return false;
}


int Set::size() const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

 
	return elem_num; //returneaza cate elemente am adaugat in bitarray

}


bool Set::isEmpty() const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//returneaza true cand e gol
	//returneaza false, altfel

	if (minim == INT_MAX || maxim == INT_MIN)
		return true;

	return false;
}


Set::~Set() {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//destructor

	delete[] bitarray; //dealoc spatiul
	
	//delete[] interval;

}


SetIterator Set::iterator() const {

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	return SetIterator(*this);
}