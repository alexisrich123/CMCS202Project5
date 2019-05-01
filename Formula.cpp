/*****************************************
** File:    Formula.cpp
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: manage the race
*********************************************
*/

#include "Formula.h"



  //Default Constructor
  Formula::Formula()
  :Racer(){

  }
  //Overloaded Constructor
  Formula::Formula(string name, int number)
  :Racer(name, number, FORMULA_SPEED){
    
  }
  
  //Overloaded << operator (to be implemented)
  ostream& operator<<(ostream& output, const Formula& formula){

    // printng out the data form the racecar
    output<<formula.ToString()<<" ";
    output <<formula.GetName()<<" (#"<<formula.GetNumber()<<") going "<<formula.GetSpeed()<<"MPH\n";

    return output;
  }



