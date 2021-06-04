#include <iostream>
#include "Dictionary.h"

int main()
{
	Dictionary<std::string> myDictionary(5);
	myDictionary.Insert("A", "Altair");
	myDictionary.Insert("B", "Betlegeuse");
	myDictionary.Insert("C", "Celbalrai");
	myDictionary.Insert("D", "Deneb");
	myDictionary.Insert("E", "Edasich");
	myDictionary.Insert("F", "Fomalhaut");
	myDictionary.PrintAll();
	return 0;
}