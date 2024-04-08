

/**************************************************************************
* *
* * FILE NAME : BmpTransNoColorSuite.cpp
* *
* * DESCRIPTION : BmpTransNoColorSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpTransNoColorSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/TransNoColor/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpTransNoColorTest();
static void BmpTransBlackWhiteTest();
static void BmpReverseColorTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpTransNoColorSuite() {
	BmpTransNoColorTest();
	BmpTransBlackWhiteTest();
	BmpReverseColorTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpTransNoColorTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpTransNoColor(bmp);
	bmp.Save(DIR_DST "no_color.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpTransBlackWhiteTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpTransBlackWhite(bmp, 0.9);
	bmp.Save(DIR_DST "black_white.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpReverseColorTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpReverseColor(bmp);
	bmp.Save(DIR_DST "reverse_color.bmp");
}

