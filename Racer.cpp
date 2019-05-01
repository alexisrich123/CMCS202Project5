/*****************************************
** File:    Racer.cpp
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: class for differnt type of racer
*********************************************
*/



#include "Racer.h"

  Racer::Racer(){ 
    m_name = " Car";
    m_number = 0;
    m_speed = 0;


  }
  Racer::Racer(string name, int number, int speed){
    m_name = name;
    m_number = number;
    m_speed = speed;

  } //Overloaded constructor
  
  //Getters and setters for each Racer
  void Racer::SetValues(string name , int number, int speed){
    m_name = name;
    m_number = number;
    m_speed = speed;


  }
  string Racer::GetName() const{
    return m_name;

  };
  void Racer::SetName(string name)
  {
    m_name = name;
  }
  int Racer::GetNumber() const{
    return m_number;
  };
  void Racer::SetNumber(int number){

    m_number = number;

  }
  int Racer::GetSpeed() const{

    return m_speed;
  };
  void Racer::SetSpeed(int speed){
    m_speed = speed;

  }
  void Racer::SetIsCrashed(bool isCrashed){
     m_isCrashed = isCrashed;

  }
  bool Racer::GetIsCrashed() const{

    return m_isCrashed;
  };
  //Racer overloaded << operator
  ostream& operator<<(ostream& output, Racer& racer){

    
    // pring out the data form the racer

    cout<<racer.ToString()<<" ";

    output <<racer.GetName()<<" (#"<<racer.GetNumber()<<") going "<<racer.GetSpeed()<<"MPH\n";

    return output;
  }

  



