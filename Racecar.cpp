/*****************************************
** File:    Racecar.cpp
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: class for differnt type of racer
*********************************************
*/

#include "Racecar.h"



  //Default constructor
  Racecar::Racecar():Racer(){

  }
  //Overloaded constructor
  Racecar::Racecar(string name, int number):
  Racer(name, number, CAR_SPEED){}

  
  //Overloaded << operator (to be implemented);
  ostream& operator<<(ostream& output, const Racecar& racecar){

    // printng out the data form the racecar
    output<<racecar.ToString()<<" ";
    output <<racecar.GetName()<<" (#"<<racecar.GetNumber()<<") going "<<racecar.GetSpeed()<<"MPH\n";


    return output;
  }



