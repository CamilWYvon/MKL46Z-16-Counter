//**********************************************************************************************************************
// FILE: global.h
//
// DESCRIPTION
// Use typedef for different size integers. Includes MKL46Z4.h. Almost every source code file we write will need to
// include global.h.
//
// AUTHOR
// Kevin R. Burger (burgerk@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
// Web: http://www.devlang.com
//**********************************************************************************************************************
#ifndef GLOBAL_H_
#define GLOBAL_H_

typedef signed char 		int8_t;
typedef short int   		int16_t;
typedef long int    		int32_t;

typedef unsigned char		uint8_t;
typedef unsigned short int  uint16_t;
typedef unsigned long int   uint32_t;

#include "mkl46z.h"

#endif
