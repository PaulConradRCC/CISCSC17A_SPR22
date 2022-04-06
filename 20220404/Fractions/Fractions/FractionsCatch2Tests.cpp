// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Fractions.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

TEST_CASE( "Test parameterless constructor Fractions()..." ) {
    REQUIRE( (Fractions().getNumerator() == 0 && Fractions().getDenominator() == 1) );
}

TEST_CASE( "Test two integer constructor Fractions(int n, int d)..." ) {
    REQUIRE( (Fractions(1,3).getNumerator() == 1 && Fractions(1,3).getDenominator() == 3) );
}

TEST_CASE( "Test two integer constructor Fractions(int n, int d) with reducing fraction..." ) {
    Fractions inst1 = Fractions(2,4); // should be reduced to 1/2
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 2) );
}

TEST_CASE( "Test copy constructor Fractions()..." ) {
    Fractions inst1 = Fractions(3,8);
    Fractions inst2 = Fractions(inst1); // create a copy of inst1
    
    REQUIRE( (inst2.getNumerator() == 3 && inst2.getDenominator() == 8) );
}

TEST_CASE( "Test setNumerator - test #1" )
{
    Fractions inst1 = Fractions(1,4); // inst1 initially 1/4
    inst1.setNumerator(3); // now inst1 should be 3/4
    
    REQUIRE( (inst1.getNumerator() == 3 && inst1.getDenominator() == 4) );
}

TEST_CASE( "Test setNumerator - test #2" )
{
    Fractions inst1 = Fractions(1,4); // inst1 initially 1/4
    inst1.setNumerator(2); // now inst1 should be 1/2 with reducing fraction
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 2) );
}

TEST_CASE( "Test setDenominator - test #1" )
{
    Fractions inst1 = Fractions(1,4); // inst1 initially 1/4
    inst1.setDenominator(3); // now inst1 should be 1/3
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 3) );
}

TEST_CASE( "Test setDenominator - test #2" )
{
    Fractions inst1 = Fractions(2,3); // inst1 initially 2/3
    inst1.setDenominator(4); // now inst1 should be 1/2 with reducing fraction
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 2) );
}

TEST_CASE( "Test setDenominator - test #3 (attempt to set to zero)" )
{
    Fractions inst1 = Fractions(2,3); // inst1 initially 2/3
    bool result = inst1.setDenominator(0); // result should be false
    
    REQUIRE( (result == false) );
}

TEST_CASE( "Test add fractions 1/5 + 3/5 = 4/5 with add method..." ) {
    Fractions inst1 = Fractions(1,5);
    Fractions inst2 = inst1.add(Fractions(3,5)); 
    
    REQUIRE( (inst2.getNumerator() == 4 && inst2.getDenominator() == 5) );
}

TEST_CASE( "Test add fractions 1/5 + 3/5 = 4/5 with overloaded operator+..." ) {
    Fractions inst1 = Fractions(1,5);
    Fractions inst2 = inst1 + Fractions(3,5); 
    
    REQUIRE( (inst2.getNumerator() == 4 && inst2.getDenominator() == 5) );
}

TEST_CASE( "Test add fractions 1/8 + 3/8 = 1/2 with add method (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(1,8);
    Fractions inst2 = inst1.add(Fractions(3,8)); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 2) );
}

TEST_CASE( "Test add fractions 1/8 + 3/8 = 1/2 with overloaded operator+ (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(1,8);
    Fractions inst2 = inst1 + Fractions(3,8); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 2) );
}

TEST_CASE( "Test subtract fractions 3/5 - 1/5 = 2/5 with subtract method..." ) {
    Fractions inst1 = Fractions(3,5);
    Fractions inst2 = inst1.subtract(Fractions(1,5)); 
    
    REQUIRE( (inst2.getNumerator() == 2 && inst2.getDenominator() == 5) );
}

TEST_CASE( "Test subtract fractions 3/5 - 1/5 = 2/5 with overloaded operator-..." ) {
    Fractions inst1 = Fractions(3,5);
    Fractions inst2 = inst1 - Fractions(1,5); 
    
    REQUIRE( (inst2.getNumerator() == 2 && inst2.getDenominator() == 5) );
}

TEST_CASE( "Test subtract fractions 3/8 - 1/8 = 1/4 with subtract method (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,8);
    Fractions inst2 = inst1.subtract(Fractions(1,8)); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test subtract fractions 3/8 - 1/8 = 1/4 with overloaded operator- (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,8);
    Fractions inst2 = inst1 - Fractions(1,8); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test multiply fractions 1/5 * 3/5 = 3/25 with multiply method..." ) {
    Fractions inst1 = Fractions(1,5);
    Fractions inst2 = inst1.multiply(Fractions(3,5)); 
    
    REQUIRE( (inst2.getNumerator() == 3 && inst2.getDenominator() == 25) );
}

TEST_CASE( "Test multiply fractions 1/5 * 3/5 = 3/25 with overloaded operator*..." ) {
    Fractions inst1 = Fractions(1,5);
    Fractions inst2 = inst1 * Fractions(3,5); 
    
    REQUIRE( (inst2.getNumerator() == 3 && inst2.getDenominator() == 25) );
}

TEST_CASE( "Test multiply fractions 1/3 * 3/4 = 1/4 with multiply method (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(1,3);
    Fractions inst2 = inst1.multiply(Fractions(3,4)); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test multiply fractions 1/3 * 3/4 = 1/4 with overloaded operator* (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(1,3);
    Fractions inst2 = inst1 * Fractions(3,4); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test divide fractions 3/5 / 1/5 = 3/1 with divide method..." ) {
    Fractions inst1 = Fractions(3,5);
    Fractions inst2 = inst1.divide(Fractions(1,5)); 
    
    REQUIRE( (inst2.getNumerator() == 3 && inst2.getDenominator() == 1) );
}

TEST_CASE( "Test divide fractions 3/5 / 1/5 = 3/1 with overloaded operator/..." ) {
    Fractions inst1 = Fractions(3,5);
    Fractions inst2 = inst1 / Fractions(1,5); 
    
    REQUIRE( (inst2.getNumerator() == 3 && inst2.getDenominator() == 1) );
}

TEST_CASE( "Test divide fractions 3/16 / 3/4 = 1/4 with divide method (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,16);
    Fractions inst2 = inst1.divide(Fractions(3,4)); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test divide fractions 3/16 / 3/4 = 1/4 with overloaded operator/ (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,16);
    Fractions inst2 = inst1 / Fractions(3,4); 
    
    REQUIRE( (inst2.getNumerator() == 1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test unary- fractions 3/16 = -3/16..." ) {
    Fractions inst1 = Fractions(3,16);
    Fractions inst2 = -inst1;
    
    REQUIRE( (inst2.getNumerator() == -3 && inst2.getDenominator() == 16) );
}

TEST_CASE( "Test unary- fractions 4/16 = -1/4 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(4,16);
    Fractions inst2 = -inst1;
    
    REQUIRE( (inst2.getNumerator() == -1 && inst2.getDenominator() == 4) );
}

TEST_CASE( "Test += fractions..." ) {
    Fractions inst1 = Fractions(3,16);
    inst1 += Fractions(1,4); // inst1 = 3/16 + 1/4 = 7/16
    
    REQUIRE( (inst1.getNumerator() == 7 && inst1.getDenominator() == 16) );
}

TEST_CASE( "Test += fractions (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,16);
    inst1 += Fractions(1,16); // inst1 = 3/16 + 1/16 = 1/4
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 4) );
}

TEST_CASE( "Test -= fractions..." ) {
    Fractions inst1 = Fractions(5,16);
    inst1 -= Fractions(1,4); // inst1 = 5/16 - 1/4 = 1/16
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 16) );
}

TEST_CASE( "Test -= fractions (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    inst1 -= Fractions(1,16); // inst1 = 5/16 - 1/16 = 1/4
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 4) );
}

TEST_CASE( "Test *= fractions..." ) {
    Fractions inst1 = Fractions(5,16);
    inst1 *= Fractions(1,4); // inst1 = 5/16 * 1/4 = 5/64
    
    REQUIRE( (inst1.getNumerator() == 5 && inst1.getDenominator() == 64) );
}

TEST_CASE( "Test *= fractions (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,4);
    inst1 *= Fractions(2,3); // inst1 = 3/4 * 2/3 = 1/2
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 2) );
}

TEST_CASE( "Test /= fractions..." ) {
    Fractions inst1 = Fractions(5,16);
    inst1 /= Fractions(1,3); // inst1 = 5/16 / 1/3 = 15/16
    
    REQUIRE( (inst1.getNumerator() == 15 && inst1.getDenominator() == 16) );
}

TEST_CASE( "Test /= fractions (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(3,4);
    inst1 /= Fractions(3,2); // inst1 = 3/4 / 3/2 = 1/2
    
    REQUIRE( (inst1.getNumerator() == 1 && inst1.getDenominator() == 2) );
}

TEST_CASE( "Test == fractions..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst1 == inst2) == true );
}

TEST_CASE( "Test == fractions (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(15,48);
    
    REQUIRE( (inst1 == inst2) == true );
}

TEST_CASE( "Test != fractions..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(3,16);
    
    REQUIRE( (inst1 != inst2) == true );
}

TEST_CASE( "Test != fractions (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(15,30);
    
    REQUIRE( (inst1 != inst2) == true );
}

TEST_CASE( "Test >= fractions #1..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst1 >= inst2) == true );
}

TEST_CASE( "Test >= fractions #2 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(15,48);
    
    REQUIRE( (inst1 >= inst2) == true );
}

TEST_CASE( "Test >= fractions #3..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst2 >= inst1) == true );
}

TEST_CASE( "Test >= fractions #4 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(15,48);
    
    REQUIRE( (inst2 >= inst1) == true );
}

TEST_CASE( "Test > fractions #1..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(3,16);
    
    REQUIRE( (inst1 > inst2) == true );
}

TEST_CASE( "Test > fractions #2 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(9,48);
    
    REQUIRE( (inst1 > inst2) == true );
}

TEST_CASE( "Test > fractions #3..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(3,16);
    
    REQUIRE( (inst2 > inst1) == false );
}

TEST_CASE( "Test > fractions #4 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(9,48);
    
    REQUIRE( (inst2 > inst1) == false );
}




TEST_CASE( "Test <= fractions #1..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst1 <= inst2) == true );
}

TEST_CASE( "Test <= fractions #2 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(15,48);
    
    REQUIRE( (inst1 <= inst2) == true );
}

TEST_CASE( "Test <= fractions #3..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst2 <= inst1) == true );
}

TEST_CASE( "Test <= fractions #4 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(5,16);
    Fractions inst2 = Fractions(15,48);
    
    REQUIRE( (inst2 <= inst1) == true );
}

TEST_CASE( "Test < fractions #1..." ) {
    Fractions inst1 = Fractions(3,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst1 < inst2) == true );
}

TEST_CASE( "Test < fractions #2 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(9,48);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst1 < inst2) == true );
}

TEST_CASE( "Test < fractions #3..." ) {
    Fractions inst1 = Fractions(3,16);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst2 < inst1) == false );
}

TEST_CASE( "Test < fractions #4 (ensure reducing results)..." ) {
    Fractions inst1 = Fractions(9,48);
    Fractions inst2 = Fractions(5,16);
    
    REQUIRE( (inst2 < inst1) == false );
}

TEST_CASE( "Test << ..." )
{
    fstream ofile;
    ofile.open("test.frc",ios::out);
    if (ofile)
    {
        Fractions f = Fractions(3,4);
        ofile << f << "\n";
        ofile.close();
        
        fstream ifile;
        string line;
        ifile.open("test.frc",ios::in);
        getline(ifile,line,'\n');
        ifile.close();
                
        REQUIRE( (line == "3 / 4") );
    }
        
}

TEST_CASE( "Test >> ..." )
{
    fstream ofile;
    ofile.open("test.frc",ios::out);
    if (ofile)
    {
        ofile << "1" << " " << 7 << "\n"; // write 1 7 to test file
        ofile.close();
        
        fstream ifile;
        Fractions f;
        ifile.open("test.frc",ios::in);
        ifile >> f;
        ifile.close();
                
        REQUIRE( (f == Fractions(1,7)) );
    }
        
}

TEST_CASE( "Test >> with zero denominator..." )
{
    fstream ofile;
    ofile.open("test.frc",ios::out);
    if (ofile)
    {
        ofile << 1 << " " << 0 << "\n"; // write 1 0 to test file
        ofile.close();
        
        fstream ifile;
        Fractions f;
        ifile.open("test.frc",ios::in);
        ifile >> f;
        ifile.close();
                
        REQUIRE( (ifile.good() == false) );
    }
        
}