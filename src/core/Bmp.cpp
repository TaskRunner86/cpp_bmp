

/**************************************************************************
* *
* * FILE NAME : Bmp.cpp
* *
* * DESCRIPTION : Bmp cpp file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "Bmp.h"
#include<fstream>


//******************************************************************************
// macro
//******************************************************************************

#define BF_TYPE_VAL (0x4D42)
#define BF_OFFBITS_VAL (54)

#define BI_SIZE_VAL (40)
#define BI_PLANTES_VAL (1)
#define BI_BITCOUNT_VAL (24)
#define BI_BICOMPRESSION_VAL (0)
#define BI_BICLRUSED_VAL (0)
#define BI_BICLRIMPORTANT_VAL (0)


//******************************************************************************
// declaration of function
//******************************************************************************

static U32 CalcLineByte(U32 width, U16 bitCount);


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
// load bmp from file
//------------------------------------------------------------------------------
bool CBmp::Load(std::string filename) {
	std::ifstream bmpFile(filename, std::ios::binary);
	TBitmapFileHdr fileHdr;

	bmpFile.read((char*)&fileHdr, sizeof(TBitmapFileHdr));
	if (fileHdr.bfType != BF_TYPE_VAL) {
		printf("bf type is not supported!\n");
		return false;
	}
	
	memcpy((char*)&m_fileHdr, (char*)&fileHdr, sizeof(TBitmapFileHdr));
	bmpFile.read((char*)&m_infoHdr, sizeof(TBitmapInfoHdr));
	if (m_infoHdr.biBitCount != BI_BITCOUNT_VAL) {
		printf("biBitCount is not supported!\n");
		return false;
	}

	m_lineByte = CalcLineByte(m_infoHdr.biWidth, m_infoHdr.biBitCount);

	delete[] m_pBmpBuf;
	m_pBmpBuf = new U8[m_lineByte * m_infoHdr.biHeight];

	bmpFile.read((char*)m_pBmpBuf, m_lineByte * m_infoHdr.biHeight);
	bmpFile.close();

	return true;
}


//------------------------------------------------------------------------------
// save bmp to file
//------------------------------------------------------------------------------
bool CBmp::Save(std::string filename) {
	if (m_pBmpBuf == nullptr) {
		printf("m_pBmpBuf is null\n");
		return false;
	}

	std::ofstream bmpFile(filename, std::ios::binary);

	bmpFile.write((char*)&m_fileHdr, sizeof(TBitmapFileHdr));
	bmpFile.write((char*)&m_infoHdr, sizeof(TBitmapInfoHdr));

	bmpFile.write((char*)m_pBmpBuf, m_lineByte * m_infoHdr.biHeight);
	bmpFile.close();
	return true;
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void CBmp::Init(U32 width, U32 height) {
	const U32 colorTableSize = 0;
	m_lineByte = CalcLineByte(width, BI_BITCOUNT_VAL);

	m_fileHdr.bfType = BF_TYPE_VAL;
	m_fileHdr.bfSize = sizeof(TBitmapFileHdr) + sizeof(TBitmapInfoHdr) + colorTableSize + m_lineByte * height;
	m_fileHdr.bfReserved1 = 0;
	m_fileHdr.bfReserved2 = 0;
	m_fileHdr.bfOffBits = BF_OFFBITS_VAL + colorTableSize;

	m_infoHdr.biSize = BI_SIZE_VAL;
	m_infoHdr.biWidth = width;
	m_infoHdr.biHeight = height;
	m_infoHdr.biXPelsPerMeter = 0;
	m_infoHdr.biYPelsPerMeter = 0;
	m_infoHdr.biPlanes = BI_PLANTES_VAL;
	m_infoHdr.biBitCount = BI_BITCOUNT_VAL;
	m_infoHdr.biCompression = BI_BICOMPRESSION_VAL;
	m_infoHdr.biSizeImage = m_lineByte * height;
	m_infoHdr.biClrUsed = BI_BICLRUSED_VAL;
	m_infoHdr.biClrImportant = BI_BICLRIMPORTANT_VAL;

	delete[] m_pBmpBuf;
	m_pBmpBuf = new U8[m_lineByte * m_infoHdr.biHeight];
	memset(m_pBmpBuf, 0, m_lineByte * m_infoHdr.biHeight);
}


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
static U32 CalcLineByte(U32 width, U16 bitCount) {
	U32 ret = 0;
	// 数据每行字节数为4的倍数
	ret = ((width * bitCount / 8 + 3) / 4 * 4);
	return ret;
}

