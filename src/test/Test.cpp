

/**************************************************************************
* *
* * FILE NAME : Test.cpp
* *
* * DESCRIPTION : Test cpp file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#include "BmpSuite.h"
#include "BmpDrawPointSuite.h"
#include "BmpDrawLineSuite.h"
#include "BmpDrawPolygonSuite.h"
#include "BmpDrawCircleSuite.h"
#include "BmpDrawAreaSuite.h"
#include "BmpCopySuite.h"
#include "BmpRotateSuite.h"
#include "BmpResizeSuite.h"
#include "BmpTransNoColorSuite.h"
#include "BmpAdjustBrSuite.h"


//******************************************************************************
// definition of function
//******************************************************************************

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	BmpSuite();
	BmpDrawPointSuite();
	BmpDrawLineSuite();
	BmpDrawPolygonSuite();
	BmpDrawCircleSuite();
	BmpDrawAreaSuite();
	BmpCopySuite();
	BmpRotateSuite();
	BmpResizeSuite();
	BmpTransNoColorSuite();
	BmpAdjustBrSuite();
	return 0;
}

