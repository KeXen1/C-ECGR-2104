#include <iostream>

using namespace std;

void foo(int* a){
    int b = 3;
    *a = *a + b;
}

void swap(int*  x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x = 5;
    int y = 8;
    
    swap(&x, &y);
    
    cout << x << endl;
    
    return 0;
}