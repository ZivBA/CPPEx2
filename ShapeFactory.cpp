//
// Created by rooty on 9/11/16.
//

//#include <iterator>
#include <sstream>
#include <iostream>
#include "ShapeFactory.h"

Shape *ShapeFactory::create(std::string line)
{
	std::list<std::string> tokens;

	std::istringstream iss(line);
	std::string token;
	while (std::getline(iss, token, '\t'))   // but we can specify a different one
	{
		tokens.push_back(token);
	}

	char type = tokens.front()[0];
	tokens.pop_front();

	std::list<CordType> pointSet = std::list<CordType>();
	for (std::string pnt : tokens)
	{
		pointSet.push_back(std::stod(pnt));
	}
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
