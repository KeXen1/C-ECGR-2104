#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

int main(){
    // touch makefile, then create makefile
    // make - to make object file
    // ./test - test no need g++ 
    double s1Grades[] = {2.5, 3.5, 4.0, 2.0, 3.0, 2.0};
    
    vector<Student> s;
    s.push_back(Student("Sam", s1Grades, 6));
    s.push_back(Student("Bob", s1Grades, 6));
    s.push_back(Student("Joe", 3.5));
    
    char userInput = 'Y';
    while(userInput == 'Y'){
        Student temp;
        string tempName;
        int tempId;
        double tempGpa;
        cout << "Please enter student infomration." << endl;
        cout << "Name: " << endl;
        cin >> tempName;
        cout << "GPA: " << endl;
        cin >> tempGpa;
        temp.setName(tempName);
        temp.setGpa(tempGpa);
        
        s.push_back(temp);
        cout << "Do you want to enter another student? (Y/N)" << endl;
        cin >> userInput;
    }
    
    for(int i = 0; i < s.size(); i++){
        cout << "Name: " << (s.at(i)).getName() << " ID: " << s.at(i).getId() << " GPA: " << s.at(i).getGpa() << endl;
    }
    
    double a[] = {2, 3, 5};
    Student st;
    double avg = Student::average(a, 3);
    
    return 0;
}