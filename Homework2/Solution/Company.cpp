//
// Created by Mateev, Nikolay on 4/11/17.
//

#include "Company.h"

const int DEFAULT_CAP = 16;

void Company::copy(const Company &other) {
    mystrcpy(this->name, other.name);

    this->employees = new Employee[other.employeeCapacity];
    for (int i = 0; i < other.employeeCount; ++i) {
        this->employees[i] = other.employees[i];
    }
    this->employeeCount = other.employeeCount;
    this->employeeCapacity = other.employeeCapacity;

    this->equipment = new Equipment[other.equipmentCount];
    for (int i = 0; i < other.equipmentCount; ++i) {
        this->equipment[i] = other.equipment[i];
    }
    this->equipmentCount = other.equipmentCount;
    this->equipmentCapacity = other.equipmentCapacity;
}

void Company::destroy() {
    delete[] this->name;
    delete[] this->employees;
    delete[] this->equipment;
}

void Company::resizeEmployees(int newCapacity) {
    Employee* temp = new Employee[newCapacity];
    for (int i = 0; i < this->employeeCount; ++i) {
       temp[i] = this->employees[i];
    }

    delete[] this->employees;
    this->employees = temp;
    this->employeeCapacity = newCapacity;
}

void Company::resizeEquipment(int newCapacity) {
    Equipment* temp = new Equipment[newCapacity];
    for (int i = 0; i < this->equipmentCount; ++i) {
       temp[i] = this->equipment[i];
    }

    delete[] this->equipment;
    this->equipment = temp;
    this->equipmentCapacity = newCapacity;
}

Company::Company() {
    this->name = NULL;
    this->employees = NULL;
    this->employeeCount = 0;
    this->employeeCapacity = 0;
    this->equipment = NULL;
    this->equipmentCount = 0;
    this->equipmentCapacity = 0;
}

Company::Company(const char* name) {
    mystrcpy(this->name, name);
    this->employees = new Employee[DEFAULT_CAP];
    this->employeeCount = 0;
    this->employeeCapacity = DEFAULT_CAP;
    this->equipment = new Equipment[DEFAULT_CAP];
    this->equipmentCount = 0;
    this->equipmentCapacity = DEFAULT_CAP;
}

Company::Company(const char* name, const Employee* employees, int employeeCount, const Equipment* equipment, int equipmentCount) {
    mystrcpy(this->name, name);
    this->employeeCapacity = employeeCount * 2;
    this->employees = new Employee[this->employeeCapacity];
    for (int i = 0; i < employeeCount; ++i) {
       this->employees[i]  = employees[i];
    }
    this->employeeCount = employeeCount;

    this->equipmentCapacity = equipmentCount * 2;
    this->equipment = new Equipment[this->equipmentCapacity];
    for (int i = 0; i < equipmentCount; ++i) {
        this->equipment[i] = equipment[i];
    }
    this->equipmentCount = equipmentCount;
}

Company::Company(const Company& other) {
    copy(other);
}

Company& Company::operator=(const Company& other) {
    if(this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

Company::~Company() {
    destroy();
}

const char* Company::getName() const {
    return this->name;
}

const Employee* Company::getEmployees() const {
    return this->employees;
}

int Company::getEmployeeCount() const {
    return this->employeeCount;
}

const Equipment* Company::getEquipment() const {
    return this->equipment;
}

int Company::getEquipmentCount() const {
    return this->equipmentCount;
}

void Company::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void Company::setEmployees(const Employee* employees, int employeeCount) {
    delete[] employees;

    this->employeeCapacity = employeeCount * 2;
    this->employees = new Employee[this->employeeCapacity];
    for (int i = 0; i < employeeCount; ++i) {
        this->employees[i] = employees[i];
    }
    this->employeeCount = employeeCount;
}

void Company::setEquipment(const Equipment* equipment, int equipmentCount) {
    delete[] equipment;

    this->equipmentCapacity = equipmentCapacity * 2;
    this->equipment = new Equipment[this->equipmentCapacity];
    for (int i = 0; i < equipmentCount; ++i) {
        this->equipment[i] = equipment[i];
    }
    this->equipmentCount = equipmentCount;
}

double Company::calculateTotalEmployeeAnnualSalary() const {
    double total = 0;
    for (int i = 0; i < this->employeeCount; ++i) {
       total += this->employees[i].calculateAnnualSalary();
    }

    return total;
}

double Company::calculateTotalYearlyMaintenanceCosts() const {
    double total = 0;
    for (int i = 0; i < this->equipmentCount; ++i) {
       total += (this->equipment[i].getMonthlyMaintenanceCost() * 12);
    }

    return total;
}

void Company::increaseEmployeeSalary(const char* name, int percent) {
    for (int i = 0; i < this->employeeCount; ++i) {
        if(strcmp(this->employees[i].getName(), name) == 0) {
            this->employees[i].increaseSalary(percent);
        }
    }
}

void Company::decreaseEmployeeSalary(const char* name, int percent) {
    for (int i = 0; i < this->employeeCount; ++i) {
        if(strcmp(this->employees[i].getName(), name) == 0) {
            this->employees[i].decreaseSalary(percent);
        }
    }
}

void Company::increaseAllSalaries(int percent) {
    for (int i = 0; i < this->employeeCount; ++i) {
       this->employees[i].increaseSalary(percent);
    }
}

void Company::decreaseAllSalaries(int percent) {
    for (int i = 0; i < this->employeeCount; ++i) {
        this->employees[i].decreaseSalary(percent);
    }
}

void Company::addEmployee(const Employee& newEmployee) {
    if(this->employeeCount == this->employeeCapacity) {
        resizeEmployees(this->employeeCapacity * 2);
    }

    this->employees[this->employeeCount] = newEmployee;
    this->employeeCount++;
}

void Company::addEquipment(const Equipment& newEquipment) {
    if(this->equipmentCount == this->equipmentCapacity) {
        resizeEquipment(this->equipmentCapacity * 2);
    }

    this->equipment[this->equipmentCount] = newEquipment;
    this->equipmentCount++;
}
