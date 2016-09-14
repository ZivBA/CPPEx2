//
// Created by zivben on 8/28/16.
//

#include <sstream>
#include <algorithm>
#include "PointSet.h"

/**
 * default constructor creating the backing array in default size.
 * @return pointer to the new PointSet.
 */
PointSet::PointSet() : PointSet(_initialCapacity)
{

}

/**
 * constructor accepting size argument, creates a new set with the backing array of size "size".
 * @param size size of array to create.
 * @return pointer to new PointSet.
 */
PointSet::PointSet(int const size)
{
	_pointArray = new Point *[size];
	_currentCapacity = size;
	_initArrayOfPnts(_pointArray, _currentCapacity);
}

/**
 * copy constructor.
 * @param oPntSet the other pointSet to copy from
 * @return a pointer to a new PointSet holding all the points of the other pointset.
 */
PointSet::PointSet(const PointSet &oPntSet) : PointSet(oPntSet.size())
{
	*this = oPntSet;
}

/**
 * default destructor.
 * deletes[] the backing array.
 */
PointSet::~PointSet()
{
	delete[] _pointArray;
}

/**
 * textual representation of the set.
 * @return a string representing all the points in the set by insertion order
 * (as long as no "remove" calls were made on the set or other sorting calls were made).
 */
std::string PointSet::toString()
{
	std::stringstream ss;
	for (int i = 0; i < this->_currentOccupancy; i++)
	{

		ss << _pointArray[i]->toString() << "\n";

	}
	return ss.str();
}

/**
 * adds a point to the set iff no other points of the same coordinates exist.
 * @param pnt reference to the point being inserted.
 * @return sucess ? true : false;
 */
bool PointSet::add(Point const &pnt)
{
	if (_contains(pnt) != _notFound)
	{
		return false;
	}
	if (_currentCapacity - _currentOccupancy == 1)
	{
		_increaseCapacity();
	}
	_pointArray[_currentOccupancy++] = new Point(pnt);
	return true;
}


/**
 * removes a point from the set iff a point of the same coordinates exists in it.
 * @param pnt reference to the removal candidate point.
 * @return sucess ? true : false;
 */

bool PointSet::remove(const Point &pnt)
{
	int res = _contains(pnt);
	if (res == _notFound)
	{
		return false;
	}
	delete _pointArray[res];
	if (res != _currentOccupancy - 1)
	{
		_pointArray[res] = _pointArray[_currentOccupancy - 1];
	}
	_currentOccupancy--;
	if (_currentOccupancy < _currentCapacity / 2)
	{
		_decreaseCapacity();
	}
	return true;


}

/**
 * the number of points in the set.
 * @return number of points in the set.
 */
int PointSet::size() const
{
	return _currentOccupancy;
}

/**
 * checks if a point is currently in the set, returns it's index if found or "notFound" else.
 * @param pPoint point to search for.
 * @return index of the point in the backing array or "notFound" flag (-1);
 */
int PointSet::_contains(const Point &pPoint) const
{
	for (int i = 0; i < _currentOccupancy; i++)
	{
		if (_pointArray[i] == nullptr)
		{
			continue;
		} else if (*_pointArray[i] == &pPoint)
		{
			return i;
		}
	}
	return _notFound;
}

/**
 * private method used for dynamic resizing of the backing array. doubles the capacity of the
 * set and copies the point pointers from the current array to the new one.
 */
void PointSet::_increaseCapacity()
{
	_currentCapacity = _currentCapacity * 2;

	Point **newArray = new Point *[_currentCapacity];
	_initArrayOfPnts(newArray, _currentCapacity);

	std::swap_ranges(_pointArray, _pointArray + _currentOccupancy, newArray);

	delete[] _pointArray;
	_pointArray = newArray;

}

/**
 * private method used for dynamic resizing of the backing array. halves the capacity of the
 * set and copies the point pointers from the current array to the new one.
 */
void PointSet::_decreaseCapacity()
{
	_currentCapacity = _currentCapacity / 2;
	Point **newArray = new Point *[_currentCapacity];
	_initArrayOfPnts(newArray, _currentCapacity);
	std::swap_ranges(_pointArray, _pointArray + _currentOccupancy, newArray);

	delete[] _pointArray;
	_pointArray = newArray;


}

/**
 * asignment operator overload, used to ensure proper copy constructor and asignments.
 * @param oPntSt the RHS pointset being asigned to "this" pointset.
 * @return pointer to "this" pointset after all points were removed and all those from the
 * other pointset were copied in.
 */
PointSet PointSet::operator=(const PointSet &oPntSt)
{
	if (this == &oPntSt)
	{
		return *this;
	}
	for (int i = 0; i < oPntSt.size(); i++)
	{
		delete _pointArray[i];
		*_pointArray[i] = *oPntSt._pointArray[i];
	}

	return *this;
}

/**
 * equality operator overload
 * @param oPntSt the RHS pointset with which "this" pointeset is being compared.
 * @return true iff "this" pointset holds exactly the same points as "that" one.
 */
bool PointSet::operator==(const PointSet &oPntSt) const
{
	if (this->size() != oPntSt.size())
	{
		return false;
	}
	for (int i = 0; i < this->size(); i++)
	{
		if (_pointArray[i] != nullptr && oPntSt._contains(*_pointArray[i]) == _notFound)
		{
			return false;
		}
	}
	return true;
}

/**
 * inequality operator overload
 * @param oPntSt the RHS pointset being compared with
 * @return true iff this pointset is not == other pointset.
 */
bool PointSet::operator!=(const PointSet &oPntSt) const
{
	return !operator==(oPntSt);
}

/**
 * subtraction operator overload.
 * @param oPntSt RHS pointset to be "substracted" from this one.
 * @return a new pointset holding all points in "this" pointset that are not in "other" pointset
 */
PointSet PointSet::operator-(const PointSet &oPntSt) const
{
	PointSet newSet = PointSet(this->size());
	for (int i = 0; i < _currentOccupancy; i++)
	{

		if (_pointArray[i] != nullptr && oPntSt._contains(*_pointArray[i]) == _notFound)
		{
			newSet.add(*_pointArray[i]);
		}
	}
	return newSet;
}

/**
 * intersection of sets
 * @param oPntSt the RHS pointset to intersect with "this"
 * @return a new PointSet holding all the points in "this" set that *are* in the "other" set.
 */
PointSet PointSet::operator&(const PointSet &oPntSt) const
{
	PointSet newSet = PointSet(this->size());
	for (int i = 0; i < _currentOccupancy; i++)
	{

		if (oPntSt._contains(*_pointArray[i]) != _notFound)
		{
			newSet.add(*_pointArray[i]);
		}
	}
	return newSet;
}


/**
 * returns the distance between two points;
 * @param a first point
 * @param b second point
 * @return an integer value of the distance between the points.
 */
CordType PointSet::_sqrDist(const Point *a, const Point *b)
{
	CordType dx = a->getxCord() - b->getxCord(), dy = a->getyCord() - b->getyCord();
	return dx * dx + dy * dy;
}


/**
 * checks if a third point (p3) is a clockwise or counter-clockwise turn from the two
* preceding points (p1, p2). used for the graham-scan algorithm.
* @param p1 input point 1
* @param p2 input point 2
* @param p3 input point 3
* @return an integer: Three points are a counter-clockwise turn if ccw > 0, clockwise if
*	ccw < 0, and collinear if ccw = 0
*/
CordType PointSet::ccw(const Point &p1, const Point &p2, const Point &p3)
{
	return ((p2.getyCord() - p1.getyCord()) * (p3.getxCord() - p1.getxCord()) -
	        (p2.getxCord() - p1.getxCord()) * (p3.getyCord() - p1.getyCord()));


}

/**
 * simple loop to initialize an array with nullptr.
 * @param pPoint the array to initialize
 * @param size the size of the array.
 */
void PointSet::_initArrayOfPnts(Point **pPoint, const int size)
{
	for (int i = 0; i < size; i++)
	{
		pPoint[i] = nullptr;
	}
}


/**
 * returns the backing array of the pointset
 * @return Point pointer (the array)
 */
Point **PointSet::getArray() const
{
	return _pointArray;
}
