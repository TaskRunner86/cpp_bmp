

/**************************************************************************
* *
* * FILE NAME : BmpDrawAreaSuite.cpp
* *
* * DESCRIPTION : BmpDrawAreaSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpDrawAreaSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/DrawArea/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpDrawAreaTest_3();
static void BmpDrawAreaTest_4();
static void BmpDrawAreaTest_circle();
static void BmpDrawAreaTest_broken();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawAreaSuite() {
	BmpDrawAreaTest_3();
	BmpDrawAreaTest_4();
	BmpDrawAreaTest_circle();
	BmpDrawAreaTest_broken();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawAreaTest_3() {
	CBmp bmp;
	bmp.Init(41, 41);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({0, 0});
	polygonPoints.push_back({40, 0});
	polygonPoints.push_back({20, 40});
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	std::vector<TPoint> polygonBorder = BmpGetPolygonPoint(polygonPoints);
	std::vector<TPoint> areaPoints = BmpGetAreaPoint(polygonBorder,
		{20, 20}, bmp.GetWidth(), bmp.GetHeight());
	BmpDrawPoints(bmp, areaPoints, {0, 0x8f, 0xff});
	bmp.Save(DIR_DST "draw_area_3.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawAreaTest_4() {
	CBmp bmp;
	bmp.Init(10, 10);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({0, 0});
	polygonPoints.push_back({9, 0});
	polygonPoints.push_back({9, 9});
	polygonPoints.push_back({0, 9});
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	std::vector<TPoint> polygonBorder = BmpGetPolygonPoint(polygonPoints);
	std::vector<TPoint> areaPoints = BmpGetAreaPoint(polygonBorder,
		{5, 5}, bmp.GetWidth(), bmp.GetHeight());
	BmpDrawPoints(bmp, areaPoints, {0, 0x8f, 0xff});
	bmp.Save(DIR_DST "draw_area_4.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawAreaTest_circle() {
	CBmp bmp;
	bmp.Init(41, 41);
	TPoint centerPoint = {20, 20};
	U32 radius = 20;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	std::vector<TPoint> circleBorder = BmpGetCirclePoint(centerPoint, radius);
	BmpDrawArea(bmp, circleBorder, centerPoint, {0, 0x8f, 0xff});
	bmp.Save(DIR_DST "draw_area_circle.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawAreaTest_broken() {
	CBmp bmp;
	bmp.Init(40, 40);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({3, 3});
	polygonPoints.push_back({3, 20});
	polygonPoints.push_back({20, 20});
	polygonPoints.push_back({20, 3});
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	std::vector<TPoint> polygonBorder = BmpGetPolygonPoint(polygonPoints);
	polygonBorder.pop_back();
	polygonBorder.pop_back();
	std::vector<TPoint> areaPoints = BmpGetAreaPoint(polygonBorder,
		{10, 10}, bmp.GetWidth(), bmp.GetHeight());
	BmpDrawPoints(bmp, areaPoints, {0, 0x8f, 0xff});
	bmp.Save(DIR_DST "draw_area_broken.bmp");
}

