#include "Fractions.h"
#include <iostream>
using namespace std;

const bool VERBOSE = false; // if true, show debugger/logging info, false does not.

Fractions::Fractions() {
    if (VERBOSE) cout << "Inside Fractions::Fractions()...\n";
    this->numerator = 0;
    this->denominator = 1;
}

Fractions::Fractions(int n, int d) {    
    if (VERBOSE) cout << "Inside Fractions::Fractions(" << n << ", " << d <<")...\n";
    this->numerator = n;
    this->setDenominator(d);   
}

Fractions::Fractions(const Fractions& orig) {
    if (VERBOSE) {
        cout << "Inside Fractions::Fractions(const Fractions& orig)...\n";
        cout << "With orig.numerator=" << orig.numerator << "\n";
        cout << "     orig.denominator=" << orig.denominator << "\n";
    }
    this->numerator = orig.numerator;
    this->denominator = orig.denominator;
}

Fractions::~Fractions() {
    if (VERBOSE) cout << "Inside Fractions::~Fractions()...\n";    
}

int Fractions::getNumerator() const {
    return this->numerator;
}

int Fractions::getDenominator() const {
    return this->denominator;
}

double Fractions::getValue() const {
    return (double)this->numerator / this->denominator;
}

bool Fractions::setNumerator(int n) {
    this->numerator=n;
    this->reduce();
    return true;
}

bool Fractions::setDenominator(int d) {
    bool success = false;
    
    if ( d < 0 ) d =-d; // make denominator always positive?
    if ( d != 0 )
    {
        this->denominator=d;
        this->reduce();
        success = true;
    }
    
    return success;
}

int Fractions::gcd(int a, int b) {
    if (a==0) return b;
    return gcd( b%a, a);
}

void Fractions::reduce()
{
    int g = gcd( this->numerator, this->denominator );    
    if ( g<0 ) g=-g;
    this->numerator /= g;
    this->denominator /= g;
}

Fractions Fractions::add(Fractions f2) {
    int a = this->numerator;
    int b = this->denominator;
    int c = f2.numerator;
    int d = f2.denominator;
    
    int nn = a*d + b*c;
    int nd = b*d;
    
    int g = this->gcd(nn,nd);
    nn /= g; // nn = nn / g
    nd /= g; // nd = nd / g
    
    return Fractions(nn, nd);
}

Fractions Fractions::subtract(Fractions f2) {
    int a = this->numerator;
    int b = this->denominator;
    int c = f2.numerator;
    int d = f2.denominator;
    
    int nn = a*d - b*c;
    int nd = b*d;
    
    int g = this->gcd(nn,nd);
    nn /= g; // nn = nn / g
    nd /= g; // nd = nd / g
    
    return Fractions(nn, nd);
}

Fractions Fractions::multiply(Fractions f2) {
    int a = this->numerator;
    int b = this->denominator;
    int c = f2.numerator;
    int d = f2.denominator;
    
    int nn = a*c;
    int nd = b*d;
    
    int g = this->gcd(nn,nd);
    nn /= g; // nn = nn / g
    nd /= g; // nd = nd / g
    
    return Fractions(nn, nd);
}

Fractions Fractions::divide(Fractions f2) {
    int a = this->numerator;
    int b = this->denominator;
    int c = f2.numerator;
    int d = f2.denominator;
    
    int nn = a*d;
    int nd = b*c;
    
    int g = this->gcd(nn,nd);
    nn /= g; // nn = nn / g
    nd /= g; // nd = nd / g
    
    return Fractions(nn, nd);
}

Fractions Fractions::operator+(const Fractions &rt)
{
    return this->add(rt);
}

Fractions Fractions::operator-(const Fractions &rt)
{
    return this->subtract(rt);
}

Fractions Fractions::operator-()
{
    return Fractions( -this->getNumerator(), this->getDenominator() );
}

Fractions Fractions::operator*(const Fractions &rt)
{
    return this->multiply(rt);
}

Fractions Fractions::operator/(const Fractions &rt)
{
    return this->divide(rt);
}

Fractions& Fractions::operator+=(const Fractions &rt)
{
    *this = this->add(rt);
    return *this;
}

Fractions& Fractions::operator-=(const Fractions &rt)
{
    *this = this->subtract(rt);
    return *this;
}

Fractions& Fractions::operator*=(const Fractions &rt)
{
    *this = this->multiply(rt);
    return *this;
}

Fractions& Fractions::operator/=(const Fractions &rt)
{
    *this = this->divide(rt);
    return *this;
}

bool Fractions::operator==(const Fractions &rt)
{
    int a = this->numerator;
    int b = this->denominator;
    int c = rt.numerator;
    int d = rt.denominator;
    
    int ad = a*d;
    int bc = b*c;
    
    return ad == bc;
}

bool Fractions::operator!=(const Fractions &rt)    
{
    int a = this->numerator;
    int b = this->denominator;
    int c = rt.numerator;
    int d = rt.denominator;
    
    int ad = a*d;
    int bc = b*c;
    
    return ad != bc;
}

bool Fractions::operator>(const Fractions &rt)
{
    int a = this->numerator;
    int b = this->denominator;
    int c = rt.numerator;
    int d = rt.denominator;
    
    int ad = a*d;
    int bc = b*c;
    
    return ad > bc;
}

bool Fractions::operator>=(const Fractions &rt)
{
    int a = this->numerator;
    int b = this->denominator;
    int c = rt.numerator;
    int d = rt.denominator;
    
    int ad = a*d;
    int bc = b*c;
    
    return ad >= bc;
}

bool Fractions::operator<(const Fractions &rt)
{
    int a = this->numerator;
    int b = this->denominator;
    int c = rt.numerator;
    int d = rt.denominator;
    
    int ad = a*d;
    int bc = b*c;
    
    return ad < bc;
}

bool Fractions::operator<=(const Fractions &rt)
{
    int a = this->numerator;
    int b = this->denominator;
    int c = rt.numerator;
    int d = rt.denominator;
    
    int ad = a*d;
    int bc = b*c;
    
    return ad <= bc;
}

ostream& operator<<(ostream& o, const Fractions &f)
{
    o << f.getNumerator() << " / " << f.getDenominator();
    return o;
}

istream& operator>>(istream& i, Fractions &f)
{
    // when using >> with Fractions, it will be expecting two values in the 
    // order of numerator (followed by whitespace) denominator
    i >> f.numerator >> f.denominator;
    // if our user entered 0 for denominator, we'll set denominator to 1 and setstate = failbit 
    // (users of this class should check this with a call to the good() function
    if ( f.denominator==0 )
    {
        i.setstate(ios_base::failbit); // set istream state to failbit if 0 denominator
        f.denominator = 1; // will not allow denominator to be 0, so let's use something like 1        
    }
    return i;
}