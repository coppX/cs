#include "Singleton.h"
#include "Singleton.cpp"
#include <iostream>

using namespace std;
int main()
{
	Singleton* ps = Singleton::Instance();
	Singleton::Destroy();
	return 0;
}
