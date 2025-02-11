

/**************************************************************************
* *
* * FILE NAME : BmpTools.h
* *
* * DESCRIPTION : BmpTools h file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#ifndef __BMP_TOOLS_H__
#define __BMP_TOOLS_H__


#include "Bmp.h"
#include "BmpDrawTools.h"
#include "HsvTools.h"


//******************************************************************************
// declaration of function
//******************************************************************************

CBmp BmpCopy(CBmp& bmp, const TPoint& initPoint, U32 width, U32 height);
CBmp BmpCut(CBmp& bmp, const TPoint& initPoint,
	U32 width, U32 height, const TRGB& background);
void BmpPaste(CBmp& bottomBmp, const CBmp& topBmp, const TPoint& initPoint);
bool BmpTransparent(CBmp& bottomBmp, const CBmp& topBmp,
	double ratio, const TPoint& initPoint);

void BmpHorFlip(CBmp& bmp);
void BmpVerFlip(CBmp& bmp);

void BmpResize(CBmp& bmp, U32 width, U32 height);

bool BmpRotatePoint(const TPoint& centerPoint, double angle, 
	const TPoint& srcPoint, TPoint& dstPoint);
void BmpRotate(CBmp& bmp, const TPoint& centerPoint, double angle,
	const TPoint& initPoint, U32 width, U32 height, const TRGB& background);

void BmpTransNoColor(CBmp& bmp);
void BmpTransBlackWhite(CBmp& bmp, double adjust);
void BmpReverseColor(CBmp& bmp);
void BmpAdjustBr(CBmp& bmp, double a, double b);

std::vector<TPoint> BmpGetColorRangePoint(CBmp& bmp,
	const THSV& minHsv, const THSV& maxHsv);

std::vector<TPoint> BmpGetReversePoint(CBmp& bmp,
	std::vector<TPoint> points);

U32 BmpCalcAvgColor(const CBmp& bmp);


#endif // __BMP_TOOLS_H__

