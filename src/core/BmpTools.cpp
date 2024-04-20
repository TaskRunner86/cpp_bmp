

/**************************************************************************
* *
* * FILE NAME : BmpTools.cpp
* *
* * DESCRIPTION : BmpTools cpp file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpTools.h"


//******************************************************************************
// declaration of function
//******************************************************************************

static std::vector<TPoint> BmpGetRatotePoints(const TPoint& centerPoint,
	double angle, const TPoint& initPoint, U32 width, U32 height);
static U32 BmpCalcDistMax(const TPoint& centerPoint, 
	const TPoint& initPoint, U32 width, U32 height);
static U32 BmpCalcAvgColor(const CBmp& bmp);
static U8 BmpAdjustBrCalcVal(U8 val, double a, double b);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
CBmp BmpCopy(CBmp& bmp, const TPoint& initPoint, U32 width, U32 height) {
	CBmp newBmp;
	newBmp.Init(width, height);

	for (U32 i = 0; i < width; ++i) {
		for (U32 j = 0; j < height; ++j) {
			if (bmp.GetWidth() <= (initPoint.x + i) ||
				bmp.GetHeight() <= (initPoint.y + j)) {
				continue;
			}

			TRGB* pRGB = bmp.GetRGB(initPoint.x + i, initPoint.y + j);
			TRGB* pNewRGB = newBmp.GetRGB(i, j);

			pNewRGB->red = pRGB->red;
			pNewRGB->green = pRGB->green;
			pNewRGB->blue = pRGB->blue;
		}
	}

	return newBmp;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
CBmp BmpCut(CBmp& bmp, const TPoint& initPoint, U32 width,
	U32 height, const TRGB& background) {
	CBmp newBmp;
	newBmp.Init(width, height);

	for (U32 i = 0; i < width; ++i) {
		for (U32 j = 0; j < height; ++j) {
			if (bmp.GetWidth() <= (initPoint.x + i) ||
				bmp.GetHeight() <= (initPoint.y + j)) {
				continue;
			}

			TRGB* pRGB = bmp.GetRGB(initPoint.x + i, initPoint.y + j);
			TRGB* pNewRGB = newBmp.GetRGB(i, j);

			pNewRGB->red = pRGB->red;
			pNewRGB->green = pRGB->green;
			pNewRGB->blue = pRGB->blue;

			pRGB->red = background.red;
			pRGB->green = background.green;
			pRGB->blue = background.blue;
		}
	}

	return newBmp;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpPaste(CBmp& bottomBmp, const CBmp& topBmp, const TPoint& initPoint) {
	for (U32 i = 0; i < topBmp.GetWidth(); ++i) {
		for (U32 j = 0; j < topBmp.GetHeight(); ++j) {
			if (bottomBmp.GetWidth() <= (initPoint.x + i) ||
				bottomBmp.GetHeight() <= (initPoint.y + j)) {
				continue;
			}

			TRGB* pBottomRGB = bottomBmp.GetRGB(initPoint.x + i, initPoint.y + j);
			TRGB* pTopRGB = topBmp.GetRGB(i, j);

			pBottomRGB->red = pTopRGB->red;
			pBottomRGB->green = pTopRGB->green;
			pBottomRGB->blue = pTopRGB->blue;
		}
	}
}


//------------------------------------------------------------------------------
// 水平翻转
//------------------------------------------------------------------------------
void BmpHorFlip(CBmp& bmp) {
	CBmp rawBmp = bmp;
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRawRGB = rawBmp.GetRGB(bmp.GetWidth() - i - 1, j);
			TRGB* pRGB = bmp.GetRGB(i, j);

			pRGB->red = pRawRGB->red;
			pRGB->green = pRawRGB->green;
			pRGB->blue = pRawRGB->blue;
		}
	}
}


//------------------------------------------------------------------------------
// 垂直翻转
//------------------------------------------------------------------------------
void BmpVerFlip(CBmp& bmp) {
	CBmp rawBmp = bmp;
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRawRGB = rawBmp.GetRGB(i, bmp.GetHeight() - j - 1);
			TRGB* pRGB = bmp.GetRGB(i, j);

			pRGB->red = pRawRGB->red;
			pRGB->green = pRawRGB->green;
			pRGB->blue = pRawRGB->blue;
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpResize(CBmp& bmp, U32 width, U32 height) {
	CBmp newBmp;
	newBmp.Init(width, height);

	for (U32 i = 0; i < newBmp.GetWidth(); ++i) {
		U32 widthPos = round((double)i * (bmp.GetWidth() - 1) /
			(newBmp.GetWidth() - 1));
		for (U32 j = 0; j < newBmp.GetHeight(); ++j) {
			U32 heightPos = round((double)j * (bmp.GetHeight() - 1) /
				(newBmp.GetHeight() - 1));
			TRGB* pRGB = bmp.GetRGB(widthPos, heightPos);
			TRGB* pNewRGB = newBmp.GetRGB(i, j);
			pNewRGB->red = pRGB->red;
			pNewRGB->green = pRGB->green;
			pNewRGB->blue = pRGB->blue;
		}
	}
	bmp = newBmp;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool BmpRotatePoint(const TPoint& centerPoint,
	double angle, const TPoint& srcPoint, TPoint& dstPoint) {

	double relPointX = (double)srcPoint.x - centerPoint.x;
	double relPointY = (double)srcPoint.y - centerPoint.y;

	double rotateRelPointX = relPointX * cos(angle) + relPointY * sin(angle);
	double rotateRelPointY = relPointX * (-sin(angle)) + relPointY * cos(angle);

	if (round(rotateRelPointX + centerPoint.x) < 0 ||
		round(rotateRelPointY + centerPoint.y) < 0) {
		return false;
	}

	dstPoint.x = round(rotateRelPointX + centerPoint.x);
	dstPoint.y = round(rotateRelPointY + centerPoint.y);
	return true;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpRotate(CBmp& bmp, const TPoint& centerPoint, double angle,
	const TPoint& initPoint, U32 width, U32 height, const TRGB& background) {
	CBmp rawBmp = bmp;
	BmpCut(bmp, initPoint, width, height, background);

	std::vector<TPoint> areaPointVec = BmpGetRatotePoints(
		centerPoint, angle, initPoint, width, height);

	TPoint srcPoint;
	TPoint dstPoint;
	for (U32 i = 0; i < areaPointVec.size(); ++i) {
		srcPoint.x = areaPointVec[i].x;
		srcPoint.y = areaPointVec[i].y;
		if (!BmpRotatePoint(centerPoint, -angle, srcPoint, dstPoint)) {
			continue;
		}

		TRGB* pRawRGB = rawBmp.GetRGB(dstPoint.x, dstPoint.y);
		TRGB* pRGB = bmp.GetRGB(srcPoint.x, srcPoint.y);
		if (pRawRGB == nullptr || pRGB == nullptr) {
			continue;
		}

		pRGB->red = pRawRGB->red;
		pRGB->green = pRawRGB->green;
		pRGB->blue = pRawRGB->blue;
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpTransNoColor(CBmp& bmp) {
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			U32 avgColor = (pRGB->red + pRGB->green + pRGB->blue) / 3;
			
			pRGB->red = avgColor;
			pRGB->green = avgColor;
			pRGB->blue = avgColor;
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpTransBlackWhite(CBmp& bmp, double adjust) {
	U32 avgColorTotal = BmpCalcAvgColor(bmp);
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			U32 avgColor = (pRGB->red + pRGB->green + pRGB->blue) / 3;

			if (avgColor <= (avgColorTotal * adjust)) {
				pRGB->red = 0;
				pRGB->green = 0;
				pRGB->blue = 0;
			} else {
				pRGB->red = 0xFF;
				pRGB->green = 0xFF;
				pRGB->blue = 0xFF;
			}
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpReverseColor(CBmp& bmp) {
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			pRGB->red = 0xFF - pRGB->red;
			pRGB->green = 0xFF - pRGB->green;
			pRGB->blue = 0xFF - pRGB->blue;
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpAdjustBr(CBmp& bmp, double a, double b) {
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			pRGB->red = BmpAdjustBrCalcVal(pRGB->red, a, b);
			pRGB->green = BmpAdjustBrCalcVal(pRGB->green, a, b);
			pRGB->blue = BmpAdjustBrCalcVal(pRGB->blue, a, b);
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static std::vector<TPoint> BmpGetRatotePoints(const TPoint& centerPoint,
	double angle, const TPoint& initPoint, U32 width, U32 height) {
	double distMax = BmpCalcDistMax(centerPoint, initPoint, width, height);
	TPoint moveCenterPoint;
	moveCenterPoint.x = centerPoint.x + distMax;
	moveCenterPoint.y = centerPoint.y + distMax;
	
	TPoint srcPoint;
	TPoint dstPoint;
	std::vector<TPoint> polygonPoints;

	srcPoint.x = initPoint.x + distMax;
	srcPoint.y = initPoint.y + distMax;
	BmpRotatePoint(moveCenterPoint, angle, srcPoint, dstPoint);
	polygonPoints.push_back(dstPoint);

	srcPoint.x = initPoint.x + distMax + width;
	srcPoint.y = initPoint.y + distMax;
	BmpRotatePoint(moveCenterPoint, angle, srcPoint, dstPoint);
	polygonPoints.push_back(dstPoint);

	srcPoint.x = initPoint.x + distMax + width;
	srcPoint.y = initPoint.y + distMax + height;
	BmpRotatePoint(moveCenterPoint, angle, srcPoint, dstPoint);
	polygonPoints.push_back(dstPoint);

	srcPoint.x = initPoint.x + distMax;
	srcPoint.y = initPoint.y + distMax + height;
	BmpRotatePoint(moveCenterPoint, angle, srcPoint, dstPoint);
	polygonPoints.push_back(dstPoint);

	std::vector<TPoint> polygonBorder = BmpGetPolygonPoint(polygonPoints);

	TPoint inAreaPointRaw;
	inAreaPointRaw.x = initPoint.x + distMax + 1;
	inAreaPointRaw.y = initPoint.y + distMax + 1;
	TPoint inAreaPoint;
	BmpRotatePoint(moveCenterPoint, angle, inAreaPointRaw, inAreaPoint);

	std::vector<TPoint> areaPointVec = BmpGetAreaPoint(polygonBorder, inAreaPoint,
		moveCenterPoint.x + distMax, moveCenterPoint.y + distMax);
	areaPointVec.insert(areaPointVec.end(), polygonBorder.begin(), polygonBorder.end());

	std::vector<TPoint> retPoints;
	for (U32 i = 0; i < areaPointVec.size(); ++i) {
		if (areaPointVec[i].x < distMax ||
			areaPointVec[i].y < distMax) {
			continue;
		}
		TPoint retPoint;
		retPoint.x = areaPointVec[i].x - distMax;
		retPoint.y = areaPointVec[i].y - distMax;
		retPoints.push_back(retPoint);
	}

	return retPoints;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static U32 BmpCalcDistMax(const TPoint& centerPoint,
	const TPoint& initPoint, U32 width, U32 height) {
	std::vector<TPoint> polygonPoints;
	TPoint polygonPoint;

	polygonPoint.x = initPoint.x;
	polygonPoint.y = initPoint.y;
	polygonPoints.push_back(polygonPoint);

	polygonPoint.x = initPoint.x + width;
	polygonPoint.y = initPoint.y;
	polygonPoints.push_back(polygonPoint);

	polygonPoint.x = initPoint.x + width;
	polygonPoint.y = initPoint.y + height;
	polygonPoints.push_back(polygonPoint);

	polygonPoint.x = initPoint.x;
	polygonPoint.y = initPoint.y + height;
	polygonPoints.push_back(polygonPoint);

	double distMax = 0;
	for (U32 i = 0; i < polygonPoints.size(); ++i) {
		double dist = PointCalcDist(centerPoint, polygonPoints[i]);
		if (distMax < dist) {
			distMax = dist;
		}
	}
	return round(distMax) + 10;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static U32 BmpCalcAvgColor(const CBmp& bmp) {
	U64 totalColor = 0;
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			totalColor += pRGB->red;
			totalColor += pRGB->green;
			totalColor += pRGB->blue;
		}
	}
	U32 avgColor = totalColor / bmp.GetWidth() / bmp.GetWidth() / 3;
	return avgColor;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static U8 BmpAdjustBrCalcVal(U8 val, double a, double b) {
	double ret = val * a + b;
	if (ret < 0) {
		return 0;
	}

	if (0xff < ret) {
		return 0xff;
	}

	return round(ret);
}

