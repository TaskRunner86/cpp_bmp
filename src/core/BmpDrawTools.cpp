

/**************************************************************************
* *
* * FILE NAME : BmpDrawTools.cpp
* *
* * DESCRIPTION : BmpDrawTools cpp file
* *
* * DATE : 2024-2-26
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include<cmath>
#include "BmpDrawTools.h"


//******************************************************************************
// macro
//******************************************************************************

#define GRAD_MAX_VAL (100000)


//******************************************************************************
// declaration of function
//******************************************************************************

static std::vector<TPoint> BmpDrawGetSectorPoint(U32 radius);
static bool BmpDrawCheckPointValid(const CBmp& bmp, const TPoint& point);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawPoint(CBmp& bmp, const TPoint& point, const TRGB& rgb) {
	if (!BmpDrawCheckPointValid(bmp, point)) {
		return;
	}
	
	TRGB* pRGB = bmp.GetRGB(point.x, point.y);
	pRGB->red = rgb.red;
	pRGB->green = rgb.green;
	pRGB->blue = rgb.blue;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawLine(CBmp& bmp, const TPoint& start, const TPoint& end, const TRGB& rgb) {
	std::vector<TPoint> pointVec = BmpGetLinePoint(start, end);

	for (U32 i = 0; i < pointVec.size(); ++i) {
		BmpDrawPoint(bmp, pointVec[i], rgb);
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawCircle(CBmp& bmp, const TPoint& centerPoint, U32 radius, const TRGB& rgb) {
	std::vector<TPoint> pointVec = BmpGetCirclePoint(centerPoint, radius);

	for (U32 i = 0; i < pointVec.size(); ++i) {
		BmpDrawPoint(bmp, pointVec[i], rgb);
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
std::vector<TPoint> BmpGetLinePoint(const TPoint& start, const TPoint& end) {
	std::vector<TPoint> pointVec;

	TPoint leftPoint;
	TPoint rightPoint;
	if (start.x < end.x) {
		leftPoint = start;
		rightPoint = end;
	} else {
		leftPoint = end;
		rightPoint = start;
	}

	for (U32 i = leftPoint.x; i <= rightPoint.x; ++i) {
		TPoint linePoint;
		linePoint.x = i;

		if (leftPoint.y < rightPoint.y) {
			double grad = 0;
			if (rightPoint.x != leftPoint.x) {
				grad = ((double)rightPoint.y - leftPoint.y) / 
					((double)rightPoint.x - leftPoint.x);
			} else {
				grad = GRAD_MAX_VAL;
			}
			linePoint.y = leftPoint.y + (i - leftPoint.x) * grad;
			pointVec.push_back(linePoint);

			U32 j = 1;
			while (j < grad && j <= (rightPoint.y - leftPoint.y)) {
				++linePoint.y;
				if (linePoint.y <= rightPoint.y && leftPoint.y <= linePoint.y) {
					pointVec.push_back(linePoint);
				}
				++j;
			}
		} else {
			double grad = 0;
			if (rightPoint.x != leftPoint.x) {
				grad = ((double)leftPoint.y - rightPoint.y) / 
					((double)rightPoint.x - leftPoint.x);
			} else {
				grad = GRAD_MAX_VAL;
			}
			linePoint.y = leftPoint.y - (i - leftPoint.x) * grad;
			pointVec.push_back(linePoint);

			U32 j = 1;
			while (j < grad && j <= (leftPoint.y - rightPoint.y)) {
				--linePoint.y;
				if (linePoint.y <= leftPoint.y && rightPoint.y <= linePoint.y) {
					pointVec.push_back(linePoint);
				}
				++j;
			}
		}	
	}

	return pointVec;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
std::vector<TPoint> BmpGetCirclePoint(const TPoint& centerPoint, U32 radius) {
	std::vector<TPoint> pointVec = BmpDrawGetSectorPoint(radius);
	for (U32 i = 0; i < pointVec.size(); ++i) {
		pointVec[i].x += centerPoint.x;
		pointVec[i].y += centerPoint.y;
	}

	U32 vecSize = pointVec.size();
	for (U32 i = 0; i < vecSize; ++i) {
		TPoint symPoint = {0, 0};
		symPoint.x = centerPoint.x - (pointVec[i].x - centerPoint.x);
		symPoint.y = pointVec[i].y;
		if (symPoint.x != centerPoint.x) {
			pointVec.push_back(symPoint);
		}
	}

	vecSize = pointVec.size();
	for (U32 i = 0; i < vecSize; ++i) {
		TPoint symPoint = {0, 0};
		symPoint.x = pointVec[i].x;
		symPoint.y = centerPoint.y - (pointVec[i].y - centerPoint.y);
		if (symPoint.y != centerPoint.y) {
			pointVec.push_back(symPoint);
		}
	}

	return pointVec;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static std::vector<TPoint> BmpDrawGetSectorPoint(U32 radius) {
	std::vector<TPoint> pointVec;

	for (U32 i = 0; i <= radius; ++i) {
		TPoint circlePoint = {0, 0};
		circlePoint.x = i;
		U32 firstY = sqrt(radius * radius - circlePoint.x * circlePoint.x);
		circlePoint.y = firstY;
		pointVec.push_back(circlePoint);

		if (i < radius) {
			U32 nextY = sqrt(radius * radius - (i + 1) * (i + 1));
		
			for (U32 j = 1; j < (firstY - nextY); ++j) {
				--circlePoint.y;
				pointVec.push_back(circlePoint);
			}
		}
	}
	return pointVec;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static bool BmpDrawCheckPointValid(const CBmp& bmp, const TPoint& point) {
	if (bmp.GetWidth() <= point.x) {
		printf("Width is over!\n");
		return false;
	}

	if (bmp.GetHeight() <= point.y) {
		printf("Height is over!\n");	
		return false;
	}

	return true;
}