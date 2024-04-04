

/**************************************************************************
* *
* * FILE NAME : Point.cpp
* *
* * DESCRIPTION : Point cpp file
* *
* * DATE : 2024-4-1
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "Point.h"


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
double PointCalcDist(const TPoint& pointA, const TPoint& pointB) {
	double ret = 0;
	ret = sqrt(((double)pointA.x - pointB.x) * ((double)pointA.x - pointB.x) +
		((double)pointA.y - pointB.y) * ((double)pointA.y - pointB.y));
	return ret;
}

