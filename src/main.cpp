#include <iostream>
#include <vector>
#include <string>

#include "animal_factory.h"

int main(int argc, char *argv[]) {
	std::vector<std::string> a_list;
	AnimalFactory *af;
	std::vector<Animal*> al;
	Animal *a;

	af = new AnimalFactory();

	a_list = af->listAll();
//	for (auto iter = a_list.begin(); iter != a_list.end(); iter++) {
	std::cout << "List all animals..." << std::endl;
	for (auto &iter : a_list) {
		std::cout << "[" << iter << "]" << std::endl;
	}

	std::cout << "Start animals..." << std::endl;
	for (auto &iter : a_list) {
		a = af->newAnimal(iter);
		af->start(iter);
	}

	/*
	std::cout << "Stop animals..." << std::endl;
	for (auto &iter : a_list) {
		af->stop();
		af->deleteAnimal(iter);
	}
	*/

	delete af;
}
