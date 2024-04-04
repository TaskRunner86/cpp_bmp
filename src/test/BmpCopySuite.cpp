

/**************************************************************************
* *
* * FILE NAME : BmpCopySuite.cpp
* *
* * DESCRIPTION : BmpCopySuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpCopySuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/Copy/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpCopyTest_100_100();
static void BmpCopyTest_1000_1000();
static void BmpCutTest_100_100();
static void BmpCutTest_1000_1000();
static void BmpPasteTest_100_100();
static void BmpPasteTest_1000_1000();
static void BmpPasteTest_smile();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpCopySuite() {
	BmpCopyTest_100_100();
	BmpCopyTest_1000_1000();
	BmpCutTest_100_100();
	BmpCutTest_1000_1000();
	BmpPasteTest_100_100();
	BmpPasteTest_1000_1000();
	BmpPasteTest_smile();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpCopyTest_100_100() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp = BmpCopy(bmp, {100, 100}, 100, 100);
	newBmp.Save(DIR_DST "copy_100_100.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpCopyTest_1000_1000() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp = BmpCopy(bmp, {100, 100}, 1000, 1000);
	newBmp.Save(DIR_DST "copy_1000_1000.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpCutTest_100_100() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp = BmpCut(bmp, {100, 100}, 100, 100, {0, 0, 0});
	bmp.Save(DIR_DST "cut_src_100_100.bmp");	
	newBmp.Save(DIR_DST "cut_dst_100_100.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpCutTest_1000_1000() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp = BmpCut(bmp, {100, 100}, 1000, 1000, {0, 0, 0});
	bmp.Save(DIR_DST "cut_src_1000_1000.bmp");	
	newBmp.Save(DIR_DST "cut_dst_1000_1000.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpPasteTest_100_100() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp;
	newBmp.Init(100, 100);
	BmpPaste(bmp, newBmp, {100, 100});
	bmp.Save(DIR_DST "paste_100_100.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpPasteTest_1000_1000() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp;
	newBmp.Init(1000, 1000);
	BmpPaste(bmp, newBmp, {100, 100});
	bmp.Save(DIR_DST "paste_1000_1000.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpPasteTest_smile() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	CBmp newBmp;
	newBmp.Load(DIR_SRC "smile.bmp");
	BmpPaste(bmp, newBmp, {100, 100});
	bmp.Save(DIR_DST "paste_smile.bmp");	
}

