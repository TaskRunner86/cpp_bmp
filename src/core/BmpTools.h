

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


//******************************************************************************
// declaration of function
//******************************************************************************

CBmp BmpCopy(CBmp& bmp, const TPoint& initPoint, U32 width, U32 height);
CBmp BmpCut(CBmp& bmp, const TPoint& initPoint,
	U32 width, U32 height, const TRGB& background);
void BmpPaste(CBmp& bottomBmp, const CBmp& topBmp, const TPoint& initPoint);

void BmpResize(CBmp& bmp, U32 width, U32 height);

bool BmpRotatePoint(const TPoint& centerPoint, double angle, 
	const TPoint& srcPoint, TPoint& dstPoint);
void BmpRotate(CBmp& bmp, const TPoint& centerPoint, double angle,
	const TPoint& initPoint, U32 width, U32 height, const TRGB& background);

void BmpTransNoColor(CBmp& bmp);
void BmpTransBlackWhite(CBmp& bmp);
void BmpReverseColor(CBmp& bmp);
void BmpAdjustBr(CBmp& bmp, U8 adjustVal, bool isAdd);


#endif // __BMP_TOOLS_H__

