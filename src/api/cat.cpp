#include <iostream>
#include "cat.h"

Cat::Cat(std::string name, int age) {
	animalInfo->name = name;
	animalInfo->age = age;
}

void Cat::run() {
	std::cout << "I'm " << animalInfo->name;
	std::cout << " age is " << animalInfo->age << std::endl;
}
