Да се реализира йерархията от класове, която е описана:

###### Company:
- name
- budget
- departments

###### Departments:
- name
- budget
- employees

###### Employee:
- name
- experience
- age
- startWorkingDate
	- startWorkingDate

Да се реализира сортировка, която приема като параметър списък от Employee и компаратор. Трябва да се реализира по един компаратор за всяко едно от полетата.

```
using Comparator = bool (*)(Employee, Employee);

void sort(Employee* emps, Comparator comaprator);
```