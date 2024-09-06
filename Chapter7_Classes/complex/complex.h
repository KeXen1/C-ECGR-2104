#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

struct Complex{
    double real;
    double imag;
    
    Complex(double real, double imag);
    
    void print();
    
    Complex operator+(Complex rhs);
    
    Complex operator+(int rhs);
    
    void operator+=(Complex rhs);

    Complex operator-(Complex rhs);
};

#endif