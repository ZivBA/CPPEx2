//
// Created by rooty on 9/11/16.
//

#include "Shape.h"

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

Shape::Shape()
{

}

Shape::~Shape()
{

}

bool Shape::intersect(Shape *&pShape)
{
	std::vector<Point *> pointList
			(this->points.getArray(), this->points.getArray() + this->points.size());
	std::vector<Point *> otherPointList
			(pShape->points.getArray(), pShape->points.getArray() + pShape->points.size());

	std::vector<std::pair<Shape, Shape>> intersections;
	if (this.area() < otherPointList.size())
	{
		std::swap(pointList, otherPointList);
	}

	for (unsigned i = 0; i < pointList.size() - 1; i++)
	{
		for (unsigned j = i; j < otherPointList.size() - 1; j++)
		{
			CordType res =
					PointSet::ccw(*pointList.at(i), *pointList.at(i + 1), *otherPointList.at(j)) *
					PointSet::ccw(*pointList.at(i), *pointList.at(i + 1),
					              *otherPointList.at(j + 1));

			if (res < 0)
			{
				return true;
			}

		}
	}

}
