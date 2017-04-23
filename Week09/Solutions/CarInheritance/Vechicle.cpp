#include "Vechicle.h"

void Vechicle::copy(const Vechicle& other)
{
  mystrcpy(color, other.color);
  mystrcpy(model, other.model);
  manufactureYear = other.manufactureYear;
  seats = other.seats;
  maxSpeed = other.maxSpeed;
}

void Vechicle::destroy()
{
  delete[] this->color;
  delete[] this->model;
}


/*
Vechicle::Vechicle()
{
  mystrcpy(this->color, "DEFAULT_COLOR");
  mystrcpy(this->model, "DEFAULT_MODEL");
  this->manufactureYear = 0;
  this->seats = 0;
  this->maxSpeed = 0;
}
*/

Vechicle::Vechicle(const char* color, const char* model, size_t manufactureYear, size_t seats, size_t maxSpeed)
{
  mystrcpy(this->color, color);
  mystrcpy(this->model, model);
  this->manufactureYear = manufactureYear;
  this->seats = seats;
  this->maxSpeed = maxSpeed;
}

Vechicle::Vechicle(const Vechicle& other)
{
  copy(other);
}

Vechicle& Vechicle::operator=(const Vechicle& other)
{
  if(this != &other)
  {
    destroy();
    copy(other);
  }
  return *this;
}

Vechicle::~Vechicle()
{
  destroy();
}

const char* Vechicle::getColor() const
{
  return this->color;
}

const char* Vechicle::getModel() const
{
  return this->model;
}

size_t Vechicle::getManufactureYear() const
{
  return this->manufactureYear;
}

size_t Vechicle::getSeats() const
{
  return this->seats;
}

size_t Vechicle::getMaxSpeed() const
{
  return this->maxSpeed;
}

void Vechicle::setColor(const char* color)
{
  delete[] this->color;

  mystrcpy(this->color, color);
}

void Vechicle::setModel(const char* model)
{
  delete[] this->model;

  mystrcpy(this->model, model);
}

void Vechicle::setManufactureYear(size_t manufactureYear)
{
  this->manufactureYear = manufactureYear;
}

void Vechicle::setSeats(size_t seats)
{
  this->seats = seats;
}

void Vechicle::setMaxSpeed(size_t maxSpeed)
{
  this->maxSpeed = maxSpeed;
}
