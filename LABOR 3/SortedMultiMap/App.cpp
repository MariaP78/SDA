#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"



/*33. ADT SortedMultiMap � repr�sentiert mithilfe einer DLLA von Paaren der Form(key, value) und 
sortiert mithilfe einer Relation auf den Schl�sseln(key).
Ein Schl�ssel kann mehrmals vorkommen.
*/


int main()
{
    testAll();
	std::cout << "Short tests done" << std::endl;

	testAllExtended();

    std::cout<<"Finished SMM Tests!"<<std::endl;
	//system("pause");
}
