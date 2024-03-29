

/**************************************************************************
* *
* * FILE NAME : BmpTools.h
* *
* * DESCRIPTION : BmpTools h file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#ifndef __BMP_TOOLS_H__
#define __BMP_TOOLS_H__


#include "Bmp.h"


//******************************************************************************
// declaration of function
//******************************************************************************

void BmpResize(CBmp& bmp, U32 width, U32 height);

void BmpTransNoColor(CBmp& bmp);
void BmpTransBlackWhite(CBmp& bmp);
void BmpReverseColor(CBmp& bmp);
void BmpAdjustBr(CBmp& bmp, U8 adjustVal, bool isAdd);


#endif // __BMP_TOOLS_H__

