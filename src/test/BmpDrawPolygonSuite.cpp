

/**************************************************************************
* *
* * FILE NAME : BmpDrawPolygonSuite.cpp
* *
* * DESCRIPTION : BmpDrawPolygonSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpDrawPolygonSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/DrawPolygon/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpDrawPolygonTest_3();
static void BmpDrawPolygonTest_4();
static void BmpDrawPolygonTest_5();
static void BmpDrawRectTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawPolygonSuite() {
	BmpDrawPolygonTest_3();
	BmpDrawPolygonTest_4();
	BmpDrawPolygonTest_5();
	BmpDrawRectTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawPolygonTest_3() {
	CBmp bmp;
	bmp.Init(41, 41);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({0, 0});
	polygonPoints.push_back({40, 0});
	polygonPoints.push_back({20, 40});
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	bmp.Save(DIR_DST "draw_polygon_3.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawPolygonTest_4() {
	CBmp bmp;
	bmp.Init(41, 41);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({1, 1});
	polygonPoints.push_back({39, 1});
	polygonPoints.push_back({39, 39});
	polygonPoints.push_back({1, 39});
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	bmp.Save(DIR_DST "draw_polygon_4.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawPolygonTest_5() {
	CBmp bmp;
	bmp.Init(100, 100);
	std::vector<TPoint> polygonPoints;
	polygonPoints.push_back({20, 0});
	polygonPoints.push_back({80, 0});
	polygonPoints.push_back({99, 60});
	polygonPoints.push_back({50, 99});
	polygonPoints.push_back({0, 60});
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPolygon(bmp, polygonPoints, rgb);
	bmp.Save(DIR_DST "draw_polygon_5.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawRectTest() {
	CBmp bmp;
	bmp.Init(100, 100);
	BmpDrawRect(bmp, {0, 0}, 100, 80, {0, 0x8f, 0xff});
	bmp.Save(DIR_DST "draw_Rect.bmp");
}
