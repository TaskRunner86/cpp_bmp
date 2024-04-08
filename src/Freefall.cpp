

/**************************************************************************
* *
* * FILE NAME : Freefall.cpp
* *
* * DESCRIPTION : Freefall cpp file
* *
* * DATE : 2024-3-25
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

#define DIR "../bmp/freefall/"

#define GRA (10 * 5)
#define DELTA_TIME (0.1)


//******************************************************************************
// declaration of function
//******************************************************************************

static void Freefall();
static void DrawFrame();


//******************************************************************************
// definition of global variable
//******************************************************************************

static double g_height = 300;
static double g_v = 0;
static U32 g_photoId = 1;


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main() {
	printf("start\n");
	Freefall();
	printf("end\n");	
	return 0;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void Freefall() {
	for (U32 i = 0; i < 200; ++i) {
		DrawFrame();
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void DrawFrame() {
	CBmp bmp;
	bmp.Init(200, 400);

	CBmp ballBmp;
	ballBmp.Load(DIR "ball.bmp");

	CBmp groundBmp;
	groundBmp.Load(DIR "ground.bmp");

	BmpPaste(bmp, groundBmp, {55, 20});

	double deltaHeight = g_v * DELTA_TIME;

	if (0 < (g_height - deltaHeight)) {
		g_v += (GRA * DELTA_TIME);
		g_height -= deltaHeight;
	} else {
		g_v = (- g_v * 0.9);
		g_height = 0;
	}

	TPoint ballPoint = {95, 25};
	ballPoint.y += g_height;
	BmpPaste(bmp, ballBmp, ballPoint);

	char bmpName[50];
	snprintf(bmpName, sizeof(bmpName), DIR "%05d.bmp", g_photoId);
	bmp.Save(bmpName);
	++g_photoId;
}

