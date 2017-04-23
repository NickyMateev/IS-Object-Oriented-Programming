#include <iostream>
#include "Bicycle.h"
#include "Car.h"

int main()
{
  Vechicle vs[5];
  Bicycle bs[5];
  Car cs[5];

  cout << vs[2].getColor() << endl;
  cout << bs[0].getSeats() << endl;
  cout << cs[0].getHorsePower() << endl;

  return 0;
}
