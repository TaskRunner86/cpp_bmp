

/**************************************************************************
* *
* * FILE NAME : BmpAdjustBrSuite.cpp
* *
* * DESCRIPTION : BmpAdjustBrSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpAdjustBrSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/AdjustBr/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpAdjustBrTest_add_50();
static void BmpAdjustBrTest_add_255();
static void BmpAdjustBrTest_sub_50();
static void BmpAdjustBrTest_sub_255();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpAdjustBrSuite() {
	BmpAdjustBrTest_add_50();
	BmpAdjustBrTest_add_255();
	BmpAdjustBrTest_sub_50();
	BmpAdjustBrTest_sub_255();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_add_50() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 50, true);
	bmp.Save(DIR_DST "add_50.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_add_255() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 0xff, true);
	bmp.Save(DIR_DST "add_255.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_sub_50() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 50, false);
	bmp.Save(DIR_DST "sub_50.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_sub_255() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 0xff, false);
	bmp.Save(DIR_DST "sub_255.bmp");
}

