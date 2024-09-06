#include "student.h"

int Student::numStudents = 0;

string Student::getName() const{
    return name;
} //const stops it from modifying any variables used
    
int Student::getId() const{
    return id;
}

double Student::getGpa() const{
    return gpa;
}

void Student::setName(string name){
    this->name = name;
}

Student::Student(){
    cout << "Constructor called!" << endl;
    id = -1;
    name = "Unassigned";
    gpa = 4.0;
}
    
Student::Student(const string& name, double gpa){
    cout << "Overloaded constructor called!" << endl;
    this->name = name;
    this->id = 800000000 + numStudents;
    ++numStudents;
    this->gpa = gpa;
}

Student::Student(const string& name, double grades[], const unsigned int NUM_GRADES){
    cout << "Overloaded constructor called!" << endl;
    this->name = name;
    this->id = 800000000 + numStudents;
    ++numStudents;
    computeGpa(grades, NUM_GRADES);
}   

void Student::computeGpa(double grades[], const unsigned int NUM_GRADES){
    this->gpa = average(grades, NUM_GRADES);
}

double Student::average(double a[], const unsigned int& SIZE){
    double sum = 0.0;
    for(int i = 0; i < SIZE; i++){
        sum += a[i];
    }
    return sum/double(SIZE);
}

void Student::setGpa(const double& gpa){
    this->gpa = gpa;
}