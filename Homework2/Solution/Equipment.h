//
// Created by Mateev, Nikolay on 4/11/17.
//

#ifndef HW2_EQUIPMENT_H
#define HW2_EQUIPMENT_H
#include "myFunctions.h"


class Equipment {
private:
    char* name;
    double price;
    double monthlyMaintenanceCost;

    void copy(const Equipment& other);
    void destroy();
public:
    Equipment();
    Equipment(const char* name, double price, double monthlyMaintenanceCost);
    Equipment(const Equipment& other);
    Equipment& operator=(const Equipment& other);
    ~Equipment();

    const char* getName() const;
    double getPrice() const;
    double getMonthlyMaintenanceCost() const;

    void setName(const char* name);
    void setPrice(double price);
    void setMonthlyMaintenanceCost(double monthlyMaintenanceCost);

};


#endif //HW2_EQUIPMENT_H
