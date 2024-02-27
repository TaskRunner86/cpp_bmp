

/**************************************************************************
* *
* * FILE NAME : Test.cpp
* *
* * DESCRIPTION : Test cpp file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR "../bmp/test/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpToolsTest();
static void BmpDrawToolsTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	// BmpToolsTest();
	BmpDrawToolsTest();
	return 0;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpToolsTest() {
	CBmp bmp;
	bmp.Load(DIR "raw.bmp");
	bmp.Save(DIR "copy.bmp");

	for (U32 i = 0; i < bmp.GetHeight(); ++i) {
		if (i % 10 <= 3) {
			for (U32 j = 0; j < bmp.GetWidth(); ++j) {
				TRGB* pRGB = bmp.GetRGB(j, i);
				memset(pRGB, 0, sizeof(TRGB));
			}
		}
	}
	bmp.Save(DIR "line.bmp");

	bmp.Init(bmp.GetWidth(), bmp.GetHeight());
	bmp.Save(DIR "new_black.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpTransNoColor(bmp);
	bmp.Save(DIR "no_color.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpTransBlackWhite(bmp);
	bmp.Save(DIR "black_white.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpReverseColor(bmp);
	bmp.Save(DIR "reverse_color.bmp");

	bmp.Load(DIR "raw.bmp");
	CBmp bmpNew = bmp;	
	bmpNew.Save(DIR "copy_contruct.bmp");

	bmp.Load(DIR "raw.bmp");
	bmpNew = bmp;
	bmpNew.Save(DIR "copy_assign.bmp");

	bmp.Load(DIR "raw.bmp");
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			if (i % 10 <= 3 && j % 10 <= 3) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->red = 0x8f;
			}

			if (3 < i % 10 && i % 10 <= 6 &&
				3 < j % 10 && j % 10 <= 6) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->green = 0x8f;
			}

			if (6 < i % 10 && 6 < j % 10) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->blue = 0x8f;
			}
		}
	}
	bmp.Save(DIR "RGB.bmp");

	bmp.Load(DIR "raw.bmp");
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			if (i % 10 <= 5 && j % 10 <= 5) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->red = i;
				pRGB->green = 0;
				pRGB->blue = j;
			}
		}
	}
	bmp.Save(DIR "RGB_color.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 1.5, bmp.GetHeight() * 1.5);
	bmp.Save(DIR "big.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 0.7, bmp.GetHeight() * 0.7);
	bmp.Save(DIR "small.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 0.7, bmp.GetHeight() * 1.5);
	bmp.Save(DIR "small_big.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 1.5, bmp.GetHeight() * 0.7);
	bmp.Save(DIR "big_small.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpAdjustBr(bmp, 50, true);
	bmp.Save(DIR "add_50.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpAdjustBr(bmp, 0xff, true);
	bmp.Save(DIR "add_255.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpAdjustBr(bmp, 50, false);
	bmp.Save(DIR "sub_50.bmp");

	bmp.Load(DIR "raw.bmp");
	BmpAdjustBr(bmp, 0xff, false);
	bmp.Save(DIR "sub_255.bmp");	
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawToolsTest() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint point;
	point.x = 0;
	point.y = 0;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPoint(bmp, point, rgb);
	bmp.Save(DIR "draw_point.bmp");

	bmp.Init(10, 10);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {9, 9};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_0_9_9.bmp");

	bmp.Init(10, 10);
	startPoint = {9, 9};
	endPoint = {0, 0};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_9_9_0_0.bmp");

	bmp.Init(10, 10);
	startPoint = {0, 9};
	endPoint = {9, 0};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_9_9_0.bmp");

	bmp.Init(10, 10);
	startPoint = {9, 0};
	endPoint = {0, 9};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_9_0_0_9.bmp");

	bmp.Init(40, 40);
	startPoint = {0, 0};
	endPoint = {39, 19};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_0_39_19.bmp");

	bmp.Init(40, 40);
	startPoint = {0, 39};
	endPoint = {19, 0};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_39_19_0.bmp");

	bmp.Init(40, 40);
	startPoint = {0, 0};
	endPoint = {19, 39};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_0_19_39.bmp");

	bmp.Init(40, 40);
	startPoint = {0, 0};
	endPoint = {30, 39};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_0_30_39.bmp");	

	bmp.Init(40, 40);
	startPoint = {0, 0};
	endPoint = {0, 39};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_0_0_39.bmp");

	bmp.Init(40, 40);
	startPoint = {39, 39};
	endPoint = {39, 0};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_39_39_39_0.bmp");

	bmp.Init(40, 40);
	startPoint = {0, 19};
	endPoint = {39, 19};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_19_39_19.bmp");

	bmp.Init(40, 40);
	startPoint = {0, 19};
	endPoint = {39, 0};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_0_19_39_0.bmp");

	bmp.Init(40, 40);
	startPoint = {39, 39};
	endPoint = {0, 39};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_39_39_0_39.bmp");	

	bmp.Init(40, 40);
	startPoint = {19, 0};
	endPoint = {19, 39};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_line_19_0_19_39.bmp");

	bmp.Init(41, 41);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({0, 0});
	polygonPoints.push_back({40, 0});
	polygonPoints.push_back({20, 40});
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	std::vector<TPoint> polygonBorder = BmpGetPolygonPoint(polygonPoints);
	std::vector<TPoint> areaPoints = BmpGetAreaPoint(polygonBorder, {20, 20}, bmp.GetWidth(), bmp.GetHeight());
	
	for (U32 i = 0; i < areaPoints.size(); ++i) {
		BmpDrawPoint(bmp, areaPoints[i], {0, 0x8f, 0xff});
	}
	bmp.Save(DIR "draw_triangle_area.bmp");	

	bmp.Init(40, 40);
	polygonPoints.clear();
	polygonPoints.push_back({3, 3});
	polygonPoints.push_back({3, 20});
	polygonPoints.push_back({20, 20});
	polygonPoints.push_back({20, 3});
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	polygonBorder = BmpGetPolygonPoint(polygonPoints);
	polygonBorder.pop_back();
	polygonBorder.pop_back();
	areaPoints = BmpGetAreaPoint(polygonBorder, {20, 20}, bmp.GetWidth(), bmp.GetHeight());
	for (U32 i = 0; i < areaPoints.size(); ++i) {
		BmpDrawPoint(bmp, areaPoints[i], {0, 0x8f, 0xff});
	}
	bmp.Save(DIR "draw_broken_area.bmp");

	bmp.Init(10, 10);
	polygonPoints.clear();
	polygonPoints.push_back({0, 0});
	polygonPoints.push_back({9, 0});
	polygonPoints.push_back({9, 9});
	polygonPoints.push_back({0, 9});
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	polygonBorder = BmpGetPolygonPoint(polygonPoints);
	areaPoints = BmpGetAreaPoint(polygonBorder, {5, 5}, 10, 10);
	for (U32 i = 0; i < areaPoints.size(); ++i) {
		BmpDrawPoint(bmp, areaPoints[i], {0, 0x8f, 0xff});
	}
	bmp.Save(DIR "draw_square_area.bmp");

	bmp.Init(100, 100);
	TPoint centerPoint = {50, 50};
	U32 radius = 40;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR "draw_circle_50_50_40.bmp");	

	bmp.Init(100, 100);
	centerPoint = {10, 20};
	radius = 40;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR "draw_circle_10_20_40.bmp");	

	bmp.Init(10, 10);
	centerPoint = {5, 5};
	radius = 1;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR "draw_circle_5_5_1.bmp");	

	bmp.Init(41, 41);
	centerPoint = {20, 20};
	radius = 20;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR "draw_circle_20_20_20.bmp");

	bmp.Init(41, 41);
	centerPoint = {20, 20};
	radius = 20;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	std::vector<TPoint> CircleBorder = BmpGetCirclePoint(centerPoint, radius);
	areaPoints = BmpGetAreaPoint(CircleBorder, centerPoint, bmp.GetWidth(), bmp.GetHeight());
	
	for (U32 i = 0; i < areaPoints.size(); ++i) {
		BmpDrawPoint(bmp, areaPoints[i], {0, 0x8f, 0xff});
	}
	bmp.Save(DIR "draw_circle_area.bmp");				
}

