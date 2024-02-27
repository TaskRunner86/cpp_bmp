

/**************************************************************************
* *
* * FILE NAME : BmpDrawTools.h
* *
* * DESCRIPTION : BmpDrawTools h file
* *
* * DATE : 2024-2-26
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#ifndef __BMP_DRAW_TOOLS_H__
#define __BMP_DRAW_TOOLS_H__


#include <vector>
#include "Bmp.h"


//******************************************************************************
// definition of type
//******************************************************************************

typedef struct TagPoint {
	U32 x;
	U32 y;
} TPoint;


//******************************************************************************
// declaration of function
//******************************************************************************

void BmpDrawPoint(CBmp& bmp, const TPoint& point, const TRGB& rgb);
void BmpDrawLine(CBmp& bmp, const TPoint& start, const TPoint& end, const TRGB& rgb);
void BmpDrawCircle(CBmp& bmp, const TPoint& centerPoint, U32 radius, const TRGB& rgb);

std::vector<TPoint> BmpGetLinePoint(const TPoint& start, const TPoint& end);
std::vector<TPoint> BmpGetCirclePoint(const TPoint& centerPoint, U32 radius);


#endif // __BMP_DRAW_TOOLS_H__

