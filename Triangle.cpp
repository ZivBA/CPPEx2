//
// Created by rooty on 9/11/16.
//

#include <assert.h>
#include "Triangle.h"

Triangle::Triangle()
{

}

Triangle::~Triangle()
{

}

Triangle::Triangle(std::list<CordType> &list)
{
	init(list);
}

void Triangle::print()
{
	std::cout << "triangle" << std::endl;
}

bool Triangle::validate()
{
	std::vector<Point *> pointList
			(this->points.getArray(), this->points.getArray() + this->points.size());
	assert(pointList.size() == 3);
	return !(pointList.front()->get_xCord() == pointList.at(1)->get_xCord() &&
	         pointList.at(1)->get_xCord() == pointList.back()->get_xCord() ||
	         pointList.front()->get_yCord() == pointList.at(1)->get_yCord() &&
	         pointList.at(1)->get_yCord() == pointList.back()->get_yCord());
}



