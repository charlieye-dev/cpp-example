#ifndef __ANIMAL_FACTORY_H__
#define __ANIMAL_FACTORY_H__

#include <map>
#include <vector>
#include <string>

#include "animal.h"

class AnimalFactory {
public:
	AnimalFactory();
	~AnimalFactory();

	std::vector<std::string> listAll();
	Animal* newAnimal(std::string name);
	void deleteAnimal(std::string name);
	void start(std::string name);
	void stop();

private:
	static std::vector<std::string> animals;
	std::map<std::string, Animal*> animal_list;
};

#endif
