/*****************************************
** File:    Formula.h
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: class for differnt type of racer
*********************************************
*/


#ifndef FORMULA_H
#define FORMULA_H

#include "Racer.h"
const int FORMULA_SPEED = 220;

class Formula: public Racer{
 public:
  //Default Constructor
  Formula();
  //Overloaded Constructor
  Formula(string name, int number);
  //ToString
  string ToString() const{
    return "Formula";
  }
  //Overloaded << operator (to be implemented)
  friend ostream& operator<<(ostream&, const Formula&);
};

#endif
