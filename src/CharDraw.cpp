

/**************************************************************************
* *
* * FILE NAME : CharDraw.cpp
* *
* * DESCRIPTION : CharDraw cpp file
* *
* * DATE : 2024-3-25
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include <map>
#include "BmpCore.h"


//******************************************************************************
// macro
//******************************************************************************

#define DIR_CHAR "./Char/"


//******************************************************************************
// declaration of function
//******************************************************************************

static void Trans(char* pSrc, char* pDst);
static void BmpTransImg(CBmp& bmp, U32 width, U32 height, 
	U32 imgWidth, U32 imgHeight, std::vector<std::string> imgNames);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("arg error!\n");
		return -1;
	}
	printf("%s	%s\n", argv[1], argv[2]);
	Trans(argv[1], argv[2]);
	// Trans(DIR_SRC "raw.bmp", DIR_DST "raw.bmp");
	return 0;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void Trans(char* pSrc, char* pDst) {
	CBmp bmp;
	bmp.Load(pSrc);
	std::vector<std::string> imgNames;

	imgNames.push_back(DIR_CHAR "0.bmp");
	imgNames.push_back(DIR_CHAR "1.bmp");
	imgNames.push_back(DIR_CHAR "2.bmp");
	imgNames.push_back(DIR_CHAR "3.bmp");
	imgNames.push_back(DIR_CHAR "4.bmp");

	BmpTransImg(bmp, 3840, 2160, 20, 20, imgNames);
	bmp.Save(pDst);
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static void BmpTransImg(CBmp& bmp, U32 width, U32 height, 
	U32 imgWidth, U32 imgHeight, std::vector<std::string> imgNames) {
	std::map<U32, CBmp> avgColors2Img;
	for (int i = 0; i < imgNames.size(); ++i) {
		CBmp img;
		img.Load(imgNames[i]);
		BmpResize(img, imgWidth, imgHeight);
		BmpTransNoColor(img);
		avgColors2Img[BmpCalcAvgColor(img)] = img;
	}

	std::vector<CBmp> imgs;
	for (auto iter = avgColors2Img.begin(); iter != avgColors2Img.end(); ++iter) {
		imgs.push_back(iter->second);
	}

	BmpTransNoColor(bmp);
	BmpResize(bmp, width, height);
	for (U32 i = 0; i < height / imgHeight; ++i) {
		for (U32 j = 0; j < width / imgWidth; ++j) {
			TPoint curPoint;
			curPoint.x = j * imgWidth;
			curPoint.y = i * imgHeight;
			CBmp curBmp = BmpCopy(bmp, curPoint, imgWidth, imgHeight);
			U32 curAvgColor = BmpCalcAvgColor(curBmp);
			U32 imgIndex = (double)curAvgColor / 0xFF * imgs.size();

			BmpPaste(bmp, imgs[imgIndex], curPoint);
		}
	}
}
