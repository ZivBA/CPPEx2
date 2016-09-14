//
// Created by zivben on 8/28/16.
//

#ifndef EX1_POINTSET_H
#define EX1_POINTSET_H


#include <string>
#include "Point.h"

/**
 * this class represents a mathematical "set" of points.
 * it also includes all the necessary methods to sort the set by angle from a reference point,
 * sorting by x then y, and calculating the convex hull of the set (the edge).
 */
class PointSet
{
private:

	const int notFound = -1;                    //not found flag for set search.
	const int static _initialCapacity = 8;      //the initial capacity of a set
	int _currentCapacity = 0;                   //the current *available* capacity of a set
	int _currentOccupancy = 0;                  //the number of points currently *in* the set
	Point **_pointArray;                        //the backing array holding pointers to the points
	//in the set.

	/**
	 * private method used for dynamic resizing of the backing array. doubles the capacity of the
	 * set and copies the point pointers from the current array to the new one.
	 */
	void increaseCapacity();

	/**
	 * private method used for dynamic resizing of the backing array. halves the capacity of the
	 * set and copies the point pointers from the current array to the new one.
	 */
	void decreaseCapacity();

	/**
	 * checks if a point is currently in the set, returns it's index if found or "notFound" else.
	 * @param pPoint point to search for.
	 * @return index of the point in the backing array or "notFound" flag (-1);
	 */
	int contains(const Point &pPoint) const;

	/**
	 * returns the distance between two points;
	 * @param a first point
	 * @param b second point
	 * @return an integer value of the distance between the points.
	 */
	static CordType sqrDist(const Point *a, const Point *b);

	/**
	 * simple loop to initialize an array with nullptr.
	 * @param pPoint the array to initialize
	 * @param size the size of the array.
	 */
	void initArrayOfPnts(Point **pPoint, const int size);


public:
	/**
	 * default constructor creating the backing array in default size.
	 * @return pointer to the new PointSet.
	 */
	PointSet();

	/**
	 * constructor accepting size argument, creates a new set with the backing array of size "size".
	 * @param size size of array to create.
	 * @return pointer to new PointSet.
	 */
	PointSet(int size);

	/**
	 * copy constructor.
	 * @param oPntSet the other pointSet to copy from
	 * @return a pointer to a new PointSet holding all the points of the other pointset.
	 */
	PointSet(const PointSet &oPntSet);

	/**
	 * default destructor.
	 * deletes[] the backing array.
	 */
	~PointSet();

	/**
	 * textual representation of the set.
	 * @return a string representing all the points in the set by insertion order
	 * (as long as no "remove" calls were made on the set or other sorting calls were made).
	 */
	std::string toString();

	/**
	 * adds a point to the set iff no other points of the same coordinates exist.
	 * @param pnt reference to the point being inserted.
	 * @return sucess ? true : false;
	 */
	bool add(Point const &pnt);

	/**
	 * removes a point from the set iff a point of the same coordinates exists in it.
	 * @param pnt reference to the removal candidate point.
	 * @return sucess ? true : false;
	 */
	bool remove(const Point &pnt);

	/**
	 * the number of points in the set.
	 * @return number of points in the set.
	 */
	int size() const;

	/**
	 * equality operator overload
	 * @param oPntSt the RHS pointset with which "this" pointeset is being compared.
	 * @return true iff "this" pointset holds exactly the same points as "that" one.
	 */
	bool operator==(const PointSet &oPntSt) const;

	/**
	 * asignment operator overload, used to ensure proper copy constructor and asignments.
	 * @param oPntSt the RHS pointset being asigned to "this" pointset.
	 * @return pointer to "this" pointset after all points were removed and all those from the
	 * other pointset were copied in.
	 */
	PointSet operator=(const PointSet &oPntSt);

	/**
	 * inequality operator overload
	 * @param oPntSt the RHS pointset being compared with
	 * @return true iff this pointset is not == other pointset.
	 */
	bool operator!=(const PointSet &oPntSt) const;

	/**
	 * subtraction operator overload.
	 * @param oPntSt RHS pointset to be "substracted" from this one.
	 * @return a new pointset holding all points in "this" pointset that are not in "other" pointset
	 */
	PointSet operator-(const PointSet &oPntSt) const;

	/**
	 * intersection of sets
	 * @param oPntSt the RHS pointset to intersect with "this"
	 * @return a new PointSet holding all the points in "this" set that *are* in the "other" set.
	 */
	PointSet operator&(const PointSet &oPntSt) const;

	Point **getArray() const;

/**
 * checks if a third point (p3) is a clockwise or counter-clockwise turn from the two
 * preceding points (p1, p2). used for the graham-scan algorithm.
 * @param p1 input point 1
 * @param p2 input point 2
 * @param p3 input point 3
 * @return an integer: Three points are a counter-clockwise turn if ccw > 0, clockwise if
  *	ccw < 0, and collinear if ccw = 0
 */
	static CordType ccw(const Point &p1, const Point &p2, const Point &p3);
};

#endif //EX1_POINTSET_H
