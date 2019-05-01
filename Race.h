/*****************************************
** File:    Race.h
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: manage the race
*********************************************
*/




#ifndef RACE_H
#define RACE_H

#include "Racer.h"
#include "Racecar.h"
#include "Truck.h"
#include "Formula.h"
#include "Lqueue.h"

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

//Constant array for Racer names (regardless of type of racer)
const string RACERS [] = {"Mcdowell","Abdel","Wheeler","Romero","Barton","Wood","Azam","Munoz","Baird","Moon","Cantrell","Kent","Hunter","Reilly","Rivas","Copeland","Sharp","York","Henson","Sweet","Horne","Cook","Vincent","Pearson","Sabir","Palmer","Sanders","Lynn","Merrill","King","Holt","Preston","Zhang","Dominguez","Workman","Roach","Franklin","Walker","Maynard","Burris","Scott","Li","Barrett","Carson","Hutchinson","Sargent","Woodward","Leblanc","Lopez","Chen","Soto","Contreras","Sellers","Espinoza","Pierce","Masood","Giles","Garrison","Garner","Garza","Spencer","Hill","Spence","Maldonado","Hassan","Garrett","Harris","Petersen","Rogers","Hester","Molla","Murphy","Conner","Yassin","Sloan","Long","Terrell","Matthews","Whitley","Kim","Branch","Crane","Browning","Gentry","English","Mayo","Barnes","Molina","Dodson","Mccray","Hines","Malone","Whitehead","Mccarty","Marsh","Fletcher","Fuller","Aguirre","Pacheco","Ozer"};
			  
//Constant array for Racer numbers (regardless of type)
const int RACE_NUMS [] = {73,62,86,78,75,8,65,17,58,17,71,21,64,33,62,95,11,98,34,8,83,37,61,33,86,79,12,17,36,41,84,34,22,5,62,80,46,33,45,45,65,64,50,11,96,27,68,71,25,11,41,2,37,43,75,4,34,86,62,59,92,49,87,27,42,64,5,20,97,11,68,97,32,45,96,43,94,81,17,71,84,99,6,91,68,46,50,44,18,8,67,28,12,10,44,6,92,35,17,58};

const int MAX_RACERS = 100; //Max number of racers in race
const int MIN_RACERS = 2; //Min number of racers in race
const int RAND_SEED = 10; //Constant seed for program (srand(RAND_SEED) in Race const.
const int SPEED_MOD = 15; //Percentage change for each lap (15%)

template <class T>
class Race{
public:
  // Name: Race (Default Constructor)
  // Preconditions: Creates a new race using a specific type of
  //                racer (racecar, truck, or formula 1
  // Postconditions: Asks how many cars in the race, inserts specific racer in race
  //                 and starts race. Also, srand(RAND_SEED) in constructor.
  Race();
  // Name: EnterRace
  // Preconditions: Has a race
  // Postconditions: Pushes the specific racer into the race
  void EnterRace(T newEntrant);
  // Name: StartRace
  // Preconditions: Has a race
  // Postconditions: Manages a race
  // Requests number of laps.
  // For each lap, checks to see if they crash (calls CheckCrash)
  // Then compares speed of each racer, if one racer is faster, swaps racers
  // At the end of chosen number of laps, the winner is who is in front
  void StartRace();
  // Name: GetRandomRacer
  // Preconditions: Has an array of names and numbers
  // Postconditions: Returns a random number from array of names/numbers
  int GetRandomRacer();
  // Name: CheckCrash
  // Preconditions: Has a race
  // Postconditions: Checks if a racer crashes (1/200 chance), if they crash speed = 0
  //          SetIsCrashed changes, Indicates crash, moves crashed racer to end of race
  void CheckCrash(int);
  // Name: RacerSpeed
  // Preconditions: Has a race and racers left in race
  // Postconditions: Calculates updated speed for a specific racer each lap
  void RacerSpeed(int);
  // Name: DisplayRacers
  // Preconditions: Has a race and racers left in race
  // Postconditions: Displays each racer in race (including if they crashed)
  void DisplayRacers();
private:
  Lqueue<T> race;
};

#endif

//***************************************************************************
//***********************Implement Race Here*********************************


//Don't forget to seed srand with 10 srand(RAND_SEED)


  // Name: Race (Default Constructor)
  // Preconditions: Creates a new race using a specific type of
  //                racer (racecar, truck, or formula 1
  // Postconditions: Asks how many cars in the race, inserts specific racer in race
  //                 and starts race. Also, srand(RAND_SEED) in constructor.
  template<class T>  
  Race<T>::Race(){

    // seed rand
    srand(RAND_SEED);

    int numberOfRacer;

    // this is for getting a random name for each car
    int randName;

    // this is for geeting a rand number for car
    int randNum;

    // valid input for numbe of racer
    do{ 

      cout<<"How many racers would you like in the race?(2-100)\n";
      cin>>numberOfRacer;
      

    }while((numberOfRacer < MIN_RACERS) || (numberOfRacer > MAX_RACERS));


    for(int i = 0;i < numberOfRacer; i++){

      // reason randName and randNumb is in her so it can get new value each time
      randName = GetRandomRacer();

      randNum = GetRandomRacer();




      // setting values and pushing a racer into a the ll
      T newRacer(RACERS[randName],RACE_NUMS[randNum]);

      EnterRace(newRacer);

      
      // seting the crashing values
      race[i].SetIsCrashed(false);      
    }
    

    //starting the race
    StartRace();


  }
  // Name: EnterRace
  // Preconditions: Has a race
  // Postconditions: Pushes the specific racer into the race
  template<class T>
  void Race<T>::EnterRace(T newEntrant){

    race.Push(newEntrant);
    
  }
  // Name: StartRace
  // Preconditions: Has a race
  // Postconditions: Manages a race
  // Requests number of laps.
  // For each lap, checks to see if they crash (calls CheckCrash)
  // Then compares speed of each racer, if one racer is faster, swaps racers
  // At the end of chosen number of laps, the winner is who is in front
  template<class T>
  void Race<T>::StartRace(){

    //displaying the racer at the beginning
    cout<<"Pole Positions\n";
    DisplayRacers();

    
    int lapNumber;

    // user valid input
    do{

      cout << "How many laps would you like to do?(1-1000)\n";

      cin >> lapNumber;


    }while((lapNumber < 1) || (lapNumber > 1000));

   

    //this will simulate the lap
    for(int i = 1 ; i <= lapNumber; i++){
     

      //this will simulate each scenario for the racer
      for(int j = 0; j < race.GetSize(); j++){

        //checking to is if iscrashed is true
        if(race[j].GetIsCrashed() == false){

          CheckCrash(j);

          RacerSpeed(j);


        }
        //swaping speed again
        //makeing sure we are not swaping m_head  .
        if(j != 0) {

          //switching speed comparing the index to the previous 
          if(race[j].GetSpeed() > race[j - 1].GetSpeed()){

            //swaping racer
            race.Swap(j);


          }


        }


      }

      //printing out lap number for the user
      cout << "Lap:" << i << "\n";

      //displaying Racer
      DisplayRacers();

      


    }
    // displaying winner
    cout<<"The winner of the race is "<<race.Front()<<"\n";


  }
  // Name: GetRandomRacer
  // Preconditions: Has an array of names and numbers
  // Postconditions: Returns a random number from array of names/numbers
  template<class T>
  int Race<T>::GetRandomRacer(){
    // index of the of the array, max_racer is minus 1 because it is the array index
    int randNum = rand() % (MAX_RACERS-1) + 0;


    return randNum;


  }
  // Name: CheckCrash
  // Preconditions: Has a race
  // Postconditions: Checks if a racer crashes (1/200 chance), if they crash speed = 0
  //          SetIsCrashed changes, Indicates crash, moves crashed racer to end of race
  template<class T>
  void Race<T>::CheckCrash(int index){
    
    
    // rand will have a range of 200 to 1 if the value is 1 then the racer crash 
    int isCrashed =  rand()% 200 + 1;

    if(isCrashed == 1){

      // setting racer speed to 0 and putting racer at the end
      race[index].SetSpeed(0);

      // changing ischrashed to true
      race[index].SetIsCrashed(true);

      //outputing crash 
      cout<<"CRASH! ! ! "<<race[index].ToString()<<" "<<race[index].GetName()<<" has crashed and is out of the race\n";
      
      // i do not need to swap the tail
      if(index != race.GetSize()-1){
        race.RemoveInsertEnd(index);
      }
    }


  }
  // Name: RacerSpeed
  // Preconditions: Has a race and racers left in race
  // Postconditions: Calculates updated speed for a specific racer each lap
  template<class T>
  void Race<T>::RacerSpeed(int index){

    // if the vaule is a 1 the it decrease if the value is a 2 it increase
    int increaseOrDecrease = rand()% 2 + 1;

    int currentSpeed = race[index].GetSpeed();

    // this the spped the racer will increase or decrease by this number
    int speedIcreaseOrDecrease = (SPEED_MOD*currentSpeed)/100;

    
    
    // increaseing car speed
      if(increaseOrDecrease == 2){

      
        race[index].SetSpeed(currentSpeed + speedIcreaseOrDecrease );

      }
      //decreaseing this make sure the speed will never be lest then 0
      else if (((currentSpeed - speedIcreaseOrDecrease) > 0) and speedIcreaseOrDecrease == 1 ){

       race[index].SetSpeed(currentSpeed - speedIcreaseOrDecrease);

      }

    

    
    //makeing sure we are not swaping m_head  .
    if(index != 0) {

      //switching speed comparing the index to the previous 
      if(race[index].GetSpeed() > race[index -1].GetSpeed()){

        //swaping racer
        race.Swap(index);


      }



    }



  }
  // Name: DisplayRacers
  // Preconditions: Has a race and racers left in race
  // Postconditions: Displays each racer in race (including if they crashed)
  template<class T>
  void Race<T>::DisplayRacers(){

    
    // will go through each node in Lqueue and display it's vaule
    //race.Display();

    for(int i = 0; i < race.GetSize(); i++){

      // this will display cars that have not crash
      if(race[i].GetIsCrashed() == false){

        cout<<race[i];


      }
      // this will only diplay crash car out put
      else{

        cout<<race[i].ToString()<<" "<<race[i].GetName()<<" has crashed and is out of the race\n";


      }

      

    }

     



    



  }

