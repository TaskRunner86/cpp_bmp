

/**************************************************************************
* *
* * FILE NAME : BmpDrawLineSuite.cpp
* *
* * DESCRIPTION : BmpDrawLineSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpDrawLineSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/DrawLine/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpDrawLineTest_0_0_9_9();
static void BmpDrawLineTest_9_9_0_0();
static void BmpDrawLineTest_0_9_9_0();
static void BmpDrawLineTest_9_0_0_9();
static void BmpDrawLineTest_0_0_39_19();
static void BmpDrawLineTest_0_39_19_0();
static void BmpDrawLineTest_0_0_19_39();
static void BmpDrawLineTest_0_0_30_39();
static void BmpDrawLineTest_0_0_0_39();
static void BmpDrawLineTest_39_39_39_0();
static void BmpDrawLineTest_0_19_39_19();
static void BmpDrawLineTest_0_19_39_0();
static void BmpDrawLineTest_39_39_0_39();
static void BmpDrawLineTest_19_0_19_39();
static void BmpDrawLineTest_399_0_199_399();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpDrawLineSuite() {
	BmpDrawLineTest_0_0_9_9();
	BmpDrawLineTest_9_9_0_0();
	BmpDrawLineTest_0_9_9_0();
	BmpDrawLineTest_9_0_0_9();
	BmpDrawLineTest_0_0_39_19();
	BmpDrawLineTest_0_39_19_0();
	BmpDrawLineTest_0_0_19_39();
	BmpDrawLineTest_0_0_30_39();
	BmpDrawLineTest_0_0_0_39();
	BmpDrawLineTest_39_39_39_0();
	BmpDrawLineTest_0_19_39_19();
	BmpDrawLineTest_0_19_39_0();
	BmpDrawLineTest_39_39_0_39();
	BmpDrawLineTest_19_0_19_39();
	BmpDrawLineTest_399_0_199_399();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_0_9_9() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {9, 9};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_0_9_9.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_9_9_0_0() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint startPoint = {9, 9};
	TPoint endPoint = {0, 0};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_9_9_0_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_9_9_0() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint startPoint = {0, 9};
	TPoint endPoint = {9, 0};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_9_9_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_9_0_0_9() {
	CBmp bmp;
	bmp.Init(10, 10);
	TPoint startPoint = {9, 0};
	TPoint endPoint = {0, 9};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_9_0_0_9.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_0_39_19() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {39, 19};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_0_39_19.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_39_19_0() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 39};
	TPoint endPoint = {19, 0};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_39_19_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_0_19_39() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {19, 39};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_0_19_39.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_0_30_39() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {30, 39};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_0_30_39.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_0_0_39() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {0, 39};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_0_0_39.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_39_39_39_0() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {39, 39};
	TPoint endPoint = {39, 0};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_39_39_39_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_19_39_19() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 19};
	TPoint endPoint = {39, 19};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_19_39_19.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_0_19_39_0() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {0, 19};
	TPoint endPoint = {39, 0};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_0_19_39_0.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_39_39_0_39() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {39, 39};
	TPoint endPoint = {0, 39};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_39_39_0_39.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_19_0_19_39() {
	CBmp bmp;
	bmp.Init(40, 40);
	TPoint startPoint = {19, 0};
	TPoint endPoint = {19, 39};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_19_0_19_39.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawLineTest_399_0_199_399() {
	CBmp bmp;
	bmp.Init(400, 400);
	TPoint startPoint = {399, 0};
	TPoint endPoint = {199, 399};
	TRGB rgb = {0xFF, 0xFF, 0xFF};
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR_DST "draw_line_399_0_199_399.bmp");
}

