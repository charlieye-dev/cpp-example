#ifndef __CAT__H__
#define __CAT_H__

#include <iostream>
#include <string>
#include "animal.h"

class Cat : public Animal {
public:
	Cat(std::string name, int age);
	~Cat() {};

	void animal() {
		std::cout << "child function." << std::endl;
	};
	void print() {
		std::cout << "child virtual function." << std::endl;
	};
	void run();
};

#endif
