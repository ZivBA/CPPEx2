//
//
// Created by rooty on 9/11/16.


#include <assert.h>
#include "Trapeze.h"

/**
 * default dtor
 * @return
 */
Trapeze::~Trapeze()
{

}

/**
 * default ctor
 * @return
 */
Trapeze::Trapeze() : Shape("Trapeze")
{

}

/**
 * ctor initializing pointset
 * @param list of CordType vars that define the shape.
 * @return
 */
Trapeze::Trapeze(std::list<CordType> &list) : Trapeze()
{
	init(list);
}

/**
 * uses the printTrapeze method to print the triangle.
 */
void Trapeze::print() const
{
	printTrapez(points.getArray()[0]->getxCord(),
	            points.getArray()[0]->getyCord(),
	            points.getArray()[1]->getxCord(),
	            points.getArray()[1]->getyCord(),
	            points.getArray()[2]->getxCord(),
	            points.getArray()[2]->getyCord(),
	            points.getArray()[3]->getxCord(),
	            points.getArray()[3]->getyCord()
	);

}

/**
 * method validating that the Triangle is not degenearted
 * @return true iff triangle has volume.
 */
bool Trapeze::validate() const
{
	std::vector<Point *> pointList
			(this->points.getArray(), this->points.getArray() + this->points.size());
	assert(pointList.size() == 4);
	return !((pointList.at(0)->getyCord() != pointList.at(1)->getyCord() ||
	          pointList.at(2)->getyCord() != pointList.at(3)->getyCord()) &&
	         pointList.at(0)->getyCord() == pointList.at(3)->getyCord());
}

/**
 * area of triangle
 * @return the area of the triangle.
 */
CordType Trapeze::area() const
{
	CordType h = fabs(points.getArray()[0]->getyCord() - points.getArray()[2]->getyCord());
	CordType b = fabs(points.getArray()[0]->getxCord() - points.getArray()[1]->getxCord());
	CordType t = fabs(points.getArray()[2]->getxCord() - points.getArray()[3]->getxCord());

	return (h * ((b + t) / 2.0));
}

