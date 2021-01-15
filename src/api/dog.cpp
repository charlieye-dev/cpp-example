#include <iostream>
#include "dog.h"

Dog::Dog(std::string name, int age) {
	animalInfo->name = name;
	animalInfo->age = age;
}

void Dog::run() {
	std::cout << "I'm " << animalInfo->name;
	std::cout << " age is " << animalInfo->age << std::endl;
}
