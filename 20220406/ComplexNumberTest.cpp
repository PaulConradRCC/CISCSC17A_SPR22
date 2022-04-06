// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "CComplex.h"

TEST_CASE( "Check complex number addition #1" )
{
	CComplex a = CComplex(3,4);
	CComplex b = CComplex(5,6);
	CComplex c = a + b;
	
	REQUIRE ( (c.getReal() == 8 && c.getImaginary() == 10) );
}