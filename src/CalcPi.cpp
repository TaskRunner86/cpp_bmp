

/**************************************************************************
* *
* * FILE NAME : CalcPi.cpp
* *
* * DESCRIPTION : CalcPi cpp file
* *
* * DATE : 2024-3-14
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

#define PI (3.1415926)


//******************************************************************************
// declaration of function
//******************************************************************************

static void CalcPi(U32 radius);
static double CalcPiAccuracy(double val);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	for (U32 i = 1; i < 10; ++i) {
		CalcPi(i);
	}

	for (U32 i = 10; i < 100; i += 10) {
		CalcPi(i);
	}

	for (U32 i = 100; i < 1000; i += 100) {
		CalcPi(i);
	}	
	return 0;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void CalcPi(U32 radius) {
	TPoint centerPoint = {1000, 1000};
	std::vector<TPoint> circleBorder = BmpGetCirclePoint(centerPoint, radius);
	std::vector<TPoint> areaPoints = BmpGetAreaPoint(circleBorder, centerPoint, 2001, 2001);

	double pi = areaPoints.size() / (radius - 0.5) / (radius - 0.5);
	// double pi = (double)areaPoints.size() / radius / radius;

	printf("radius = %d    PI = %f    accuracy = %f%\n", radius, pi, CalcPiAccuracy(pi));
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static double CalcPiAccuracy(double val) {
	double ret = 0;
	if (val < PI) {
		ret = (val / PI) * 100;
	} else {
		ret = ((PI - (val - PI)) / PI) * 100;
	}
	return ret;
}

