#include "employee.h"

Employee::Employee(const string& name, const string& jobTitle, const double& hourlyWage){
    this->name = name;
    this->jobTitle = jobTitle;
    setHourlyWage(hourlyWage);
}

void Employee::setHourlyWage(double hourlyWage){
    if(hourlyWage > 0.0){
        this->hourlyWage = hourlyWage;
    } else{
        throw invalid_argument("Invalid hourly wage.");
    }
}

string Employee::getName() const{
    return name;
}

string Employee::getJobTitle() const{
    return jobTitle;
}

double Employee::getHourlyWage() const{
    return hourlyWage;
}

void printOptions(){
    cout << endl << "1. Print list of employees\n2. Calculate total wages\n3. Exit Application" << endl << endl;
}