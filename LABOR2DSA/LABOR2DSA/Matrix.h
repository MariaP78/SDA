#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0
class Iterator;


class Matrix {

	friend class Iterator;
private:
	//TODO - Representation
	struct DLLNode
	{
		int zeile; //rand
		int spalte; //coloana
		TElem wert; //valoare
		struct DLLNode* prev; //adresa elementului precedent
		struct DLLNode* next; //adresa elementului urmator

	}*head,*tail; //*head - adresa primului nod, *tail - adresa ultimului nod


	int zeilen; //numarul de randuri din matrice
	int spalten; //numarul de coloane din matrice

	

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	//return an iterator for the set
	Iterator iterator() const;

};
