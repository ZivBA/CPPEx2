//
// Created by rooty on 9/11/16.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "ShapeFactory.h"

static const int LINE_LENGTH = 256;
static const int PRECISION = 2;


/**
 * Driver for the Shapes program. takes input and [optional] output file of shapes.
 * checks validity of shapes and intersection.
 * @param argc number of command line arguments.
 * @param argv array of command line arguments.
 * @return 0 if all good + outputs results. otherwise prints error to standard error stream.
 */
int main(int argc, char *argv[])
{
	//set output precision.
	std::cout.precision(PRECISION);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);

	//validate correct number of CL arguments is given.
	if (argc < 2 || argc > 3)
	{
		std::cerr << "incorrect number of program arguments" << std::endl;
		std::cerr << "usage: Shapes <input_file> [<output_file>]" << std::endl;
		exit(ERROR);
	}
	// if output file is provided in CL arguments, redirect 'cout' to file.
	if (argc == 3)
	{
		static std::ofstream s_outF(argv[2]);

		//check if output file is reachable.
		if (!s_outF.is_open())
		{
			std::cerr << "error opening output file" << std::endl;
			exit(ERROR);
		}

		std::cout.rdbuf(s_outF.rdbuf());
	}
	static std::ifstream s_inF(argv[1]);

	//check if input file is reachable.
	if (!s_inF.is_open())
	{
		std::cerr << "error opening input file" << std::endl;
		exit(ERROR);
	}

	std::cin.rdbuf(s_inF.rdbuf());

	std::vector<Shape *> shapes = std::vector<Shape *>();
	std::string line;

	//for each line, try to create relevant shape.
	while (std::getline(std::cin, line))
	{
		shapes.push_back(ShapeFactory::create(line));
	}

	// assuming all lines hold correctly formatted shapes, validate each shape.
	for (Shape *shape:shapes)
	{
		if (!shape->validate())
		{
			std::cerr << "invalid shape" << std::endl;
			exit(ERROR);
		}
	}

	// flag - if done then area is printed.
	bool notDone = false;

	// check intersection between each two shapes.
	for (unsigned i = 0; i < shapes.size() - 1; i++)
	{
		//no need to re-check previous combinations.
		for (unsigned j = i + 1; j < shapes.size(); j++)
		{
			//if not done and shapes intersect print the shapes and report intersection.
			//flip flag to denote
			if (!notDone && shapes.at(i)->intersect(shapes.at(j)))
			{
				shapes.at(i)->print();
				shapes.at(j)->print();
				reportDrawIntersect();
				notDone = !notDone;

			}
		}
	}

	// if done then print sum of area.
	if (!notDone)
	{
		CordType sumArea = 0.0;
		for (Shape *&shape : shapes)
		{
			sumArea += shape->area();
		}
		printArea(sumArea);
	}

//	shapes.clear();


}