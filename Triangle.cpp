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
	printTrig(points.getArray()[0]->getxCord(),
	          points.getArray()[0]->getyCord(),
	          points.getArray()[1]->getxCord(),
	          points.getArray()[1]->getyCord(),
	          points.getArray()[2]->getxCord(),
	          points.getArray()[2]->getyCord()
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



