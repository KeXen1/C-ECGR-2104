#include <iostream>
#include <cmath>
#include <ctype.h>

using namespace std;

int main(){
    
    char s[] = {'a', 'b', 'c', 'z'};
    int key = 3;
    
    for(int i = 0; i < 4; i++){
        
        if(islower(s[i])){
            int idx = s[i] - 97;
            
            char shiftedidx = ((idx + key) % 26) + 97;
            
            cout << shiftedidx << endl;
        }
        
        
        /*if(s[i] >= 97 && s[i] <= 122){
            if(s[i] > 122){
            s[i] = 97 + (s[i] - 122) + key;
            } else {
                s[i] = s[i] + key;
            }
        }
        
        cout << s[i] << endl;
        */
    }
    
    /*int x = 27;
    int y = 5;
    
    cout << y % 26 << endl;
    cout << x % 26 << endl;
    */
    
    return 0;
}