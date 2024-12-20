

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

static void BmpChangeBackgroundTest();
static void BmpRemoveManTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpColorRangeSuite() {
	BmpChangeBackgroundTest();
	BmpRemoveManTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpChangeBackgroundTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "green.bmp");
	std::vector<TPoint> backgroundPoints = BmpGetColorRangePoint(bmp, 
		{90, 30, 30}, {155, 100, 100});
	BmpDrawPoints(bmp, backgroundPoints, {0, 0x8f, 0xff});
	bmp.Save(DIR_DST "change_background.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRemoveManTest() {
	// CBmp bmp;
	// bmp.Load(DIR_SRC "raw.bmp");
	// BmpVerFlip(bmp);
	// bmp.Save(DIR_DST "ver_flip.bmp");
}

