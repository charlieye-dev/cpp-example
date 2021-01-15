#include <iostream>
#include "animal_factory.h"

#include "cat.h"
#include "dog.h"

std::vector<std::string> AnimalFactory::animals = {
	"cat",
	"dog"
};

AnimalFactory::AnimalFactory() {
	std::cout << "Start..." << std::endl;
}

AnimalFactory::~AnimalFactory() {
	std::cout << "Stop..." << std::endl;
}

std::vector<std::string> AnimalFactory::listAll() {
	return animals;
}

Animal* AnimalFactory::newAnimal(std::string name) {
	Animal* a;

	if (name == "cat") {
		a = new Cat(name, 10);
		animal_list[name] = a;
	}

	if (name == "dog") {
		a = new Dog(name, 20);
		animal_list[name] = a;
	}

	return a;
}

void AnimalFactory::deleteAnimal(std::string name) {
	delete animal_list[name];

	// then clean this key:value from map;
}

void AnimalFactory::start(std::string name) {
	animal_list[name]->run();
	animal_list[name]->animal();
	animal_list[name]->print();
}

void AnimalFactory::stop() {
}
