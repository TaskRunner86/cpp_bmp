

/**************************************************************************
* *
* * FILE NAME : Draw.cpp
* *
* * DESCRIPTION : Draw cpp file
* *
* * DATE : 2024-2-21
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR "../bmp/draw/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void BmpDrawX();
static void BmpDrawOOOOO();

//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	BmpDrawX();
	BmpDrawOOOOO();	
	return 0;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawX() {
	CBmp bmp;
	bmp.Init(60, 60);
	TPoint startPoint = {0, 0};
	TPoint endPoint = {59, 59};
	TRGB rgb;
	rgb.blue = 0xff;
	rgb.green = 0;
	rgb.red = 0;
	BmpDrawLine(bmp, startPoint, endPoint, rgb);

	startPoint = {0, 59};
	endPoint = {59, 0};
	rgb.blue = 0;
	rgb.green = 0;
	rgb.red = 0xff;
	BmpDrawLine(bmp, startPoint, endPoint, rgb);
	bmp.Save(DIR "draw_X.bmp");	
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawOOOOO() {
	CBmp bmp;
	bmp.Init(800, 200);
	TRGB rgb = {0xFF, 0xFF, 0xFF};	

	TPoint centerPoint = {100, 100};
	U32 radius = 90;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);

	centerPoint = {250, 100};
	radius = 90;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);

	centerPoint = {400, 100};
	radius = 90;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);	

	centerPoint = {550, 100};
	radius = 90;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);	

	centerPoint = {700, 100};
	radius = 90;
	BmpDrawCircle(bmp, centerPoint, radius, rgb);

	bmp.Save(DIR "draw_OOOOO.bmp");
}
