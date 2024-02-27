

/**************************************************************************
* *
* * FILE NAME : BmpTools.cpp
* *
* * DESCRIPTION : BmpTools cpp file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpTools.h"
#include "BmpDrawTools.h"


//******************************************************************************
// macro
//******************************************************************************

#define BLACK_WHITE_ADJUST (0.80)


//******************************************************************************
// declaration of function
//******************************************************************************

static U32 BmpCalcAvgColor(const CBmp& bmp);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpResize(CBmp& bmp, U32 width, U32 height) {
	CBmp newBmp;
	newBmp.Init(width, height);

	for (U32 i = 0; i < newBmp.GetWidth(); ++i) {
		U32 widthPos = i * bmp.GetWidth() / newBmp.GetWidth();
		for (U32 j = 0; j < newBmp.GetHeight(); ++j) {
			U32 heightPos = j * bmp.GetHeight() / newBmp.GetHeight();
			TRGB* pRGB = bmp.GetRGB(widthPos, heightPos);
			TRGB* pNewRGB = newBmp.GetRGB(i, j);
			pNewRGB->red = pRGB->red;
			pNewRGB->green = pRGB->green;
			pNewRGB->blue = pRGB->blue;
		}
	}
	bmp = newBmp;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpTransNoColor(CBmp& bmp) {
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			U32 avgColor = (pRGB->red + pRGB->green + pRGB->blue) / 3;
			
			pRGB->red = avgColor;
			pRGB->green = avgColor;
			pRGB->blue = avgColor;
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpTransBlackWhite(CBmp& bmp) {
	U32 avgColorTotal = BmpCalcAvgColor(bmp);
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			U32 avgColor = (pRGB->red + pRGB->green + pRGB->blue) / 3;

			if (avgColor <= (avgColorTotal * BLACK_WHITE_ADJUST)) {
				pRGB->red = 0;
				pRGB->green = 0;
				pRGB->blue = 0;
			} else {
				pRGB->red = 0xFF;
				pRGB->green = 0xFF;
				pRGB->blue = 0xFF;
			}
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpReverseColor(CBmp& bmp) {
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			pRGB->red = 0xFF - pRGB->red;
			pRGB->green = 0xFF - pRGB->green;
			pRGB->blue = 0xFF - pRGB->blue;
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BmpAdjustBr(CBmp& bmp, U8 adjustVal, bool isAdd) {
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			if (isAdd) {
				if (((U32)pRGB->red + adjustVal) < 0xFF) {
					pRGB->red += adjustVal;
				} else {
					pRGB->red = 0xFF;
				}

				if (((U32)pRGB->green + adjustVal) < 0xFF) {
					pRGB->green += adjustVal;
				} else {
					pRGB->green = 0xFF;
				}

				if (((U32)pRGB->blue + adjustVal) < 0xFF) {
					pRGB->blue += adjustVal;
				} else {
					pRGB->blue = 0xFF;
				}
			} else {
				if (0x00 < ((S32)pRGB->red - adjustVal)) {
					pRGB->red -= adjustVal;
				} else {
					pRGB->red = 0x00;
				}

				if (0x00 < ((S32)pRGB->green - adjustVal)) {
					pRGB->green -= adjustVal;
				} else {
					pRGB->green = 0x00;
				}

				if (0x00 < ((S32)pRGB->blue - adjustVal)) {
					pRGB->blue -= adjustVal;
				} else {
					pRGB->blue = 0x00;
				}
			}
		}
	}
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static U32 BmpCalcAvgColor(const CBmp& bmp) {
	U64 totalColor = 0;
	for (U32 i = 0; i < bmp.GetWidth(); ++i) {
		for (U32 j = 0; j < bmp.GetHeight(); ++j) {
			TRGB* pRGB = bmp.GetRGB(i, j);
			totalColor += pRGB->red;
			totalColor += pRGB->green;
			totalColor += pRGB->blue;
		}
	}
	U32 avgColor = totalColor / bmp.GetWidth() / bmp.GetWidth() / 3;
	return avgColor;
}

