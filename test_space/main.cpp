#include <iostream>

using namespace std;

class Fraction {
  public:
  int n;
  
  double deciVal(){
    return (double)n/(double)d;
  }
  
  int getDenominator() const{
    return d;
  }
  
  void setDenominator(int d){
    if(d == 0){
        cout << "Invalid" << endl;
    } else {
        this->d = d;
    }
  }
  
  private:
  int d;
};

int main(){
    
    Fraction F1;
    F1.n = 2;
    F1.setDenominator(4);
    cout << F1.getDenominator() << endl;
    cout << F1.deciVal() << endl;
    
    
    return 0;
}