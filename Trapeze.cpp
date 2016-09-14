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
	printTrapez(points.getArray()[0]->get_xCord(),
	            points.getArray()[0]->get_yCord(),
	            points.getArray()[1]->get_xCord(),
	            points.getArray()[1]->get_yCord(),
	            points.getArray()[2]->get_xCord(),
	            points.getArray()[2]->get_yCord(),
	            points.getArray()[3]->get_xCord(),
	            points.getArray()[3]->get_yCord()
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
	return !((pointList.at(0)->get_yCord() != pointList.at(1)->get_yCord() ||
	          pointList.at(2)->get_yCord() != pointList.at(3)->get_yCord()) &&
	         pointList.at(0)->get_yCord() == pointList.at(3)->get_yCord());
}

/**
 * area of triangle
 * @return the area of the triangle.
 */
CordType Trapeze::area() const
{
	CordType h = fabs(points.getArray()[0]->get_yCord() - points.getArray()[2]->get_yCord());
	CordType b = fabs(points.getArray()[0]->get_xCord() - points.getArray()[1]->get_xCord());
	CordType t = fabs(points.getArray()[2]->get_xCord() - points.getArray()[3]->get_xCord());

	return (h * ((b + t) / 2.0));
}

