#include "Problema14.h"
#include <exception>

MaxHeap::MaxHeap()
{
	     // constructor
	//////////////////////////
	     // COMPLEXITATE:
	     // best case: Θ(1)
	     // worst case: Θ(1)
	     // avg case: Θ(1)
	
	len = 0; //lungimea array-ului
	kap = 10000; //capacitatea
	heap = new TElem[kap]; //initializez array-ul

}

void MaxHeap::bubble_up(int p,int n) // n-aren heap
{
	// bubble up
	// p este pozitia de la care trebuie sa urc nodul nou, pozitia nodului
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: O(1)
		 // worst case: O(logn(n)) // logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
		 // avg case: O(logn(n)) // logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
		       // complexitatea este aceasta pentru ca inaltimea arborelui este logaritmica
	int poz = p; // pozitia nodului
	TElem elem = heap[p]; // caut pozitia elementului
	int parent = (p-1) / n; // setez indicele parintelui
	while (poz > 0 && elem > heap[parent])
	{
		// nodul parinte e mutat jos
		heap[poz] = heap[parent];
		poz = parent;
		parent = (poz-1) / n;
	}
	heap[poz] = elem; // am gasit pozitia elementului
}

bool MaxHeap::add(TElem el,int n) 
{
	// adauga un element nou in array
	// el este elementul pe care vreau sa il adaug
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: O(1)
		 // worst case: O(logn(n)) // logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
		 // avg case: O(logn(n)) // logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
			   // complexitatea este aceasta pentru ca inaltimea arborelui este logaritmica
	
	if (len == kap) // daca lungimea e egala cu capacitatea
	{   
		// resize, realoc memoria/ maresc capacitatea
		
		kap = kap * n;  // capacitatea devine capacitate*n pt ca heap ul are n copii

		TElem* newheap = new TElem[kap]; // creez un array nou cu capacitatea de n ori mai mare

		// copiez elementele din array-ul actual in noul array
		for (int i = 0; i < len; i++)
			newheap[i] = heap[i];  

		delete[] heap; // sterg array-ul vechi
		heap = newheap; // noul array ia locul vechiului array
	}

	heap[len] = el; // elementul nou adaugat
	bubble_up(len,n); // restabilesc heap-ul prin bubble_up pt a indeplini conditiile de a fi heap
	len = len + 1; // cresc lungimea din moment ce am adaugat un element nou
	
	return true; // returnez true daca a adaugat corect(am facut functia de tip bool pentru a o putea testa in ShortTests.cpp
}

void MaxHeap::bubble_down(int p, int n) // n-aren heap
{
	//bubble down
    // p este pozitia de la care trebuie sa cobor nodul nou
    
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: O(1)
		 // worst case: O(n*logn(n)) // n*logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
		                             // inmultesc cu n din cauza for-urilor
		 // avg case: O(n*logn(n)) // n*logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
		                             // inmultesc cu n din cauza for-urilor
			   // complexitatea este aceasta pentru ca inaltimea arborelui este logaritmica *n (de la for)
 
	int poz = p; // p este pozitia de la care trebuie sa cobor nodul nou, pozitia nodului
	int* children = new int[n + 1]; // aici imi fac un array nou pentru a retine indicii copiilor nodului parinte
	while (1)
	{
		for (int i = 1; i <= n; i++)
		{
			if ((n * poz + i) < len)
				children[i] = n * poz + i; //copiii
			else
				children[i] = -1; // daca nodul e frunza, adica nu are copii
		}
		TElem maxChild = -1;  // copilul maxim, in maxChild il stochez
		int maxChildindex = 0; //indicele copilului maxim

		for (int i = 1; i <= n; i++)
		{
			// acest for este pentru gasirea maximului dintre toti copiii unui nod
			if (children[i] != -1 && heap[children[i]] > maxChild)
			{
				maxChild = heap[children[i]];
				maxChildindex = children[i];
			}
		}
		if (maxChild == -1) break; // nod frunza

		if (heap[poz] < heap[maxChildindex])  // daca heap[maxChildindex]>heap[poz] atunci interschimb
		{
			TElem tmp = heap[poz];
			heap[poz] = heap[maxChildindex];
			heap[maxChildindex] = tmp;
		}
		poz = maxChildindex; // pozitia/indicele nodului primeste indicele copilului maxim

	}
}

	
TElem MaxHeap::remove(int n)
{
	// sterge un element din array, acel element fiind radacina
	// in MaxHeap functia de remove sterge radacina (in cazul nostru fiind MaxHeap sterge maximul din array)
	// in MaxHeap, radacina este maximul din array
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: O(1)
		 // worst case: O(n*logn(n)) // n*logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
									 // inmultesc cu n din cauza for-urilor
		 // avg case: O(n*logn(n)) // n*logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
									 // inmultesc cu n din cauza for-urilor
			   // complexitatea este aceasta pentru ca inaltimea arborelui este logaritmica *n (de la for)
			   
	if (len <= 0) //daca lungimea e mai mica sau egala cu 0
	{
		return NULL; //heap ul e array dinamic deci pot returna NULL
	}

	TElem deletedElem = heap[0]; //retin radacina(care urmeaza sa fie stearsa
	heap[0] = heap[len-1];       //aceasta primeste heap[lungime-1]
	len = len - 1;               //scad lungimea cu 1 pentru ca am sters un element
	bubble_down(0,n);            //restabilesc heap-ul prin bubble_down pt a indeplini conditiile de a fi heap
	TElem remove = deletedElem;  //retin elementul sters adica radacina

	return remove; //o returnez
}

int MaxHeap::size() const
{
	// returneaza numarul de elemente din array
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: Θ(1)
		 // worst case: Θ(1)
		 // avg case: Θ(1)
		 
	return len;
}

bool MaxHeap::isEmpty() const
{
	// verifica daca array-ul e gol sau nu
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: Θ(1)
		 // worst case: Θ(1)
		 // avg case: Θ(1)
		 
	// daca e gol
	if (len == 0)
		return true; // returneaza true

	return false; //altfel returneaza false
}

MaxHeap::~MaxHeap()
{
	//destructor
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: Θ(1)
		 // worst case: Θ(1)
		 // avg case: Θ(1)
		 
	delete[] heap;
}

long long computeProduct(vector<TElem> vector, int k, int n)
{
	
	// calculeaza si returneaza produsul celor mai mari k elemente din vector
	// daca k<=0 arunca exceptie
	// n este numarul descendentilor 
	
	//////////////////////////
		 // COMPLEXITATE:
		 // best case: O(1)
		 // worst case: O(n*logn(n)) // n*logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
									 // inmultesc cu n din cauza for-urilor
		 // avg case: O(n*logn(n)) // n*logaritm in baza n de n pentru ca am n copii(in cazul cu 2 ar fi fost O(log2(n)), deci generalizand inlocuiesc 2-ul cu n)
									 // inmultesc cu n din cauza for-urilor
			   // complexitatea este aceasta pentru ca inaltimea arborelui este logaritmica *n (de la for)
	
	// daca k<=0 arunca exceptie
	if (k <= 0)
	{
		exception e;
		throw e;
	}

	MaxHeap mh; // imi fac un maxheap
	long long kprodukt = 1; //produsul ce trebuie calculat
	
	//adaug vectorul dat ca parametru intr-un heap
	for (int i = 0; i < vector.size(); i++)
		mh.add(vector[i],n);

	//calculez produsul celor mai mari k elemente din vector (care este acum un heap)
	for (int i = 0; i < k; i++)
	{
		TElem elem = mh.remove(n);
		//mh.bubble_up(0, n);
		kprodukt *= elem;
	}
	
	return kprodukt; //returnez produsul
}

