//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Abdullah Alshuaibi
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef char el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // return true if there are no nodes. else return false
  bool isEmpty();
    
  //display element in each node
  void displayAll();

  // adding a node in the front 
  void addFront(el_t);
    
  //adding a node to the rear 
  void addRear(el_t);

  //deleting a node from the front 
  void deleteFront(el_t&);
    
  //deleting a node from the rear
  void deleteRear(el_t&);
    
  //deleting a specific node
  void deleteIth(int, el_t&);

  //adding a node at a specific place 
  void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);
  
  //Overloading of = 
  llist& operator=(const llist&); 

};
