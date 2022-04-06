#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Fractions.h"
using namespace std;

const int ARR_SIZE = 10;


int my_random(int min, int max)
{
    static bool rand_seeded = false;
    if ( !rand_seeded)
    {
        srand(time(0));
        rand_seeded = true;
    }
    return min+rand() % (max-min+1);    
}

int main() {
    
    Fractions a = Fractions(3,8);
    Fractions b = Fractions(3,4);
    
    //Fractions c = a.add(b); // should be 9/8
    //Fractions d = b.subtract(a); // should be 3/8
    //Fractions e = a.multiply(b); // should be 9 / 32
    //Fractions f = a.divide(b); // should be 1 / 2
    Fractions c = a + b; // should be 9/8
    Fractions d = b - a; // should be 3/8
    Fractions e = a * b; // should be 9 / 32
    Fractions f = a / b; // should be 1 / 2
    
    Fractions g = Fractions(1,2);
    g += a; // g = 1/2 + 3/8 = 7/8
    
    //cout << c.getNumerator() << " / " << c.getDenominator() << endl;
    //cout << d.getNumerator() << " / " << d.getDenominator() << endl;
    //cout << e.getNumerator() << " / " << e.getDenominator() << endl;
    //cout << f.getNumerator() << " / " << f.getDenominator() << endl;
    //cout << g.getNumerator() << " / " << g.getDenominator() << endl;
    
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    
    // does unary - work?
    cout << -f << endl; // if so, should output -1/2
    
    cout << endl << "Testing += -= *= /= overloaded operators..." << endl << endl;
    cout << g << endl; // should output 7/8
    g-=e; // g = 7/8 - 9/32 = 19/32
    cout << g << endl; // should output 19/32
    g*=e; // g = 19/32 * 9/32 = 171/1024
    cout << g << endl; // should output 171/1024
    g/=e; // g = g / (9/32) = 19/32
    cout << g << endl << endl; // should output 19/32
    
    Fractions fractions_array[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++)
        fractions_array[i] = Fractions( my_random(1,5), my_random(6,10) );
    
    cout << "The " << ARR_SIZE << " random fractions are:\n\n";
    for(int i=0;i<ARR_SIZE;i++)
        cout << fractions_array[i].getNumerator() << " / " << fractions_array[i].getDenominator() << endl;
    
    // sum of all the fractions in fractions_array...
    Fractions sum = Fractions(); // sum = 0 / 1 or just plain zero
    
    for(int i = 0; i < ARR_SIZE; i++)
    {
        //sum += fractions_array[i];
        sum = sum + fractions_array[i];
        cout << sum.getNumerator() << " / " << sum.getDenominator() << endl;
    }
    
    //cout << sum.getNumerator() << " / " << sum.getDenominator() << endl;
    
    cout << "Sum of fractions array = " <<sum << endl;
    
    // test stream extraction operator
    Fractions test, test2;
    
    cout << "Enter your fraction as numerator then denominator (separate with a space): ";
    cin >> test;
    
    cout << "Your fraction to entered was: " << test << endl;
    cout << "cin.good() returned: " << cin.good() << endl;
    
    // test logical and relational ops
    cout << "Enter another fraction as numerator then denominator (separate with a space): ";
    cin >> test2;
    
    cout << test << " == " << test2 << " evaluated as: " << (test==test2) << endl;
    cout << test << " != " << test2 << " evaluated as: " << (test!=test2) << endl;
    cout << test << " > " << test2 << " evaluated as: " << (test>test2) << endl;
    cout << test << " >= " << test2 << " evaluated as: " << (test>=test2) << endl;
    cout << test << " < " << test2 << " evaluated as: " << (test<test2) << endl;
    cout << test << " <= " << test2 << " evaluated as: " << (test<=test2) << endl;
    
    return 0;
}
