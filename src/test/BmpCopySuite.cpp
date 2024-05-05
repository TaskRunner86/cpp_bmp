

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
static void BmpTransparentTest_smile();
static void BmpTransparentTest_hand();
static void BmpTransparentTest_smile_hand();


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
	BmpTransparentTest_smile();
	BmpTransparentTest_hand();
	BmpTransparentTest_smile_hand();
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
	CBmp bottomBmp;
	bottomBmp.Load(DIR_SRC "raw.bmp");
	CBmp topBmp;
	topBmp.Init(100, 100);
	BmpPaste(bottomBmp, topBmp, {100, 100});
	bottomBmp.Save(DIR_DST "paste_100_100.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpPasteTest_1000_1000() {
	CBmp bottomBmp;
	bottomBmp.Load(DIR_SRC "raw.bmp");
	CBmp topBmp;
	topBmp.Init(1000, 1000);
	BmpPaste(bottomBmp, topBmp, {100, 100});
	bottomBmp.Save(DIR_DST "paste_1000_1000.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpPasteTest_smile() {
	CBmp bottomBmp;
	bottomBmp.Load(DIR_SRC "raw.bmp");
	CBmp topBmp;
	topBmp.Load(DIR_SRC "smile.bmp");
	BmpPaste(bottomBmp, topBmp, {100, 100});
	bottomBmp.Save(DIR_DST "paste_smile.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpTransparentTest_smile() {
	CBmp bottomBmp;
	bottomBmp.Init(500, 500);
	CBmp topBmp;
	topBmp.Load(DIR_SRC "smile.bmp");
	BmpTransparent(bottomBmp, topBmp, 0.3, {50, 50});
	bottomBmp.Save(DIR_DST "transparent_smile.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpTransparentTest_hand() {
	CBmp bottomBmp;
	bottomBmp.Init(500, 500);
	CBmp topBmp;
	topBmp.Load(DIR_SRC "hand.bmp");
	BmpTransparent(bottomBmp, topBmp, 0.7, {50, 50});
	bottomBmp.Save(DIR_DST "transparent_hand.bmp");	
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpTransparentTest_smile_hand() {
	CBmp bottomBmp;
	bottomBmp.Load(DIR_SRC "hand.bmp");
	CBmp topBmp;
	topBmp.Load(DIR_SRC "smile.bmp");
	BmpTransparent(bottomBmp, topBmp, 0.3, {50, 50});
	bottomBmp.Save(DIR_DST "transparent_smile_hand.bmp");	
}

