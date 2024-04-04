

/**************************************************************************
* *
* * FILE NAME : BmpRotateSuite.cpp
* *
* * DESCRIPTION : BmpRotateSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpRotateSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/Rotate/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpRotateTest_1_4_200_200();
static void BmpRotateTest_1_3_200_200();
static void BmpRotateTest_1_2_200_200();
static void BmpRotateTest_1_200_200();
static void BmpRotateTest_2_200_200();
static void BmpRotateTest_1_4_full();
static void BmpRotateTest_1_3_full();
static void BmpRotateTest_1_2_full();
static void BmpRotateTest_1_full();
static void BmpRotateTest_2_full();
static void BmpRotateTest_1_3_reverse();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpRotateSuite() {
	BmpRotateTest_1_4_200_200();
	BmpRotateTest_1_3_200_200();
	BmpRotateTest_1_2_200_200();
	BmpRotateTest_1_200_200();
	BmpRotateTest_2_200_200();
	BmpRotateTest_1_4_full();
	BmpRotateTest_1_3_full();
	BmpRotateTest_1_2_full();
	BmpRotateTest_1_full();
	BmpRotateTest_2_full();
	BmpRotateTest_1_3_reverse();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_4_200_200() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpRotate(bmp, {300, 300}, PI / 4, {200, 200}, 100, 50, {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_4_200_200.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_3_200_200() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpRotate(bmp, {300, 300}, PI / 3, {200, 200}, 100, 50, {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_3_200_200.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_2_200_200() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpRotate(bmp, {300, 300}, PI / 2, {200, 200}, 100, 50, {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_2_200_200.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_200_200() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpRotate(bmp, {300, 300}, PI, {200, 200}, 100, 50, {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_200_200.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_2_200_200() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpRotate(bmp, {300, 300}, PI * 2, {200, 200}, 100, 50, {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_2_200_200.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_4_full() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	TPoint centerPoint;
	centerPoint.x = (bmp.GetWidth() / 2);
	centerPoint.y = (bmp.GetHeight() / 2);
	BmpRotate(bmp, centerPoint, (PI / 4), {0, 0},
		bmp.GetWidth(), bmp.GetHeight(), {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_4_full.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_3_full() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	TPoint centerPoint;
	centerPoint.x = (bmp.GetWidth() / 2);
	centerPoint.y = (bmp.GetHeight() / 2);
	BmpRotate(bmp, centerPoint, (PI / 3), {0, 0},
		bmp.GetWidth(), bmp.GetHeight(), {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_3_full.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_2_full() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	TPoint centerPoint;
	centerPoint.x = (bmp.GetWidth() / 2);
	centerPoint.y = (bmp.GetHeight() / 2);
	BmpRotate(bmp, centerPoint, (PI / 2), {0, 0},
		bmp.GetWidth(), bmp.GetHeight(), {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_2_full.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_full() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	TPoint centerPoint;
	centerPoint.x = (bmp.GetWidth() / 2);
	centerPoint.y = (bmp.GetHeight() / 2);
	BmpRotate(bmp, centerPoint, PI, {0, 0},
		bmp.GetWidth(), bmp.GetHeight(), {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_full.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_2_full() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	TPoint centerPoint;
	centerPoint.x = (bmp.GetWidth() / 2);
	centerPoint.y = (bmp.GetHeight() / 2);
	BmpRotate(bmp, centerPoint, PI * 2, {0, 0},
		bmp.GetWidth(), bmp.GetHeight(), {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_2_full.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRotateTest_1_3_reverse() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	TPoint centerPoint;
	centerPoint.x = (bmp.GetWidth() / 2);
	centerPoint.y = (bmp.GetHeight() / 2);
	BmpRotate(bmp, centerPoint, -(PI / 3), {0, 0},
		bmp.GetWidth(), bmp.GetHeight(), {0, 0, 0});
	bmp.Save(DIR_DST "Rotate_1_3_reverse.bmp");
}

