//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_SHAPE_H
#define CPPEX2_SHAPE_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "Point.h"
#include "PointSet.h"
#include "PrintOuts.h"

//anti magic-number const error code.
static const int ERROR = -1;

/**
 * abstract Shape class, each concrete shape inherits from this.
 */
class Shape
{

private:
	/**
	 * default constructor.
	 * @return NA.
	 */
	Shape();

public:
	// the requested useless const string shape name....
	const std::string _name;

	/**
	 * ctor accepting a name for the shape. sets the name.
	 * @param name the name of the shape to create.
	 * @return NA.
	 */
	Shape(std::string name);

	/**
	 * initialize a shape from a list of coordinates (create a PointSet backing obj).
	 * @param list the list of coordinates to use for populating the PointSet.
	 */
	virtual void init(std::list<CordType> &list);

	/**
	 * default dtor
	 */
	virtual ~Shape();

	/**
	 * method to check if "this" shape intersects with "other" shape.
	 * @param pShape the "other" shape to check intersection with.
	 * @return true iff shapes intersect (or one shape is subset of other.)
	 */
	bool intersect(const Shape *pShape) const;

	/**
	 * method to validate the specific shape.
	 * pure virtual method to ensure inheriting classes implement it.
	 *
	 * @return true iff shape is valid according to the shape specific definition.
	 */
	virtual bool validate() const =0;

	/**
	 * method to return the area of a shape.
	 * pure virutal to ensure inheriting classes implement it.
	 * @return are of shape.
	 */
	virtual CordType area() const =0;

	/**
	 * method to print the shape.
	 * pure virtual to ensure inheriting classes implement the relevant print method.
	 */
	virtual void print() const =0;

protected:
	// the backing pointset holding the points of the shape.
	PointSet points;
};


#endif //CPPEX2_SHAPE_H
