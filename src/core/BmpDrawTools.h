

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
#include "Point.h"


//******************************************************************************
// declaration of function
//******************************************************************************

void BmpDrawPoint(CBmp& bmp, const TPoint& point, const TRGB& rgb);
void BmpDrawPoints(CBmp& bmp, std::vector<TPoint> pointVec, const TRGB& rgb);
void BmpDrawLine(CBmp& bmp, const TPoint& start, const TPoint& end, const TRGB& rgb);
void BmpDrawPolygon(CBmp& bmp, std::vector<TPoint> pointVec, const TRGB& rgb);
void BmpDrawRect(CBmp& bmp, const TPoint& initPoint, U32 width, U32 height, const TRGB& rgb);
void BmpDrawCircle(CBmp& bmp, const TPoint& centerPoint, U32 radius, const TRGB& rgb);
void BmpDrawArea(CBmp& bmp, std::vector<TPoint> border,
	const TPoint& inAreaPoint, const TRGB& rgb);

std::vector<TPoint> BmpGetLinePoint(const TPoint& start, const TPoint& end);
std::vector<TPoint> BmpGetPolygonPoint(std::vector<TPoint> pointVec);
std::vector<TPoint> BmpGetRectPoint(const TPoint& initPoint,
	U32 width, U32 height, const TRGB& rgb);
std::vector<TPoint> BmpGetCirclePoint(const TPoint& centerPoint, U32 radius);
std::vector<TPoint> BmpGetAreaPoint(std::vector<TPoint> border,
	const TPoint& inAreaPoint, U32 width, U32 height);


#endif // __BMP_DRAW_TOOLS_H__

