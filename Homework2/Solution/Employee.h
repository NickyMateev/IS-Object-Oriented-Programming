//
// Created by Mateev, Nikolay on 4/11/17.
//

#ifndef HW2_EMPLOYEE_H
#define HW2_EMPLOYEE_H
#include "myFunctions.h"
#include "EmployeePosition.h"

class Employee {
private:
    char* name;
    int age;
    double monthlySalary;
    EmployeePosition employeePosition;

    void copy(const Employee& other);
    void destroy();
public:
    Employee();
    Employee(char* name, int age, double monthlySalary, EmployeePosition employeePosition);
    Employee(const Employee& other);
    Employee&operator=(const Employee& other);
    ~Employee();

    const char* getName() const;
    int getAge() const;
    double getMonthlySalary() const;
    EmployeePosition getEmployeePosition() const;

    void setName(const char* name);
    void setAge(int age);
    void setMonthlySalary(double monthlySalary);
    void setEmployeePosition(EmployeePosition employeePosition);

    double calculateAnnualSalary() const;
    void increaseSalary(int percent);
    void decreaseSalary(int percent);
};


#endif //HW2_EMPLOYEE_H
