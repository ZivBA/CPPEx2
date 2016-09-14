//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_SHAPEFACTORY_H
#define CPPEX2_SHAPEFACTORY_H


#include <bits/basic_string.h>
#include "Shape.h"
#include "Trapeze.h"
#include "Triangle.h"

//the seperator for tokenizing
#define SEP_TOKEN '\t'


//officially supported shapes. adding more requires adding more cases in the factory method.
static const char TRIANGLE = 'T';
static const char TRAPEZE = 't';

/**
 * factory class for generating shapes.
 */
class ShapeFactory
{
public:
	/**
	 * static factory method for creating shapes. gets a string and returns a shape if possible.
	 * @param line the input string according to which a shape must be generated.
	 * @return Shape pointer to the concrete shape type.
	 */
	static Shape *create(const std::string line);
};


#endif //CPPEX2_SHAPEFACTORY_H
