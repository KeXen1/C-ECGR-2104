#include <iostream>
#include <stdlib.h>
#include <fstream>

//#define DEBUG

using namespace std;

int main(int argc, char* argv[]){
    
    bool encrypt_flag = false;
    string inputFile;
    string outputFile;
    int key;
    
    if(argc != 8){
        cout << "Errornous input parameter(s)" << endl;
        return 0;
    }
    
    for(int i = 0; i < argc; i++){
        string s(argv[i]);
        if(s == "-e"){
            #ifdef DEBUG
                cout << "Encrypting!" << endl;
            #endif
            encrypt_flag = true;
        } else if(s == "-d"){
            #ifdef DEBUG
                cout << "Decrypting!" << endl;
            #endif
            encrypt_flag = false;
        }
        
        if(s == "-k"){
            key = atoi(argv[i+1]);
            #ifdef DEBUG
                cout << "Key value: " << key << endl;
            #endif
        }
        
        if(s == "-o"){
            outputFile = argv[i+1];
        }
        
        if(s == "-i"){
            inputFile = argv[i+1];
        }
    }
    
    ifstream inFile;
    inFile.open(inputFile);
    
    if(!inFile.is_open()){
        cout << "File is not opened!" << endl;
        return 0;
    }
    
    string text;
    if(!inFile.eof()){
        getline(inFile, text);
    }
    
    if(encrypt_flag){
        for(int i = 0; i < text.size(); i++){
            
            if(isupper(text[i])){
                int idx = text[i] - 65;
                
                char shiftedidx = ((idx + key) % 26) + 65;
                
                text[i] = shiftedidx;
            }
            
            if(islower(text[i])){
                int idx = text[i] - 97;
                
                char shiftedidx = ((idx + key) % 26) + 97;
                
                text[i] = shiftedidx;
            }
            
            if(text[i] == ' '){
                text[i] = ' ';
            }
        }
    }
    
    if(!encrypt_flag){
        for(int i = 0; i < text.size(); i++){
            
            if(isupper(text[i])){
                int idx = text[i] - 65;
                
                char shiftedidx = (26 + ((idx - key) % 26)) % 26 + 65;
                
                text[i] = shiftedidx;
            }
            
            if(islower(text[i])){
                int idx = text[i] - 97;
                
                char shiftedidx = (26 + ((idx - key) % 26)) % 26 + 97;
                
                text[i] = shiftedidx;
            }
            
            if(text[i] == ' '){
                text[i] = ' ';
            }
        }
    }
    
    inFile.close();
    ofstream outFile;
    outFile.open(outputFile);
    
    if(!outFile.is_open()){
        cout << "File is not opened!" << endl;
        return 0;
    }
    outFile << text;
    
    outFile.close();
    
    return 0;
}