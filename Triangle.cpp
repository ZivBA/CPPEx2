//
// Created by rooty on 9/11/16.
//

#include "Triangle.h"


/**
 * default dtor.
 */

Triangle::~Triangle()
{

}

/**
 * default ctor
 * @return
 */
Triangle::Triangle() : Shape("Triangle")
{
}

/**
 * ctor initializing pointset
 * @param list of CordType vars that define the shape.
 * @return
 */
Triangle::Triangle(std::list<CordType> &list) : Triangle()
{
	init(list);
}

/**
 * uses the printTrig method to print the triangle.
 */
void Triangle::print() const
{
	printTrig(points.getArray()[0]->get_xCord(),
	          points.getArray()[0]->get_yCord(),
	          points.getArray()[1]->get_xCord(),
	          points.getArray()[1]->get_yCord(),
	          points.getArray()[2]->get_xCord(),
	          points.getArray()[2]->get_yCord()
	);
}

/**
 * method validating that the Triangle is not degenearted
 * @return true iff triangle has volume.
 */

bool Triangle::validate() const
{
	return this->area() > 0.0;
}

/**
 * area of triangle
 * @return the area of the triangle.
 */
CordType Triangle::area() const
{
	return fabs(
			PointSet::ccw(*points.getArray()[0], *points.getArray()[1], *points.getArray()[2]) / 2.0
	);
}



