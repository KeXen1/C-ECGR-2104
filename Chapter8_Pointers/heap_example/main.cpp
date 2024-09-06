#include <iostream>

using namespace std;

void func(){
    int* x = new int[3];
    
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    
    
    cout << x[0] << endl;
    //cout << *x << endl;
    //cout << &x << endl;
    delete[] x;
}
int main(){
    
    func();
    func();
    func();
   
    return 0;
}