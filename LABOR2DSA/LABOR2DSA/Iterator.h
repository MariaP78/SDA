#pragma once
#include "Matrix.h"

class Iterator
{
	//DO NOT CHANGE THIS PART
	friend class Matrix;
private:
	//DO NOT CHANGE THIS PART
	const Matrix& matrix;
	Iterator(const Matrix& m);

	//TODO - Representation
	int i;
	int j;

public:
    void first();
	void next();
	void previous();
	TElem getCurrent();
	bool valid();
};

