

/**************************************************************************
* *
* * FILE NAME : BmpResizeSuite.cpp
* *
* * DESCRIPTION : BmpResizeSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpResizeSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/Resize/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpResizeTest_big();
static void BmpResizeTest_small();
static void BmpResizeTest_small_big();
static void BmpResizeTest_big_small();
static void BmpResizeTest_mosaic();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpResizeSuite() {
	BmpResizeTest_big();
	BmpResizeTest_small();
	BmpResizeTest_small_big();
	BmpResizeTest_big_small();
	BmpResizeTest_mosaic();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpResizeTest_big() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 1.5, bmp.GetHeight() * 1.5);
	bmp.Save(DIR_DST "big.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpResizeTest_small() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 0.7, bmp.GetHeight() * 0.7);
	bmp.Save(DIR_DST "small.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpResizeTest_small_big() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 0.7, bmp.GetHeight() * 1.5);
	bmp.Save(DIR_DST "small_big.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpResizeTest_big_small() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() * 1.5, bmp.GetHeight() * 0.7);
	bmp.Save(DIR_DST "big_small.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpResizeTest_mosaic() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpResize(bmp, bmp.GetWidth() / 20, bmp.GetHeight() / 20);
	BmpResize(bmp, bmp.GetWidth() * 20, bmp.GetHeight() * 20);
	bmp.Save(DIR_DST "mosaic.bmp");
}

