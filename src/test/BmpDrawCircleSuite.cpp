

/**************************************************************************
* *
* * FILE NAME : BmpDrawCircleSuite.cpp
* *
* * DESCRIPTION : BmpDrawCircleSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpDrawCircleSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/DrawCircle/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpDrawCircleTest_50_50_40();
static void BmpDrawCircleTest_10_20_40();
static void BmpDrawCircleTest_5_5_1();
static void BmpDrawCircleTest_20_20_20();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawCircleSuite() {
	BmpDrawCircleTest_50_50_40();
	BmpDrawCircleTest_10_20_40();
	BmpDrawCircleTest_5_5_1();
	BmpDrawCircleTest_20_20_20();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawCircleTest_50_50_40() {
	CBmp bmp;
	bmp.Init(101, 101);
	TPoint centerPoint = {50, 50};
	U32 radius = 40;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR_DST "draw_circle_50_50_40.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawCircleTest_10_20_40() {
	CBmp bmp;
	bmp.Init(100, 100);
	TPoint centerPoint = {10, 20};
	U32 radius = 40;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR_DST "draw_circle_10_20_40.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawCircleTest_5_5_1() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint centerPoint = {5, 5};
	U32 radius = 1;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR_DST "draw_circle_5_5_1.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawCircleTest_20_20_20() {
	CBmp bmp;
	bmp.Init(41, 41);
	TPoint centerPoint = {20, 20};
	U32 radius = 20;
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	bmp.Save(DIR_DST "draw_circle_20_20_20.bmp");
}

