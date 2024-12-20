

/**************************************************************************
* *
* * FILE NAME : HsvTools.h
* *
* * DESCRIPTION : HsvTools h file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#ifndef __HSV_TOOLS_H__
#define __HSV_TOOLS_H__


#include "Bmp.h"


//******************************************************************************
// definition of type
//******************************************************************************

// 定义HSV结构体
typedef struct TagHSV {
	bool operator < (const TagHSV& hsv) const{
		if (this->h != hsv.h) {
			return this->h < hsv.h;
		}
		if (this->s != hsv.s) {
			return this->s < hsv.s;
		}		
		return this->v < hsv.v;
	}

	bool operator == (const TagHSV& hsv) const{
		if (this->h == hsv.h && this->s == hsv.s &&
			this->v == hsv.v) {
			return true;
		}
		return false;
	}	

	// 0 - 359
	U32 h;
	// 0 - 100
	U32 s;
	// 0 - 100
	U32 v;
} THSV;


//******************************************************************************
// declaration of function
//******************************************************************************

void Rgb2Hsv(const TRGB& rgb, THSV& hsv);


#endif // __HSV_TOOLS_H__

