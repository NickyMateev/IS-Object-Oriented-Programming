#include "Bicycle.h"

void Bicycle::copy(const Bicycle& other)
{
  this->gears = other.gears;
  this->lights = other.lights;
  this->bell = other.bell;
}

Bicycle::Bicycle(const char* color, const char* model, size_t manufactureYear, size_t seats, size_t maxSpeed, size_t gears, bool lights, bool bell) : Vechicle(color, model, manufactureYear, seats, maxSpeed)
{
  this->gears = gears;
  this->lights = lights;
  this->bell = bell;
}

Bicycle::Bicycle(const Bicycle& other) : Vechicle(other)
{
  copy(other);
}

Bicycle& Bicycle::operator=(const Bicycle& other)
{
  if(this != &other)
  {
    Vechicle::operator=(other);

    copy(other);
  }

  return *this;
}

Bicycle::~Bicycle() { }

size_t Bicycle::getGears() const
{
  return this->gears;
}

bool Bicycle::hasLights() const
{
  return this->lights;
}

bool Bicycle::hasBell() const
{
  return this->bell;
}

void Bicycle::setGears(size_t gears)
{
  this->gears = gears;
}

void Bicycle::setLights(bool lights)
{
  this->lights = lights;
}

void Bicycle::setBell(bool bell)
{
  this->bell = bell;
}
