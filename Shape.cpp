//
// Created by rooty on 9/11/16.
//

#include "Shape.h"

/**
 * default constructor.
 * @return NA.
 */
Shape::Shape()
{

}

/**
 * ctor accepting a name for the shape. sets the name.
 * @param name the name of the shape to create.
 * @return NA.
 */
Shape::Shape(const std::string name) : _name(name)
{

}

/**
 * initialize a shape from a list of coordinates (create a PointSet backing obj).
 * @param list the list of coordinates to use for populating the PointSet.
 */
void Shape::init(std::list<CordType> &newPoints)
{

	while (!newPoints.empty())
	{
		CordType p1 = newPoints.front();
		newPoints.pop_front();
		CordType p2 = newPoints.front();
		newPoints.pop_front();

		bool res = this->points.add(Point(p1, p2));
		if (!res)
		{
			std::cerr << "Shape cannot have two points with the same coords" << std::endl;
			exit(ERROR);
		}
	}
}

/**
 * default dtor
 */
Shape::~Shape()
{

}

/**
 * method to check if "this" shape intersects with "other" shape.
 * @param pShape the "other" shape to check intersection with.
 * @return true iff shapes intersect (or one shape is subset of other.)
 */
bool Shape::intersect(const Shape *pShape) const
{
	std::vector<Point *> pntList
			(this->points.getArray(), this->points.getArray() + this->points.size());
	pntList.push_back(pntList.front()); // re-add first point to close circle of edges.

	std::vector<Point *> oPntList
			(pShape->points.getArray(), pShape->points.getArray() + pShape->points.size());
	oPntList.push_back(oPntList.front()); // re-add first point to close circle of edges.

	if (this->area() < pShape->area())
	{
		std::swap(pntList, oPntList);
	}
	bool contained = false;

	for (unsigned i = 0; i < pntList.size() - 1; i++)
	{
		for (unsigned j = 1; j < oPntList.size() - 1; j++)
		{
			CordType res =
					PointSet::ccw(*pntList.at(i), *pntList.at(i + 1), *oPntList.at(j)) *
					PointSet::ccw(*pntList.at(i), *pntList.at(i + 1), *oPntList.at(j + 1)
					);

			if (res < 0)
			{
				CordType res2 =
						PointSet::ccw(*oPntList.at(j), *oPntList.at(j + 1), *pntList.at(i)) *
						PointSet::ccw(*oPntList.at(j), *oPntList.at(j + 1), *pntList.at(i + 1)
						);

				if (res2 > 0)
				{
					contained = false;
				} else
				{
					return true;
				}
			}

		}
	}
	return contained;
}
