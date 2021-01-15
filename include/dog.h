#ifndef __DOG__H__
#define __DOG_H__

#include "animal.h"

class Dog : public Animal {
public:
	Dog(std::string name, int age);
	~Dog();

	virtual void run();
};

#endif
