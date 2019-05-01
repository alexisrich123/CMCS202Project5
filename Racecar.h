/*****************************************
** File:    Racecar.h
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: class for differnt type of racer
*********************************************
*/



#ifndef RACECAR_H
#define RACECAR_H

#include "Racer.h"
const int CAR_SPEED = 200;

class Racecar: public Racer{
 public:
  //Default constructor
  Racecar();
  //Overloaded constructor
  Racecar(string name, int number);
  //ToString
  string ToString() const{
    return "Racecar";
  }
  //Overloaded << operator (to be implemented);
  friend ostream& operator<<(ostream&, const Racecar&);
};

#endif
