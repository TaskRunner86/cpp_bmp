

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
static void BmpDrawSmile();


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	BmpDrawX();
	BmpDrawOOOOO();
	BmpDrawSmile();
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


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpDrawSmile() {
	CBmp bmp;
	bmp.Init(201, 201);

	for (U32 i = 0; i < bmp.GetHeight(); ++i) {
		for (U32 j = 0; j < bmp.GetWidth(); ++j) {
			BmpDrawPoint(bmp, {j, i}, {255, 255, 255});
		}
	}

	TPoint centerPoint = {100, 100};
	U32 radius = 95;
	TRGB rgb = {14, 193, 255};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	std::vector<TPoint> circleBorder = BmpGetCirclePoint(centerPoint, radius);
	std::vector<TPoint> areaPoints = BmpGetAreaPoint(circleBorder,
		centerPoint, bmp.GetWidth(), bmp.GetHeight());
	BmpDrawPoints(bmp, areaPoints, rgb);

	centerPoint = {70, 120};
	radius = 15;
	rgb = {0, 0, 0};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);
	circleBorder = BmpGetCirclePoint(centerPoint, radius);
	areaPoints = BmpGetAreaPoint(circleBorder,
		centerPoint, bmp.GetWidth(), bmp.GetHeight());
	BmpDrawPoints(bmp, areaPoints, rgb);

	centerPoint = {130, 120};
	BmpDrawCircle(bmp, centerPoint, radius, rgb);	
	circleBorder = BmpGetCirclePoint(centerPoint, radius);
	areaPoints = BmpGetAreaPoint(circleBorder,
		centerPoint, bmp.GetWidth(), bmp.GetHeight());	
	BmpDrawPoints(bmp, areaPoints, rgb);

	centerPoint = {100, 100};
	radius = 70;	
	circleBorder = BmpGetCirclePoint(centerPoint, radius);
	std::vector<TPoint> mouthBorder;
	for (U32 i = 0; i < circleBorder.size(); ++i) {
		if (circleBorder[i].y <= 100) {
			mouthBorder.push_back(circleBorder[i]);
		}
	}

	centerPoint = {100, 100};
	radius = 65;	
	circleBorder = BmpGetCirclePoint(centerPoint, radius);
	for (U32 i = 0; i < circleBorder.size(); ++i) {
		if (circleBorder[i].y <= 100) {
			mouthBorder.push_back(circleBorder[i]);
		}
	}

	std::vector<TPoint> linePoint = BmpGetLinePoint({30, 100}, {35, 100});
	mouthBorder.insert(mouthBorder.end(), 
		linePoint.begin(), linePoint.end());

	linePoint = BmpGetLinePoint({170, 100}, {165, 100});
	mouthBorder.insert(mouthBorder.end(), 
		linePoint.begin(), linePoint.end());

	BmpDrawPoints(bmp, mouthBorder, rgb);

	areaPoints = BmpGetAreaPoint(mouthBorder,
		{100, 32}, bmp.GetWidth(), bmp.GetHeight());	

	BmpDrawPoints(bmp, areaPoints, rgb);

	bmp.Save(DIR "draw_smile.bmp");
}

