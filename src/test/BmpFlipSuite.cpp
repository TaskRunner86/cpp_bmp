

/**************************************************************************
* *
* * FILE NAME : BmpFlipSuite.cpp
* *
* * DESCRIPTION : BmpFlipSuite cpp file
* *
* * DATE : 2024-4-2
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpFlipSuite.h"
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_SRC "../bmp/test/Raw/"
#define DIR_DST "../bmp/test/Flip/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpHorFlipTest();
static void BmpVerFlipTest();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpFlipSuite() {
	BmpHorFlipTest();
	BmpVerFlipTest();
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpHorFlipTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpHorFlip(bmp);
	bmp.Save(DIR_DST "hor_flip.bmp");
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpVerFlipTest() {
	CBmp bmp;
	bmp.Load(DIR_SRC "raw.bmp");
	BmpVerFlip(bmp);
	bmp.Save(DIR_DST "ver_flip.bmp");
}

