#include "Builder.h"
#include "Director.cpp"
#include <iostream>
using namespace std;

int main()
{
	Director *pDirector1 = new Director(new ConcreteBuilder1());
	pDirector1->Construct();
	delete pDirector1;
	pDirector1 = NULL;

	Director *pDirector2 = new Director(new ConcreteBuilder2());
	pDirector2->Construct();
	delete pDirector2;
	pDirector2 = NULL;
	
	return 0;
}
