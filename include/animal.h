#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

struct AnimalInfo {
	std::string name;
	int age;
};

class Animal {
public:
	Animal() {
		animalInfo = new AnimalInfo();
	};
	~Animal() {
		delete animalInfo;
	};

	void animal() {
		std::cout << "base function." << std::endl;
	};
	virtual void print() {
		std::cout << "base virtual function." << std::endl;
	};
	virtual void run() = 0;

protected:
	AnimalInfo* animalInfo;
};

#endif
