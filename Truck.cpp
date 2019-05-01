/*****************************************
** File:    Truck.cpp
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: class for differnt type of racer
*********************************************
*/

#include "Truck.h"



  //Default constructor
  Truck::Truck()
  :Racer(){

  }
  //Overloaded constructor
  Truck::Truck(string name, int number)
  :Racer(name, number, TRUCK_SPEED){

  }
 
  //Overloaded << operator (to be implemented)
  ostream& operator<<(ostream& output, const Truck& truck){

    // printng out the data form the truck

    output<<truck.ToString()<<" ";
    output <<truck.GetName()<<" (#"<<truck.GetNumber()<<") going "<<truck.GetSpeed()<<"MPH\n";

    return output;
  }

