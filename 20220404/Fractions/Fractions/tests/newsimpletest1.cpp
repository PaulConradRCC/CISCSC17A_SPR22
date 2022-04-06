// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "./Fractions.h"
#include "./catch.hpp"

TEST_CASE( "Test parameterless constructor Fractions()...", "[single-file]" ) {
    REQUIRE( Fractions().getNumerator() == 0 );
    REQUIRE( Fractions().getDenominator() == 1);
}

TEST_CASE( "Test two integer constructor Fractions(int n, int d)...", "[single-file]" ) {
    REQUIRE( Fractions(1,3).getNumerator() == 1 );
    REQUIRE( Fractions(1,3).getDenominator() == 3);
}

TEST_CASE( "Test two integer constructor Fractions(int n, int d) with reducing fraction...", "[single-file]" ) {
    Fractions inst1 = Fractions(2,4); // should be reduced to 1/2
    REQUIRE( inst1.getNumerator() == 1 );
    REQUIRE( inst1.getDenominator() == 2 );
}

TEST_CASE( "Test copy constructor Fractions()...", "[single-file]" ) {
    Fractions inst1 = Fractions(3,8);
    Fractions inst2 = Fractions(inst1); // create a copy of inst1
    
    REQUIRE( inst2.getNumerator() == 3 );
    REQUIRE( inst2.getDenominator() == 8);
}

