//
// Created by rooty on 9/11/16.
//

//#include <iterator>
#include <sstream>
#include <iostream>
#include "ShapeFactory.h"


/**
 * static factory method for creating shapes. gets a string and returns a shape if possible.
 * @param line the input string according to which a shape must be generated.
 * @return Shape pointer to the concrete shape type.
 */
Shape *ShapeFactory::create(std::string line)
{
	//vector holding the seperate tokens in the string.
	std::list<std::string> tokens;
	//tokenize the string by tabs.
	std::istringstream iss(line);
	std::string token;
	while (std::getline(iss, token, SEP_TOKEN))   // but we can specify a different one
	{
		tokens.push_back(token);
	}

	// take the first token into a char, this is the shape type. remove from vector.
	char type = tokens.front()[0];
	tokens.pop_front();

	//initialize a vector of CordType for the actual data in the tokens.
	std::list<CordType> pointSet = std::list<CordType>();
	//parse the string tokens into doubles and push to the vector (implicit cast to CordType)
	for (std::string pnt : tokens)
	{
		pointSet.push_back(std::stod(pnt));
	}

	// switch case by shape type, return a new Shape pointer to the relevant concrete type.
	// print an error if invalid type is requested.
	switch (type)
	{
		case TRIANGLE:
			return (new Triangle(pointSet));
		case TRAPEZE:
			return (new Trapeze(pointSet));
		default:
			std::cerr << "Invalid shape type." << std::endl;
			exit(ERROR);
	}

}
