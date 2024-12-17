

/**************************************************************************
* *
* * FILE NAME : HsvTools.cpp
* *
* * DESCRIPTION : HsvTools cpp file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "HsvTools.h"
#include <algorithm>


//******************************************************************************
// declaration of function
//******************************************************************************

static bool IsEqual(double val1, double val2);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
// RGB 转换为 HSV
//------------------------------------------------------------------------------
void Rgb2Hsv(const TRGB& rgb, THSV& hsv) {
	double r, g, b;
	double h, s, v;
	double min, max;
	double delta;

	r = rgb.red;
	g = rgb.green;
	b = rgb.blue;
	max = std::max({r, g, b});
	min = std::min({r, g, b});

	v = max;
	delta = max - min;

	if (IsEqual(max, 0)) {
		s = 0.0;
	} else {
		s = delta / max;
	}

	if (IsEqual(max, min)) {
		h = 0.0;
	} else {
		if (IsEqual(r, max) && b <= g) {
			h = 60 * (g - b) / delta + 0;
		} else if (IsEqual(r, max) && g < b) {
			h = 60 * (g - b) / delta + 360;
		} else if (IsEqual(g, max)) {
			h = 60 * (b - r) / delta + 120;
		} else if (IsEqual(b, max)) {
			h = 60 * (r - g) / delta + 240;
		}
	}

	hsv.h = round(h);
	hsv.h = (hsv.h > 359) ? (hsv.h - 360) : hsv.h;
	hsv.h = (hsv.h < 0) ? (hsv.h + 360) : hsv.h;
	hsv.s = s;
	hsv.v = v;
}


//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
static bool IsEqual(double val1, double val2) {
	return fabs(val1 - val2) < 0.001;
}

