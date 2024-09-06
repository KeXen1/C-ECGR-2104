#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include "employee.h"

using namespace std;

int main(){
    unsigned int inputAsInt;
    double hoursWorked;
    double totalWages;
    const int OPTION_1 = 1;
    const int OPTION_2 = 2;
    const int OPTION_3 = 3;
    
    cout << "This application will track employee's names, job titles, wages, and calculate the total amount of wages that employees are to be paid for the week." << endl;
    
    vector<Employee> employeeDatabase;
    employeeDatabase.push_back(Employee("Sam", "Software Engineer", 30.00));
    employeeDatabase.push_back(Employee("Bob", "Marketing Specialist", 20.00));
    employeeDatabase.push_back(Employee("Joe", "Human Resources Manager", 18.00));
    employeeDatabase.push_back(Employee("Rob", "Financial Analyst", 15.00));
    employeeDatabase.push_back(Employee("Jill","Customer Service Representative", 12.50));
    
    do{
        printOptions();
        cout << "Please select one of the options: ";
        string userInput;
        cin >> userInput;
        inputAsInt = atoi(userInput.c_str());
        cout << endl;
        
        if(inputAsInt == OPTION_1){
            for(int i = 0; i < employeeDatabase.size(); i++){
                cout << "Name: " << employeeDatabase[i].getName() << setw(2) << "\tHourly Wage: $" << fixed << setprecision(2) << employeeDatabase[i].getHourlyWage() 
                << "\tJob Title: " << employeeDatabase[i].getJobTitle() << endl;
            }
        }
        
        if(inputAsInt == OPTION_2){
            for(int i = 0; i < employeeDatabase.size(); i++){
                do{
                    cout << "Enter number of hours " << employeeDatabase[i].getName() << " has worked: ";
                    cin >> userInput;
                    hoursWorked = atof(userInput.c_str());
                }while(hoursWorked <= 0.0);
                totalWages += hoursWorked * employeeDatabase[i].getHourlyWage();
            }
            cout << endl << "The total wages for this week is: $" << fixed << setprecision(2) << totalWages << endl;
        }
        
    }while(inputAsInt != OPTION_3);
    
    return 0;
}