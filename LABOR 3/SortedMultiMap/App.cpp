#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"



/*33. ADT SortedMultiMap – repräsentiert mithilfe einer DLLA von Paaren der Form(key, value) und 
sortiert mithilfe einer Relation auf den Schlüsseln(key).
Ein Schlüssel kann mehrmals vorkommen.
*/


int main()
{
    testAll();
	std::cout << "Short tests done" << std::endl;

	testAllExtended();

    std::cout<<"Finished SMM Tests!"<<std::endl;
	//system("pause");
}
