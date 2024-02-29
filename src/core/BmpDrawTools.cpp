

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


#include "BmpDrawTools.h"
#include <cmath>
#include <set>


//******************************************************************************
// macro
//******************************************************************************

#define BMP_DRAW_MOVE_RATE (0.4)


//******************************************************************************
// declaration of function
//******************************************************************************

static std::vector<TPoint> BmpDrawGetSectorPoint(U32 radius);
static std::vector<TPoint> BmpDrawGetNeighborPoint(const TPoint& point,	U32 width, U32 height);
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
void BmpDrawPolygon(CBmp& bmp, std::vector<TPoint> pointVec, const TRGB& rgb) {
	std::vector<TPoint> polygonBorder = BmpGetPolygonPoint(pointVec);

	for (U32 i = 0; i < polygonBorder.size(); ++i) {
		BmpDrawPoint(bmp, polygonBorder[i], rgb);
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawCircle(CBmp& bmp, const TPoint& centerPoint, U32 radius, const TRGB& rgb) {
	if (radius == 0) {
		return;
	}

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

	if (leftPoint.y < rightPoint.y) {
		TPoint linePoint;
		linePoint.x = leftPoint.x;
		if (rightPoint.x == leftPoint.x) {
			for (U32 i = 0; i <= (rightPoint.y - leftPoint.y); ++i) {
				linePoint.y = leftPoint.y + i;
				pointVec.push_back(linePoint);
			}
			return pointVec;
		} 
	} else {
		TPoint linePoint;
		linePoint.x = leftPoint.x;
		if (rightPoint.x == leftPoint.x) {
			for (U32 i = 0; i <= (leftPoint.y - rightPoint.y); ++i) {
				linePoint.y = leftPoint.y - i;
				pointVec.push_back(linePoint);
			}
			return pointVec;
		} 
	}

	for (U32 i = leftPoint.x; i <= rightPoint.x; ++i) {
		TPoint linePoint;
		linePoint.x = i;

		if (leftPoint.y < rightPoint.y) {
			double grad = ((double)rightPoint.y - leftPoint.y) / 
				((double)rightPoint.x - leftPoint.x);
			
			linePoint.y = round(leftPoint.y + (i - leftPoint.x) * grad);
			pointVec.push_back(linePoint);

			U32 nextY = round(leftPoint.y + (i + 1 - leftPoint.x) * grad);
			U32 j = linePoint.y;
			while ((j + 1) < nextY) {
				++linePoint.y;
				if (linePoint.y <= rightPoint.y && leftPoint.y <= linePoint.y) {
					pointVec.push_back(linePoint);
				}
				++j;
			}
		} else {
			double grad = ((double)leftPoint.y - rightPoint.y) / 
				((double)rightPoint.x - leftPoint.x);

			linePoint.y = round(leftPoint.y - (i - leftPoint.x) * grad);
			pointVec.push_back(linePoint);

			U32 nextY = round(leftPoint.y - (i + 1 - leftPoint.x) * grad);
			U32 j = linePoint.y;
			while ((nextY + 1) < j) {
				--linePoint.y;
				if (linePoint.y <= leftPoint.y && rightPoint.y <= linePoint.y) {
					pointVec.push_back(linePoint);
				}
				--j;
			}
		}	
	}

	return pointVec;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
std::vector<TPoint> BmpGetPolygonPoint(std::vector<TPoint> pointVec) {
	std::set<TPoint> pointSet;
	for (U32 i = 0; i < pointVec.size() - 1; ++i) {
		std::vector<TPoint> linePointVec = BmpGetLinePoint(pointVec[i], pointVec[i + 1]);
		for (U32 j = 0; j < linePointVec.size(); ++j) {
			pointSet.insert(linePointVec[j]);
		}
	}

	std::vector<TPoint> linePointVec = BmpGetLinePoint(pointVec[0], pointVec[pointVec.size() - 1]);
	for (U32 j = 0; j < linePointVec.size(); ++j) {
		pointSet.insert(linePointVec[j]);
	}

	std::vector<TPoint> polygonPointVec(pointSet.begin(), pointSet.end());
	return polygonPointVec;
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
		if (centerPoint.x < (pointVec[i].x - centerPoint.x)) {
			continue;
		}

		TPoint symPoint = {0, 0};
		symPoint.x = centerPoint.x - (pointVec[i].x - centerPoint.x);
		symPoint.y = pointVec[i].y;
		if (symPoint.x == centerPoint.x) {
			continue;
		}
		pointVec.push_back(symPoint);
	}

	vecSize = pointVec.size();
	for (U32 i = 0; i < vecSize; ++i) {
		if (centerPoint.y < (pointVec[i].y - centerPoint.y)) {
			continue;
		}

		TPoint symPoint = {0, 0};
		symPoint.x = pointVec[i].x;
		symPoint.y = centerPoint.y - (pointVec[i].y - centerPoint.y);
		if (symPoint.y == centerPoint.y) {
			continue;
		}
		pointVec.push_back(symPoint);
	}
	
	return pointVec;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
std::vector<TPoint> BmpGetAreaPoint(
	std::vector<TPoint> border,
	const TPoint& inAreaPoint,
	U32 width,
	U32 height	
) {
	std::set<TPoint> borderSet(border.begin(), border.end());
	std::set<TPoint> areaPointSet;
	std::set<TPoint> procPointSet;
	procPointSet.insert(inAreaPoint);
	areaPointSet.insert(inAreaPoint);

	while (!procPointSet.empty()) {
		TPoint curPoint = *procPointSet.begin();
		std::vector<TPoint> neighborPointVec = BmpDrawGetNeighborPoint(
			curPoint, width, height);
		for (U32 i = 0; i < neighborPointVec.size(); ++i) {
			if (areaPointSet.find(neighborPointVec[i]) != areaPointSet.end()) {
				continue;
			}

			if (borderSet.find(neighborPointVec[i]) != borderSet.end()) {
				continue;
			}

			procPointSet.insert(neighborPointVec[i]);
			areaPointSet.insert(neighborPointVec[i]);
		}

		procPointSet.erase(curPoint);
	}

	std::vector<TPoint> areaPointVec(areaPointSet.begin(), areaPointSet.end());
	return areaPointVec;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static std::vector<TPoint> BmpDrawGetSectorPoint(U32 radius) {
	std::vector<TPoint> pointVec;

	if (radius == 0) {
		return pointVec;
	}

	for (U32 i = 0; i <= radius; ++i) {
		TPoint circlePoint = {0, 0};
		circlePoint.x = i;
		U32 firstY = round(sqrt(radius * radius - circlePoint.x * circlePoint.x));
		circlePoint.y = firstY;
		pointVec.push_back(circlePoint);

		if (i < radius) {
			U32 nextY = round(sqrt(radius * radius - (i + 1) * (i + 1)));

			bool isMove = false;
			for (U32 j = 1; j < (firstY - nextY); ++j) {
				if ((firstY - nextY) * BMP_DRAW_MOVE_RATE < j && !isMove) {
					++circlePoint.x;
					isMove = true;
				}

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
static std::vector<TPoint> BmpDrawGetNeighborPoint(const TPoint& point, U32 width, U32 height) {
	std::vector<TPoint> neighborPointVec;
	if ((point.y + 1) != height) {
		TPoint neighborPoint;
		neighborPoint.x = point.x;
		neighborPoint.y = point.y + 1; 
		neighborPointVec.push_back(neighborPoint);
	}

	if (point.y != 0) {
		TPoint neighborPoint;
		neighborPoint.x = point.x;
		neighborPoint.y = point.y - 1; 
		neighborPointVec.push_back(neighborPoint);
	}

	if (point.x != 0) {
		TPoint neighborPoint;
		neighborPoint.x = point.x - 1;
		neighborPoint.y = point.y; 
		neighborPointVec.push_back(neighborPoint);
	}

	if ((point.x + 1) != height) {
		TPoint neighborPoint;
		neighborPoint.x = point.x + 1;
		neighborPoint.y = point.y; 
		neighborPointVec.push_back(neighborPoint);
	}

	return neighborPointVec;
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

