#pragma once
#include <iostream>
#include "myFunctions.h"
using namespace std;

class Vechicle
{
  char* color;
  char* model;
  size_t manufactureYear;
  size_t seats;
  size_t maxSpeed;

  void copy(const Vechicle& other);
  void destroy();
public:
  // Vechicle(); we can either explicitly define a default constructor like this OR define an explicit construcotor with parameters which have default values like what's done on the next line...
  Vechicle(const char* color = "DEFAULT_COLOR", const char* model = "DEFAULT_MODEL", size_t manufactureYear = 0, size_t seats = 0, size_t maxSpeed = 0);
  Vechicle(const Vechicle& other);
  Vechicle& operator=(const Vechicle& other);
  ~Vechicle();

  const char* getColor() const;
  const char* getModel() const;
  size_t getManufactureYear() const;
  size_t getSeats() const;
  size_t getMaxSpeed() const;

  void setColor(const char* color);
  void setModel(const char* model);
  void setManufactureYear(size_t manufactureYear);
  void setSeats(size_t seats);
  void setMaxSpeed(size_t maxSpeed);
};
