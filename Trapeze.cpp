//
// Created by rooty on 9/11/16.
//

#include <assert.h>
#include "Trapeze.h"

Trapeze::Trapeze(std::list<CordType> &list)
{
	init(list);
}

void Trapeze::print()
{
	std::cout << "Trapeze" << std::endl;

}

bool Trapeze::validate()
{
	std::vector<Point *> pointList
			(this->points.getArray(), this->points.getArray() + this->points.size());
	assert(pointList.size() == 4);
	return !((pointList.at(0)->get_yCord() != pointList.at(1)->get_yCord() ||
	          pointList.at(2)->get_yCord() != pointList.at(3)->get_yCord()) &&
	         pointList.at(0)->get_yCord() == pointList.at(3)->get_yCord());
}

