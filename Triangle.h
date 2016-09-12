//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_TRIANGLE_H
#define CPPEX2_TRIANGLE_H


#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle();

	Triangle(std::list<CordType> &list);

	~Triangle();

	bool validate();

	void print();
};


#endif //CPPEX2_TRIANGLE_H
