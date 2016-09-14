//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_TRAPEZE_H
#define CPPEX2_TRAPEZE_H
#include "Shape.h"

/**
 * class representing a Trapeze, inherits from Shape.
 */
class Trapeze : public Shape
{

public:
	/**
	 * default ctor
	 * @return
	 */
	Trapeze();

	/**
	* ctor initializing pointset
	* @param list of CordType vars that define the shape.
	* @return
	*/
	Trapeze(std::list<CordType> &list);

	/**
 	* default dtor
 	* @return
 	*/
	~Trapeze();

	/**
	 * uses the printTrapeze method to print the triangle.
	 */
	void print() const;

	/**
	 * method validating that the Triangle is not degenearted
	 * @return true iff triangle has volume.
	 */
	bool validate() const;

	/**
	 * area of triangle
	 * @return the area of the triangle.
	 */
	CordType area() const;

};


#endif //CPPEX2_TRAPEZE_H
