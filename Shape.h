//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_SHAPE_H
#define CPPEX2_SHAPE_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "Defs.h"
#include "Point.h"
#include "PointSet.h"


static const int ERROR = -1;

class Shape
{

public:
	Shape();

	virtual void init(std::list<CordType> &list);

	virtual ~Shape();

	virtual bool validate()=0;

	virtual int area()=0;

	virtual void print() =0;

	bool intersect(Shape *&pShape);

protected:
	PointSet points;
};


#endif //CPPEX2_SHAPE_H
