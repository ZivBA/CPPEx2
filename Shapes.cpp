//
// Created by rooty on 9/11/16.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Shape.h"
#include "ShapeFactory.h"

static const int LINE_LENGTH = 256;
static const int PRECISION = 2;


int main(int argc, char *argv[])
{
	std::setprecision(PRECISION);
	if (argc < 2 || argc > 3)
	{
		std::cout << "incorrect number of program arguments" << std::endl;
		std::cout << "usage: Shapes <input_file> [<output_file>]" << std::endl;
		exit(ERROR);
	}
	if (argc == 3)
	{
		static std::ofstream s_outF(argv[2]);
		std::cout.rdbuf(s_outF.rdbuf());
	}
	static std::ifstream s_inF(argv[1]);
	std::cin.rdbuf(s_inF.rdbuf());

	std::vector<Shape *> shapes = std::vector<Shape *>();
	std::string line;
	while (std::getline(std::cin, line))
	{
		shapes.push_back(ShapeFactory::create(line));
	}

	for (Shape *&shape:shapes)
	{
		if (!shape->validate())
		{
			std::cerr << "invalid shape" << std::endl;
			exit(ERROR);
		}
	}

	for (int i = 0; i < shapes.size() - 1; i++)
	{
		for (int j = i + 1; j < shapes.size(); j++)
		{
			shapes.at(i)->intersect(shapes.at(j));
		}
	}

	std::cout << argv[2] << argv[3] << std::endl;

	shapes.clear();


}