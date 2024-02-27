

/**************************************************************************
* *
* * FILE NAME : Common.h
* *
* * DESCRIPTION : Common h file
* *
* * DATE : 2024-2-16
* *
* * AUTHOR : TaskRunner
* *
* * MODIFY :
* *
**************************************************************************/


#pragma once


#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>


//******************************************************************************
// definition of type
//******************************************************************************

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long long U64;

typedef signed char S8;
typedef signed short S16;
typedef signed int S32;
typedef signed long long S64;


//******************************************************************************
// declaration of function
//******************************************************************************

int GetRandom();
int GetRandomMod(double num, int modPercent);
int GetRandomInt(int num);
double GetRandomDouble(double num);

