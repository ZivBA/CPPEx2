//
// Created by rooty on 9/11/16.
//

#ifndef CPPEX2_TRAPEZE_H
#define CPPEX2_TRAPEZE_H

#include "Shape.h"

class Trapeze : public Shape
{

public:
	Trapeze(std::list<CordType> &list);

	void print();

	bool validate();

};


#endif //CPPEX2_TRAPEZE_H
