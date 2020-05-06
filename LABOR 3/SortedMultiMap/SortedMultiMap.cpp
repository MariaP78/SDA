#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation

	// constructor

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	rel = r; // initializez relatia cu r care este dat ca parametru

	kapazitat = 100; //initializez capacitatea
	firstEmpty = 0; //initializez firstEmpty-ul primul index din array

	nodes= new DLLANode[kapazitat]; //array de noduri

	nodes[0].info = NULL_TELEM; // initializez valoarea de pe prima pozitie

    head = -1; //indexul head
    tail = -1; //index tail
	nr_pairs = 0; // numarul de perechi de tip <key, value>
}

void SortedMultiMap::add(TKey c, TValue v) {
	//TODO - Implementation

	//adds a new key value pair to the sorted multi map

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	int i; //indexul cu care plec de la head

	i = head; //primul nod din lista
	

	//creez elem nou pe poz firstEmpty 
	//fac legaturile intre elem respectiv si cel de pe poz i
	//setez noul firstEmpty

	if (isEmpty()) //daca isEmpty e true => nu am niciun element
	{
		// asa ca aici adaug primul element
		head = firstEmpty; // head primeste primul gol
		tail = firstEmpty; // tail primeste primul gol

		// perechea pe care vreau sa o adaug (c si v date ca param in antetul functiei)
		nodes[firstEmpty].info.first = c;  // cheia devine c
		nodes[firstEmpty].info.second = v; // valoarea devine v

		//adaugand un singur element inseamna ca next si prev vor fi -1 pentru ca inca nu se leaga de alte elemente
		nodes[firstEmpty].next = -1;
		nodes[firstEmpty].prev = -1;

		nr_pairs++; // creste numarul de perechi
		firstEmpty = 1; //firstEmpty devine 1 pentru ca acum poz 0 e ocupata de elem(perechea) adaugata, iar urm pozitie goala e poz 1
	}
	else 
	{
		//cazul in care am elem in array si vreau sa adaug elemente(perechi)

		if (nr_pairs == kapazitat) //daca nr de perechi e egal cu capacitatea
		{
			//aici fac marirea capacitate/realocarea de memorie memorie
			if (kapazitat != 0)
				kapazitat = kapazitat * 2;// creez o capacitate de 2 ori mai mare ca cea anterioara
			else
				kapazitat += 1; //daca cap e 0 o cresc cu 1 ca altfel nu se modifica deloc

			DLLANode* aux = new DLLANode[kapazitat]; // creez un nou array cu capacitatea de 2 ori mai mare

			// copiez elementele din array-ul actual in noul array
			for (int i = 0; i < kapazitat; i++)                                 // O(n)
				aux[i] = nodes[i];

			// sterg array-ul vechi
			delete[] nodes;

			// noul array ia locul vechiului array
			nodes = aux;
		}
		
		//parcurg cat timp relatia e adevarata
		while (rel(nodes[i].info.first, c) && nodes[i].next != -1 && nodes[i].info.first != c)       // O(n)
		{
			i = nodes[i].next; //trece pe urmatorul
		}
		
		// cazul in care am o singura pereche
		if (nr_pairs == 1) 
		{
			if (rel(nodes[i].info.second, v) == true) //daca relatia e adevarata
			{   
				//adaug la final

				//perechea mea
				nodes[firstEmpty].info.first = c; //cheia devine c
				nodes[firstEmpty].info.second = v; //valoarea devine v 

				int nextf = nodes[firstEmpty].next; //pastrez nextul lui firstEmpty

				//aici creez legaturile corecte
				nodes[i].next = firstEmpty;
				nodes[firstEmpty].prev = i;
				nodes[firstEmpty].next = -1;

				tail = firstEmpty; // tail devine firstEmpty
				nr_pairs++; // cresc nr de perechi

				//daca nextul lui firstEmpty e in intervalul [0,nr_pairs], restabilesc legaturile pentru a se adauga corect
				if (nextf >= 0 && nextf <= nr_pairs)
				{
					firstEmpty = nextf; //firstEmpty devine nextf
					nodes[nextf].prev = -2; // prev ul lui devine -2
				}
				else
				{
					firstEmpty = nr_pairs; // firstEmpty devine nr_pairs
					nodes[firstEmpty].next = -2; // next ul lui devine -2
					nodes[firstEmpty].prev = -2;// prev ul lui devine -2
				}

				return; // iese 
			}
			else
			{
				//adaug la inceput

				//perechea mea
				nodes[firstEmpty].info.first = c; //cheia devine c
				nodes[firstEmpty].info.second = v; //valoarea devine v 


				int nextf = nodes[firstEmpty].next; //pastrez nextul lui firstEmpty

				//aici creez legaturile corecte
				nodes[firstEmpty].prev = -1;
				nodes[firstEmpty].next = i;
				nodes[i].prev = firstEmpty;

				head = firstEmpty; //head devine firstEmpty

				nr_pairs++; //cresc nr de pairs
				 
				//daca nextul lui firstEmpty e in intervalul [0,nr_pairs], restabilesc legaturile pentru a se adauga corect
				if (nextf >= 0 && nextf <= nr_pairs)
				{
					firstEmpty = nextf; //firstEmpty devine nextf
					nodes[nextf].prev = -2; // prev ul lui devine -2
				}
				else
				{
					firstEmpty = nr_pairs; // firstEmpty devine nr_pairs
					nodes[firstEmpty].next = -2; // next ul lui devine -2
					nodes[firstEmpty].prev = -2; // prev ul lui devine -2
				}

				return; //iese
			}
		}

		//cazul in care nu e una singura
		if (nodes[i].next != -1 && nodes[i].prev != -1)
		{
			//introduc undeva la mijloc

			//perechea mea
			nodes[firstEmpty].info.first = c; //cheia devine c
			nodes[firstEmpty].info.second = v; //valoarea devine v
			
			int nextf = nodes[firstEmpty].next; //pastrez nextul lui firstEmpty
			

			//creez legaturile
			nodes[firstEmpty].prev = i;
			nodes[firstEmpty].next = nodes[i].next;
			nodes[nodes[i].next].prev = firstEmpty;
			nodes[i].next = firstEmpty;

			nr_pairs++; //cresc nr de perechi

			//daca nextul lui firstEmpty e in intervalul [0,nr_pairs], restabilesc legaturile pentru a se adauga corect
			if (nextf >= 0 && nextf <= nr_pairs)
			{
				firstEmpty = nextf; //firstEmpty devine nextf
				nodes[nextf].prev = -2; // prev ul lui devine -2
			}
			else
			{
				firstEmpty = nr_pairs; // firstEmpty devine nr_pairs
				nodes[firstEmpty].next = -2; // next ul lui devine -2
				nodes[firstEmpty].prev = -2; // prev ul lui devine -2
			}
		}
		else
			if (nodes[i].next == -1) //daca e primul
			{
				//adaug la final

				//toate comentariile sunt analog cu cele in care adaug la final mai sus

				nodes[firstEmpty].info.first = c;
				nodes[firstEmpty].info.second = v;

				int nextf = nodes[firstEmpty].next;

				nodes[i].next = firstEmpty;
				nodes[firstEmpty].prev = i;
				nodes[firstEmpty].next = -1;

				tail = firstEmpty;
				nr_pairs++;
				
				if (nextf >= 0 && nextf <= nr_pairs)
				{
					firstEmpty = nextf;
					nodes[nextf].prev = -2;
				}
				else
				{
					firstEmpty = nr_pairs;
					nodes[firstEmpty].next = -2;
					nodes[firstEmpty].prev = -2;
				}
			}
			else
				{
					//cand adaug la inceput

				   //toate comentariile sunt analog cu cele in care adaug la inceput mai sus

					nodes[firstEmpty].info.first = c;
					nodes[firstEmpty].info.second = v;

					int nextf = nodes[firstEmpty].next;

					nodes[firstEmpty].prev = -1;
					nodes[firstEmpty].next = i;
					nodes[i].prev = firstEmpty;

					head = firstEmpty;

					nr_pairs++;

					if (nextf >= 0 && nextf <= nr_pairs)
					{
						firstEmpty = nextf;
						nodes[nextf].prev = -2;
					}
					else
					{
						firstEmpty = nr_pairs;
						nodes[firstEmpty].next = -2;
						nodes[firstEmpty].prev = -2;
					}

				}
		
	}

}

vector<TValue> SortedMultiMap::search(TKey c) const {
	//TODO - Implementation

	//returns the values belonging to a given key

	//caut in multimap cheia care e egala cu cea din param si valorile le pun intr-un vector, vectorul suchen_vektor

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	int i; //indexul cu care plec de la head

	vector <TValue> suchen_vektor; //vectorul in care pun valorile de care am nevoie(cele care apartin unei anumite chei-cea data ca param)

	i = head; //primul nod din lista


	//trec prin tot array ul si imi creez vectorul in care pun 
	//valorile de care am nevoie(cele care apartin unei anumite chei-cea data ca param)

	while (i != -1)                                               // O(n)
	{ 
		// daca cheia e egala cu cea data ca param 
		if(nodes[i].info.first == c)
			suchen_vektor.push_back(nodes[i].info.second);   //pun valoarea respectiva in vector
		 
		i = nodes[i].next;   //trec la urmatorul 
	}

	return suchen_vektor; // afisez vectorul de valori
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	int i; //indexul cu care plec de la head
	i = head; //primul nod din lista

	if (isEmpty() == false)  //daca nu e gol array ul meu(am ce sa sterg)
	{
		if (nodes[i].next == -1 && nodes[i].prev == -1)  //cazul in care am un singur element(o pereche adica)
		{
			//am un singur element in lista

			// head si tail sunt -1
			head = -1;
			tail = -1;

			//fac legaturile corecte pentru a realiza stergerea
			// e nevoie doar sa restabilesc legaturile pentru a sterge elementul
			// asa am inteles conform cursului la sectiunea DLLA/SLLA

			nodes[firstEmpty].prev = i;
			nodes[i].next = firstEmpty;
			nodes[i].prev = -1;
			firstEmpty = i;

			nr_pairs--; // scad nr de perechi din moment ce am sters

		    return true; // returnez true daca am sters
		}

		//daca nu s a terminat, parcurg pentru a avansa
		//daca o pereche e stearsa si mai gasesc una la fel, o sterg doar pe prima
		while (i != -1 && nodes[i].info.first != c && nodes[i].info.second != v)
		{
			i = nodes[i].next; // trece la urmatorul
		}

		
		int newi = i; //salvez poz actuala(pe care vreau sa o sterg)

		//fac legaturile

		nodes[nodes[i].prev].next = nodes[i].next;
		nodes[nodes[i].next].prev = nodes[i].prev;

		nodes[firstEmpty].prev = i;
		nodes[newi].next = firstEmpty;
		nodes[newi].prev = -2;
		firstEmpty = newi;

		nr_pairs--; //scad nr de perechi dupa ce am sters perechea


		return true;  //returnez true
		
	}
	
	return false; //cand nu am ce sa sterg returnez false
}


int SortedMultiMap::size() const {
	//TODO - Implementation

	//returns the number of key-value pairs from the sorted multimap

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	return nr_pairs; // returnez nr de perechi <key, value>
}

bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//verifies if the sorted multi map is empty

	if (nr_pairs == 0) // daca smm e gol returnez true
		return true;

	return false; //altfel e false
}

vector<TValue> SortedMultiMap::key_pairs() const {


	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	int i; //indexul cu care plec de la head
	i = head; //primul nod din lista

	vector <TValue> keys; // vector pentru chei
	vector <TValue> keys_frecv; //vector pentru frecventele cheilor
	int key_counter = 0;
	

	//trec prin tot
	while (i != -1)                                               // O(n)
	{
		keys.push_back(nodes[i].info.first); //pun cheile in vector

		int cheie = nodes[i].info.first; //retin cheia
		if (nodes[i].info.first == cheie)  // daca e egala cu cheia cresc counter ul ca sa ii nr frecv
		    key_counter++; //numar aparitiile cheii

		keys_frecv.push_back(key_counter);
	}

	//returnez cei doi vectori pentru chei si frecventa lor

	return keys;

	return keys_frecv;


	//o testez in short test
}

SMMIterator SortedMultiMap::iterator() const {

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation
	//destructor

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

}
