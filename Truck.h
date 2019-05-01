/*****************************************
** File:    Truck.h
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: class for differnt type of racer
*********************************************
*/


#ifndef TRUCK_H
#define TRUCK_H

#include "Racer.h"
const int TRUCK_SPEED = 150;

class Truck: public Racer{
 public:
  //Default constructor
  Truck();
  //Overloaded constructor
  Truck(string name, int number);
  //To String
  string ToString() const{
    return "Truck";
  }
  //Overloaded << operator (to be implemented)
  friend ostream& operator<<(ostream&, const Truck&);
};

#endif
