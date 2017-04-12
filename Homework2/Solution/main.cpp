#include "Company.h"
using namespace std;

int main() {
    int employeeCount = 3;
    Employee* employees = new Employee[employeeCount];
    int equipmnetCount = 5;
    Equipment* equipment = new Equipment[equipmnetCount];

    Company company("TechSoft", employees, employeeCount, equipment, equipmnetCount);
    cout << "Total employee annual salary: $" << company.calculateTotalEmployeeAnnualSalary() << endl;


    delete[] employees;
    delete[] equipment;
    return 0;
}
