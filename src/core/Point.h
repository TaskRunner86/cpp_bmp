

/**************************************************************************
* *
* * FILE NAME : Point.h
* *
* * DESCRIPTION : Point h file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#ifndef __POINT_H__
#define __POINT_H__


#include "Common.h"


//******************************************************************************
// definition of type
//******************************************************************************

//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
typedef struct TagPoint {
	bool operator < (const TagPoint& point) const{
		if (this->x != point.x) {
			return this->x < point.x;
		}
		return this->y < point.y;
	}

	bool operator == (const TagPoint& point) const{
		if (this->x == point.x && this->y == point.y) {
			return true;
		}
		return false;
	}	

	U32 x;
	U32 y;
} TPoint;


//******************************************************************************
// declaration of function
//******************************************************************************

double PointCalcDist(const TPoint& pointA, const TPoint& pointB);


#endif // __POINT_H__

