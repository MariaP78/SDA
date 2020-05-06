#include "Matrix.h"
#include <exception>
#include <iostream>
#include "Iterator.h"

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: O(n^2)
	//worst case: O(n^2)
	//avg case: O(n^2)

	//constructor

	zeilen = nrLines; 
	spalten = nrCols;
	head = new DLLNode();  
	tail = new DLLNode();

	//initializez cu null coordonatele lui head
	head->prev = nullptr; //nullptr pt ca e pointer
	head->next = nullptr;  //nullptr pt ca e pointer
	head->wert = NULL_TELEM; //NULL_TELEM pt ca e de tip TElem

	//initializez cu null coordonatele lui tail
	tail->prev = nullptr;  //nullptr pt ca e pointer
	tail->next = nullptr;  //nullptr pt ca e pointer
	tail->wert = NULL_TELEM; //NULL_TELEM pt ca e de tip TElem

	//coordonatele primului si ultimului nod
	head->zeile = 0;
	head->spalte = 0;
	tail->zeile = zeilen-1;
	tail->spalte = spalten - 1;
	
	DLLNode* currentnode = head; //fac un currentnode 

	//initializez toata matricea cu null
	for(int k=0;k<zeilen;k++)
		for (int m = 0; m < spalten; m++)
		{
			//nod nou
			DLLNode* node = new DLLNode();
			if (k == 0 & m == 0)
			{
				//elementul corespunde cu head(primul din matrice)
			}
			else
			{
				node->wert = NULL_TELEM;
				node->zeile = k;
				node->spalte = m;
				node->next = nullptr;

				//fac legatura dintre ele
				currentnode->next = node;
				node->prev = currentnode;
				currentnode = currentnode->next; //trec la urmatorul
			}
		}
}


int Matrix::nrLines() const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//returneaza numarul de linii
    

	return zeilen; //returnez nr de linii

}


int Matrix::nrColumns() const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	//returneaza numarul de coloane

	
	return spalten;  //returnez nr de coloane
}


TElem Matrix::element(int i, int j) const {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	//returneaza elementul de pe linia i, coloana j
	//arunca exceptie daca (i,j) nu e pozitie valida in matrice

	//valid position
    
	if (i >=0 && j>=0 && i < zeilen && j < spalten)   //pozitia mea e valida atunci cand linia si coloana sunt >=0 si i<nr de randuri
		                                              //si j<nr de coloane
	{  
		DLLNode* aux = head;  //fac un nod nou auxiliar in care o sa am head-ul
		for (int k = 0; k < i * spalten + j - 1; k++)   //for -> O(n)
		{   //am descoperit aceasta formula(formula am gasit-o prin calcul matematic(i*spalten+j-1) pentru a parcurge exact atatea elemente pentru a ajunge 
			//la elementul pe care doresc sa il returnez, elementul de pe linia i si coloana j
			aux = aux->next; //inainteaza la urmatorul nod
		}
		return aux->wert; //returneaza valoarea acestuia
	}
	else
	{
		//arunc exceptie daca pozitia nu este valida
		exception e;
		throw e;
	}

}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: O(n)
	//avg case: O(n)

	//modifica valoarea de pe linia i, coloana j
	//returneaza valoarea precedenta de pe pozitie
	//arunca exceptie daca (i,j) nu e pozitie valida in matrice

	if (i >= 0 && j >= 0 && i < zeilen && j < spalten) //pozitia mea e valida atunci cand linia si coloana sunt >=0 si i<nr de randuri
		                                               //si j<nr de coloane
	{
		DLLNode* aux = head; //fac un nod nou auxiliar in care o sa am head-ul
		TElem temp;    //iau o variabila temp(temporara in care pot retine valoarea precedenta de pe pozitie - ceea ce mi se cere sa returnez)
		for (int k = 0; k < i * spalten + j - 1; k++) //parcurg  matricea pana la elementul caruia vreau sa ii modific valoarea
			                                          //cu formula pe care am gasit-o prin calcul matematic(i*spalten+j-1)
		{
			//cout << k << " ";  //aici am vrut sa vad cand se termina mix din ExtendedTests
			aux = aux->next;     //trece la urmatorul nod
		}
		temp = aux->wert; //retine valoarea precedenta in temp
		aux->wert = e;   //iar valoarea din aux devine e care se afla in parametrii 

		return temp;   //returnez temp

	}
	else
	{
		//arunc exceptie daca pozitia nu este valida
		exception e;
		throw e;
	}

}

Iterator Matrix::iterator() const {

	//COMPLEXITATE:
	//best case: Θ(1)
	//worst case: Θ(1)
	//avg case: Θ(1)

	return Iterator(*this);
}


