

/**************************************************************************
* *
* * FILE NAME : BmpDrawPointSuite.cpp
* *
* * DESCRIPTION : BmpDrawPointSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpDrawPointSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/DrawPoint/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpDrawPointTest();
static void BmpDrawPointsTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawPointSuite() {
	BmpDrawPointTest();
	BmpDrawPointsTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawPointTest() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint point;
	point.x = 0;
	point.y = 0;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawPoint(bmp, point, rgb);
	bmp.Save(DIR_DST "draw_point.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawPointsTest() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {9, 9};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_points.bmp");
}

