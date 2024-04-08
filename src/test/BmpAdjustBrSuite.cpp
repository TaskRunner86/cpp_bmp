

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

static void BmpAdjustBrTest_add_1_50();
static void BmpAdjustBrTest_add_1_255();
static void BmpAdjustBrTest_sub_1_50();
static void BmpAdjustBrTest_sub_1_255();

static void BmpAdjustBrTest_add_2_0();
static void BmpAdjustBrTest_add_1_5_0();
static void BmpAdjustBrTest_sub_0_8_0();
static void BmpAdjustBrTest_sub_0_5_0();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpAdjustBrSuite() {
	BmpAdjustBrTest_add_1_50();
	BmpAdjustBrTest_add_1_255();
	BmpAdjustBrTest_sub_1_50();
	BmpAdjustBrTest_sub_1_255();
	BmpAdjustBrTest_add_2_0();
	BmpAdjustBrTest_add_1_5_0();
	BmpAdjustBrTest_sub_0_8_0();
	BmpAdjustBrTest_sub_0_5_0();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_add_1_50() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 1, 50);
	bmp.Save(DIR_DST "add_1_50.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_add_1_255() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 1, 255);
	bmp.Save(DIR_DST "add_1_255.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_sub_1_50() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 1, -50);
	bmp.Save(DIR_DST "sub_1_50.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_sub_1_255() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 1, -255);
	bmp.Save(DIR_DST "sub_1_255.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_add_2_0() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 2, 0);
	bmp.Save(DIR_DST "add_2_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_add_1_5_0() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 1.5, 0);
	bmp.Save(DIR_DST "add_1_5_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_sub_0_8_0() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 0.8, 0);
	bmp.Save(DIR_DST "sub_0_8_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpAdjustBrTest_sub_0_5_0() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpAdjustBr(bmp, 0.5, 0);
	bmp.Save(DIR_DST "sub_0_5_0.bmp");
}

