//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_SHAPEFACTORY_H
#define CPPEX2_SHAPEFACTORY_H


#include <bits/basic_string.h>
#include "Shape.h"
#include "Trapeze.h"
#include "Triangle.h"


static const char TRIANGLE = 'T';
static const char TRAPEZE = 't';

class ShapeFactory
{
	std::list<char> validShapes = {TRIANGLE, TRAPEZE}; // add new shapes here.

public:
	static Shape *create(std::string line);
};


#endif //CPPEX2_SHAPEFACTORY_H
