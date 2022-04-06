#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <iostream>
using namespace std;

class Fractions {
private:
    int numerator, denominator;
    
    int gcd(int a, int b);
    void reduce();
    
public:
    Fractions();
    Fractions(int n, int d);
    Fractions(const Fractions& orig);
    virtual ~Fractions();
    
    int getNumerator() const; // added 3/28/19
    int getDenominator() const; // added 3/28/19
    bool setNumerator(int n);
    bool setDenominator(int d);
    double getValue() const;
    
    Fractions add(Fractions f2);
    Fractions subtract(Fractions f2);
    Fractions multiply(Fractions f2);
    Fractions divide(Fractions f2);
    
    // overloaded operators (arithmetics)
    Fractions operator+(const Fractions &rt);
    Fractions operator-(const Fractions &rt);
    Fractions operator-(); // unary op - added 3/28/19
    Fractions operator*(const Fractions &rt);
    Fractions operator/(const Fractions &rt);
        
    Fractions& operator+=(const Fractions &rt);
    Fractions& operator-=(const Fractions &rt);
    Fractions& operator*=(const Fractions &rt);
    Fractions& operator/=(const Fractions &rt);
    
    // overloaded operators (logical/relational)
    bool operator==(const Fractions &rt);
    bool operator!=(const Fractions &rt);   
    bool operator>(const Fractions &rt);
    bool operator>=(const Fractions &rt);
    bool operator<(const Fractions &rt);
    bool operator<=(const Fractions &rt);
    
    // overloaded operators (I/O)
    friend ostream& operator<<(ostream& o, const Fractions& f);
    friend istream& operator>>(istream& i, Fractions& f);
    
};

#endif /* FRACTIONS_H */

