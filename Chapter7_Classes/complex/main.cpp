#include <iostream>
#include "complex.h"

using namespace std;

int main(){
    
    Complex c1(4,3);
    Complex c2(1,1);
    
    Complex c5 = c2 + 5 + c2;
    
    //Complex c5 = (c2.add(5)).add(c2);
    
    c5.print();
    
    //Complex c3 = c1.add(c2);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    c3 = c3 + 5;
    c3 += c1;
 
    c3.print();
    c4.print();
    
    return 0;
    
}