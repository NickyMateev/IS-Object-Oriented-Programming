//
// Created by Mateev, Nikolay on 4/11/17.
//

#ifndef HW2_COMPANY_H
#define HW2_COMPANY_H

#include "myFunctions.h"
#include "Employee.h"
#include "Equipment.h"
#include <cstring>

class Company {
private:
    char* name;

    Employee* employees;
    int employeeCount;
    int employeeCapacity;

    Equipment* equipment;
    int equipmentCount;
    int equipmentCapacity;

    void copy(const Company& other);
    void destroy();

    void resizeEmployees(int newCapacity);
    void resizeEquipment(int newCapacity);
public:
    Company();
    Company(const char* name);
    Company(const char* name, const Employee* employees, int employeeCount, const Equipment* equipment, int equipmentCount);
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    const char* getName() const;
    const Employee* getEmployees() const;
    int getEmployeeCount() const;
    const Equipment* getEquipment() const;
    int getEquipmentCount() const;

    void setName(const char* name);
    void setEmployees(const Employee* employees, int employeeCount);
    void setEquipment(const Equipment* equipment, int equipmentCount);

    double calculateTotalEmployeeAnnualSalary() const;
    double calculateTotalYearlyMaintenanceCosts() const;
    void increaseEmployeeSalary(const char* name, int percent);
    void decreaseEmployeeSalary(const char* name, int percent);
    void increaseAllSalaries(int percent);
    void decreaseAllSalaries(int percent);

    void addEmployee(const Employee& newEmployee);
    void addEquipment(const Equipment& newEquipment);
};


#endif //HW2_COMPANY_H
