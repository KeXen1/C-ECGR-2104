#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee{
    public:
        Employee(const string& name, const string& jobTitle, const double& hourlyWage);
        void setHourlyWage(double hourlyWage);
        string getName() const;
        string getJobTitle() const;
        double getHourlyWage() const;
    private:
        string name;
        string jobTitle;
        double hourlyWage;
};

void printOptions();

#endif