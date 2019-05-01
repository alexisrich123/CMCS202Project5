/*****************************************
** File:    Lqueue.h
** Project: CMSC 202 Project 5, Fall 2018
** Author:  Alexis Richardson
** Date:    11/22/18
** Section: 02
** E-mail:  alexisr2@umbc.edu 
** description: makes the node and function to run templ node
*********************************************
*/



#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <class T>
class Node {
public:
  Node( const T& data ); //Overloaded constructor
  T& GetData(); //Getter
  void SetData( const T& data ); //Setter
  Node<T>* GetNext(); //Getter
  void SetNext( Node<T>* next ); //Setter
private:
  T m_data; //Data stored in node
  Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

template <class T>
T& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to NULL
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue<T>& operator = (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  void Clear();
  // Name: RemoveInsertEnd
  // Preconditions: Requires a lqueue
  // Postconditions: Moves a node from somewhere to the end of the lqueue
  void RemoveInsertEnd(int);
  // Name: TestHeadTail() (Optional test function)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns the value of the head and the tail (used for main below)
  void TestHeadTail();
  // Name: operator<< (Overloaded << operator)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  friend ostream& operator<<(ostream& output, const Lqueue<U>&);
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};
//*********************************************************************
//******************Implement Lqueue Functions Here********************

  template<class T>
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to NULL
  Lqueue<T>::Lqueue(){
      // starting the the Lqueue by putting every thing to null 
     
      m_head = NULL;
      
      m_tail = NULL;

      m_size = 0;

  }


  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
  template<class T>
 Lqueue<T>::~Lqueue(){

    Lqueue<T>::Clear();
    
   

 }


  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  template<class T>
  Lqueue<T>::Lqueue(const Lqueue& LqueueC){

      //copying m_head to the m_head before
      m_head = NULL;

      
      m_tail = NULL;
      

      m_size = 0;

      // a temp variable to move through the LL and get each Node data
      Node<T> *temp = LqueueC.m_head;

      // pushing LqueueC value in to this Lqueue
      for(int i= 0; i< LqueueC.m_size;i++){

         Push(temp->GetData());

         temp = temp->GetNext();
      }
   
      

      
  }


  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  template<class T>
  Lqueue<T>& Lqueue<T>::operator = (Lqueue<T>& LqueueCopying){
     
     // getting the first node of each Lqueue
     Node<T> *tempTwo = LqueueCopying.m_head;
     
      // clearing the node that i am copying LqueueCOpying to so i can just 
      // push the data into the Lqueue 
      Clear();
      
      // keep on going unitl every value has ben push onto Lqueue
     for(int i = 0; i < LqueueCopying.GetSize(); i ++){
        
         Push(tempTwo->GetData());
      
         
         
         tempTwo = tempTwo->GetNext();


     }


     return *this;
  }

  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  template<class T>
  void Lqueue<T>::Push(const T& racer){

      
      Node<T> *temp = new Node<T>(racer);

      // this is a check, to see if the LL has not been made yet
      if(m_head == NULL){

         // making m_head have a new pointer
         m_head = temp;


         m_tail = temp;

         // setting the data in head
         m_head->SetData(racer);

         m_tail->SetNext(NULL);

         m_size = 1;

      }
      else{

         // tail will aways be poinint to null so temp next is null, then tail will == temp
         temp->SetNext(NULL);

         // moving m_tail to the need of the ll
         m_tail->SetNext(temp);
   
         m_tail = temp;
      

         // seting temp data
         temp->SetData(racer);

         m_size++;
   
   }      
  }



  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  template<class T>
  T Lqueue<T>::Pop(){
      // making a temp so can deleted the first node with out
      // deleting m_head
      Node<T> *temp = m_head;

      T headData = m_head->GetData();


      
      // m_head is being set to next
      m_head = m_head->GetNext();
      

      // deleting temp and making temp to null
      delete temp;

      temp = NULL;

      // decresing size
      m_size--;

      
      // returning m_head data
      return headData;


  }


  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  template<class T>
  void Lqueue<T>::Display(){


     Node<T> *temp = m_head;

      // will keep on displaying data untitl it hit null
     while(temp != NULL){

         cout<<temp->GetData();


         temp = temp->GetNext();
         }
     
     }


  
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front
  template<class T> 
  
  T Lqueue<T>::Front(){
     // since head is alway in fornt, then i can just return the data in head

   return m_head->GetData();
  }



  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  template<class T>
  bool Lqueue<T>::IsEmpty(){
     // will be false until proven true
     bool isEmpty = false;

     if(m_head == NULL){
        isEmpty = true;
     }
     

   return isEmpty;
  }



  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  template<class T>
  int Lqueue<T>::GetSize(){

     return m_size;

  }

  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  template<class T>
  void Lqueue<T>::Swap(int index){
     // will have  to temp that will make the value swapG
     Node<T> *temp = m_head;
     
      
     // the for lop is here to find the node at that index
     // specialy case when need to swap the m_head, and m_tail, and node need to swap
      int i = 0;

      //indexMinusTwo will be two behide switchIndex
      Node<T> *indexMinusTwo = m_head;

      //indexMinusOne will be one behide switchIndex
      Node<T> *indexMinusOne = m_head;


      // will be the curren index
      Node<T> *switchIndex = m_head;  


      // this statment for when index is 1
      if((index == 1) and (index != 0)){

         // the first index after m_head
         indexMinusOne = m_head->GetNext();

         // the second index after m_head
         indexMinusTwo = indexMinusOne->GetNext();

         // m_head is set to the first index after m_head
         m_head = indexMinusOne;

         // m_head next is set to temp(which is alreay set to m_head) 
         m_head->SetNext(temp);

         //temp next -s set to the second index after m_head
         temp->SetNext(indexMinusTwo);


      }

      // this is if the index is tails
      else if((index == m_size-1) and (index != 0)){
         for(int j = 0; j < index; j++ ){

            indexMinusTwo = indexMinusOne;

            indexMinusOne = switchIndex;

            switchIndex = switchIndex->GetNext();


         }
         //this is setting the previous next to current next
         indexMinusOne->SetNext(switchIndex->GetNext());
         
         // this sets the previous of prviou next to current
         indexMinusTwo->SetNext(switchIndex);
         
         // this set current next to indexMinusOne the previous node
         switchIndex->SetNext(indexMinusOne);
         
         // since indexMinusOne is last tail will be set to that
         m_tail = indexMinusOne;
         
         // m_tail next is being set to null
         m_tail->SetNext(NULL);
      }

   
      else if( (index != m_size-1) and (index != 0) ){

         //if the while loop is not at tail and i is lest then index, and index is not 0
         // the loop will keep going
         while((temp->GetNext() != NULL) and (i < index ) and (index != 0) )
         {
            //indexMinusTwo the previous of previous index
            indexMinusTwo = indexMinusOne;

            //indexMinusOne the previous index
            indexMinusOne = switchIndex;

            // the currennt index
            switchIndex = switchIndex->GetNext();
         
      
            // incrementing
            i++;

         

         }


         //set previous next to current next
         indexMinusOne->SetNext(switchIndex->GetNext());


         //set previous next to current
         indexMinusTwo->SetNext(switchIndex);


         // set current next tp previous
         switchIndex->SetNext(indexMinusOne);
   
      }
      




  }


  // Name: Cle= ar
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
 template<class T>
  void Lqueue<T>::Clear(){
   // setting temp and prev
   Node<T> *temp = m_head;

   // prev will be used to delete and set = null
   Node<T> *prev = m_head;

   // making sure ll is not empty
   while(m_size != 0){

      // making sure temp is not tail
      if(temp != m_tail){
         // having prev leading behide
         prev = temp;

         temp = temp->GetNext();

         delete prev;
         // so pointer can be completely free
         prev = NULL;

         m_size--;

      }
      
      else{

         m_size = 0;
      }
      // setting m_head and m_tail = null
      m_head =NULL;
      m_tail = NULL;



   }


  }
  // Name: RemoveInsertEnd
  // Preconditions: Requires a lqueue
  // Postconditions: Moves a node from somewhere to the end of the lqueue
  template<class T>
  void Lqueue<T>::RemoveInsertEnd(int index ){

     // the node that will be save 
     Node <T> *saveNode = m_head;

     Node <T> *temp = m_head;

      // the previious nood
      Node<T> *prev = temp;

      // thie if else stament will check tho see if they want to 
      // swap the begining 
      if(index == 0){
         // moving m_head to the next
         m_head = m_head->GetNext();
         
         // setting save node next to null so it can be the tail
         saveNode->SetNext(NULL);

         // comnexting m_tail node to save node
         m_tail->SetNext(saveNode);
         // the swtiching them
         m_tail = saveNode;


      }



      else{
         // this loop will good through the ll
         for(int i = 0; i < m_size; i++ ){
        
      


            // when the loop reaches the index that needs to be in the end
            // then the loop save the node, and set previous node next to the save node next
            if(i == (index)){

               saveNode = temp;

               prev->SetNext(temp->GetNext());

            }
            // moving through the node 
            prev = temp;
            temp = temp->GetNext();
         }
      
     
         // tail will == save node so save node NEXT must == nUll
          saveNode->SetNext(NULL);
         // comnexting m_tail node to save node
         m_tail->SetNext(saveNode);
         // the swtiching them
         m_tail = saveNode;
      }
  }
  // Name: TestHeadTail() (Optional test function)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns the value of the head and the tail (used for main below)
  template<class T>
  void Lqueue<T>::TestHeadTail(){
     cout<<"head: "<<m_head->GetData()<<" tail "<<m_tail->GetData()<<"\n";


  }


  // Name: operator<< (Overloaded << operator)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  ostream& operator<<(ostream& output, const Lqueue<U>& LqueueC){
     
     Node<U> *temp = LqueueC.m_head;
     
     

     while(temp != NULL){

        output<<temp->GetData()<<"\n";
        

         temp = temp->GetNext();

     }

     return output;

  }
  
  
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  template<class T>
  T& Lqueue<T>::operator[] (int x){

      Node<T> *temp = m_head;
      // will keep on going through the list until it hit the index it is looking for
      for(int i = 0; i < x ; i++){

         temp = temp->GetNext();

      }



      return temp->GetData();


  }




//************************Lqueue Tests Below***************************
// To test just Lqueue follow these instructions:
//   1.  mv Lqueue.h Lqueue.cpp
//   2.  Uncomment out int main below
//   3.  make Lqueue
//   4.  ./Lqueue

/*
int main () {
   
  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Lqueue <int> newLQ1;
  //Push 4 nodes into Lqueue
  newLQ1.Push(10);
  newLQ1.Push(11);
  newLQ1.Push(12);
  newLQ1.Push(13);
  cout << endl;

   
  
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
  //Test Copy constructor
  Lqueue <int> newLQ2(newLQ1);
  //Test Overloaded Assignment Operator
  Lqueue <int> newLQ3;
  
  newLQ3 = newLQ2;


  cout << endl;
 
  
  //Test 3 - Test Display and Overloaded <<
  cout << "Test 3 - Display and Overloaded << Running" << endl;
  cout << "newLQ1" << endl;
  newLQ1.Display();
  cout << "newLQ2" << endl;
  newLQ2.Display();
  cout << "newLQ3" << endl;
  newLQ3.Display();
  cout << "newLQ1" << endl;
  cout << newLQ1;
  cout << "newLQ2" << endl;
  cout << newLQ2;
  cout << "newLQ3" << endl;
  cout << newLQ3;
  cout << endl;
  
   
  //Test 4 - Test Front and Pop
  cout << "Test 4 - Front and Pop Running" << endl;
  //Test Front()
  cout << "Testing Front - Output 10" << endl;
  cout << newLQ1.Front() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  cout << endl;

 
  //Test 5 - Test GetSize and Clear
  cout << "Test 5 - GetSize and Clear Running" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newLQ1.GetSize() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  newLQ1.Clear();
  cout << endl;
   

  //Test 6 - Test Swap
  cout << "Test 6 - Swap Running" << endl;
  newLQ2.Swap(2);

  cout<<"LQ1: "<<newLQ1.GetSize()<<"\n";
  cout<<"LQ2: "<<newLQ2.GetSize()<<"\n";
  
  cout << "Swap 2 - Should display 10->12->11->13->END" << endl;
  newLQ2.Display();
    //Testing to make sure head and tail point at the correct node
  newLQ2.TestHeadTail();
  cout << "Should display head 10 and tail 13" << endl;
  cout << endl;
 
  
  //Test 7 - Test RemoveInsertEnd(2)
  cout << "Test 7 - RemoveInsertEnd Running" << endl;
  cout << "Before RemoveInsertEnd" << endl;
  newLQ3.Display();
  newLQ3.TestHeadTail();
  newLQ3.RemoveInsertEnd(2);
  cout << "After RemoveInsertEnd 10->11->13->12->END" << endl;
  newLQ3.Display();
  newLQ3.TestHeadTail();
  

 
  return 0;
}






*/

