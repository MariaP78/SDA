#include "ShortTests.h"
#include <assert.h>
#include "Problema14.h"

//aici mi-am facut eu cateva teste pentru a ma asigura ca merg corect toate functiile :D
// 
void testAll() 
{
	MaxHeap mh; //creez un heap
		
	assert(mh.isEmpty() == true);
	assert(mh.size() == 0);
	assert(mh.add(20, 2) == true);
	assert(mh.add(15, 2) == true);
	assert(mh.add(8, 2) == true);
	assert(mh.add(10, 2) == true);
	assert(mh.add(5, 2) == true);
	assert(mh.add(17, 2) == true);
	assert(mh.size() == 6);
	assert(mh.remove(2) == 20);
	assert(mh.size() == 5);
	assert(mh.remove(2) == 17);
	assert(mh.size() == 4);
	assert(computeProduct({ 20,15,8,10,5,17 }, 1, 2) == 20);
	assert(computeProduct({ 20,15,8,10,5,17 }, 2, 2) == 340);
	assert(computeProduct({ 20,15,8,10,5,17 }, 3, 2) == 5100);
	assert(computeProduct({ 20,15,8,10,5,17 }, 4, 2) == 51000);
	assert(computeProduct({ 20,15,8,10,5,17 }, 5, 2) == 408000);
	assert(computeProduct({ 20,15,8,10,5,17 }, 6, 2) == 2040000);
}

