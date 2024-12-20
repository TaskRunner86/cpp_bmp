

/**************************************************************************
* *
* * FILE NAME : BmpColorRangeSuite.cpp
* *
* * DESCRIPTION : BmpColorRangeSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpColorRangeSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/ColorRange/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpRemoveBackgroundTest();
static void BmpRemoveManTest();
static void BmpChangeBackgroundTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpColorRangeSuite() {
	BmpRemoveBackgroundTest();
	BmpRemoveManTest();
	BmpChangeBackgroundTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRemoveBackgroundTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "green.bmp");
	std::vector<TPoint> backgroundPoints = BmpGetColorRangePoint(bmp, 
		{90, 30, 30}, {155, 100, 100});
	BmpDrawPoints(bmp, backgroundPoints, {0, 0, 0});
	bmp.Save(DIR_DST "remove_background.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRemoveManTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "green.bmp");
	std::vector<TPoint> backgroundPoints = BmpGetColorRangePoint(bmp, 
		{90, 30, 30}, {155, 100, 100});
	std::vector<TPoint> manPoints = BmpGetReversePoint(bmp, backgroundPoints);
	BmpDrawPoints(bmp, manPoints, {0, 0, 0});
	bmp.Save(DIR_DST "remove_man.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpChangeBackgroundTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "green.bmp");
	std::vector<TPoint> backgroundPoints = BmpGetColorRangePoint(bmp, 
		{90, 30, 30}, {155, 100, 100});
	std::vector<TPoint> manPoints = BmpGetReversePoint(bmp, backgroundPoints);

	CBmp backgroundBmp;
	backgroundBmp.Load(DIR_SRC "background.bmp");

	for (U32 i = 0; i < manPoints.size(); ++i) {
		TRGB* pRawRGB = bmp.GetRGB(manPoints[i].x, manPoints[i].y);
		TRGB* pBackgroundRGB = backgroundBmp.GetRGB(manPoints[i].x + 100 , manPoints[i].y - 30);
		pBackgroundRGB->red = pRawRGB->red;
		pBackgroundRGB->green = pRawRGB->green;
		pBackgroundRGB->blue = pRawRGB->blue;
	}

	backgroundBmp.Save(DIR_DST "change_background.bmp");
}
