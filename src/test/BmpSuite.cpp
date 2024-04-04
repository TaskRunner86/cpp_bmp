

/**************************************************************************
* *
* * FILE NAME : BmpSuite.cpp
* *
* * DESCRIPTION : BmpSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/Bmp/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpInitTest();
static void BmpCopyContructTest();
static void BmpCopyAssignTest();
static void BmpLineTest();
static void BmpRGBTest();
static void BmpRGBColorTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpSuite() {
	BmpInitTest();
	BmpCopyContructTest();
	BmpCopyAssignTest();
	BmpLineTest();
	BmpRGBTest();
	BmpRGBColorTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpInitTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	bmp.Init(bmp.GetWidth(), bmp.GetHeight());
	bmp.Save(DIR_DST "new_black.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpCopyContructTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp bmpNew = bmp;	
	bmpNew.Save(DIR_DST "copy_contruct.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpCopyAssignTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp bmpNew;
	bmpNew = bmp;
	bmpNew.Save(DIR_DST "copy_assign.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpLineTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	for (U32 i = 0; i < bmp.GetHeight(); ++i) {
		if (i % 10 <= 3) {
			for (U32 j = 0; j < bmp.GetWidth(); ++j) {
				TRGB* pRGB = bmp.GetRGB(j, i);
				memset(pRGB, 0, sizeof(TRGB));
			}
		}
	}
	bmp.Save(DIR_DST "line.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRGBTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			if (i % 10 <= 3 && j % 10 <= 3) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->red = 0x8f;
			}

			if (3 < i % 10 && i % 10 <= 6 &&
				3 < j % 10 && j % 10 <= 6) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->green = 0x8f;
			}

			if (6 < i % 10 && 6 < j % 10) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->blue = 0x8f;
			}
		}
	}
	bmp.Save(DIR_DST "RGB.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpRGBColorTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			if (i % 10 <= 5 && j % 10 <= 5) {
				TRGB* pRGB = bmp.GetRGB(i, j);
				pRGB->red = i;
				pRGB->green = 0;
				pRGB->blue = j;
			}
		}
	}
	bmp.Save(DIR_DST "RGB_color.bmp");
}

