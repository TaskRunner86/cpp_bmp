

/**************************************************************************
* *
* * FILE NAME : Bmp.h
* *
* * DESCRIPTION : Bmp h file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#ifndef __BMP_H__
#define __BMP_H__


#include <string>
#include "Common.h"


//******************************************************************************
// definition of type
//******************************************************************************

#pragma pack(1)

typedef struct TagBitmapFileHdr {
	// 位图文件类型 必须是0x4D42 即字符串“BM”
	U16 bfType;
	// 位图文件大小 包括这14个字节
	U32 bfSize;
	U16 bfReserved1;
	U16 bfReserved2;
	// 偏移字节数
	U32 bfOffBits;
} TBitmapFileHdr;

typedef struct TagBitmapInfoHdr{
	U32 biSize;
	// 位图宽度
	U32 biWidth;
	// 位图高度
	U32 biHeight;
	U16 biPlanes;
	// 每像素用的位数 1(黑白图) 4(16色) 8(256色) 24(真彩色)
	U16 biBitCount;
	U32 biCompression;
	U32 biSizeImage;
	U32 biXPelsPerMeter;
	U32 biYPelsPerMeter;
	U32 biClrUsed;
	U32 biClrImportant;
} TBitmapInfoHdr;

typedef struct TagRGB {
	U8 blue;
	U8 green;
	U8 red;
} TRGB;

#pragma pack()


//******************************************************************************
// definition of class
//******************************************************************************

//------------------------------------------------------------------------------
// 只支持真彩 bmp 图片
//------------------------------------------------------------------------------
class CBmp {
public:
	CBmp() {
		m_lineByte = 0;
		m_pBmpBuf = nullptr;
	}

	CBmp(const CBmp& bmp) {
		m_lineByte = 0;
		m_pBmpBuf = nullptr;
		Init(bmp.GetWidth(), bmp.GetHeight());
		memcpy(m_pBmpBuf, bmp.m_pBmpBuf, bmp.m_lineByte * bmp.GetHeight());
	}

	~CBmp() {
		delete[] m_pBmpBuf;
	}

	CBmp& operator = (const CBmp& bmp) {
		Init(bmp.GetWidth(), bmp.GetHeight());
		memcpy(m_pBmpBuf, bmp.m_pBmpBuf, bmp.m_lineByte * bmp.GetHeight());
		return *this;
	}
	
	bool Load(std::string filename);
	bool Save(std::string filename);

	void Init(U32 width, U32 height);

	TRGB* GetRGB(U32 widthPos, U32 heightPos) const {
		if (m_pBmpBuf == nullptr) {
			return nullptr;
		}

		if (GetWidth() <= widthPos) {
			return nullptr;
		}

		if (GetHeight() <= heightPos) {
			return nullptr;
		}

		U8* pLineBuf = m_pBmpBuf + heightPos * m_lineByte;
		TRGB* pRGB = (TRGB*)(pLineBuf + sizeof(TRGB) * widthPos);
		return pRGB;
	}

	U32 GetWidth() const {
		return m_infoHdr.biWidth;
	}

	U32 GetHeight() const {
		return m_infoHdr.biHeight;
	}

private:
	TBitmapFileHdr m_fileHdr;
	TBitmapInfoHdr m_infoHdr;
	U32 m_lineByte;
	U8* m_pBmpBuf;
};


#endif // __BMP_H__

