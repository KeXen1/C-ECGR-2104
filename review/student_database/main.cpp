#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    /*
    string name0 = "Sam";
    int id0 = 801723321;
    double gpa0 = 2.5;
    
    string name1 = "Bob";
    int id1 = 801723341;
    double gpa1 = 3.0;
    */
    
    /*
    const unsigned int BUFF_SIZE = 100;
    string name[BUFF_SIZE];
    int id[BUFF_SIZE];
    double gpa[BUFF_SIZE];
    unsigned int nextIdx = 0;
    
    name[nextIdx] = "Sam";
    id[nextIdx] = 801723321;
    gpa[nextIdx] = 2.5;
    nextIdx++;
    
    for(int i = 0; i < nextIdx; i++){
        cout << "Name: " << name[i] << " ID: " << id[i] << " GPA: " << gpa[i] << endl;
    }
    */
    
    vector<string> name;
    vector<int> id;
    vector<double> gpa;
    
    name.push_back("Sam");
    id.push_back(801723321);
    gpa.push_back(2.5);
    
    name.push_back("Bob");
    id.push_back(801723321);
    gpa.push_back(3.0);
    
    /*
    name.pop_back();
    id.pop_back();
    gpa.pop_back();
    */
    
    for(int i = 0; i < name.size(); i++){
        cout << "Name: " << name.at(i) << " ID: " << id[i] << " GPA: " << gpa[i] << endl;
    }
    
    return 0;
} 