//=========================================================
//HW#: HW3P1 slist
//Your name: Abdullah Alshuaibi
//Complier:  g++
//File type: Implementation file  slist.cpp
//===========================================================

using namespace std;
#include "slist.h"
#include<iostream>

slist::slist() // constructor. cout "in slist constructor".
{}// Make it do nothing else.
// Experiment and see what happens.
// Taking this out completely would not work.
// But note that there is no destructor.
// PLEASE DO NOT delete the couts in slist and llist
// constructors and destructors for HW6!!!!!


// search through the list to see if any node contains the key.
// If so, return its position (>=1). Otherwise, return 0.
int slist::search(el_t key)
{
  Node *P;
  P = Front; //p points to front's node
  int count = 1;
  while(P!= NULL) // when P is pointing to a node
    {
      if(P->Elem == key)
	{return count;}  // return the position of the node P points to 
      else
	{
	  P=P->Next;          // p points to next node
	  count++;
	}
    }
  
  return 0;

}

el_t slist::search2(el_t k)
{
  Node *P;
  P = Front; //p points to front's node
  //int count = 1;
  while(P!= NULL) // when P is pointing to a node
    {
      if(P->Elem == k) 
        {return P->Elem;}  // return the element of the node P
      else
        {
          P=P->Next;          // p points to next node
          //count++;
        }
    }
  el_t notfound; //blank, 
  return notfound;

}


// go to the Ith node (if I is between 1 and Count) and
// replace the element there with the new element.
// If I was an illegal value, throw OutOfRange
void slist::replace(el_t newNum,  int I)
{
  if(I >= Count+1 || I <= 0)    
    throw OutOfRange();
  else if(I == 1)
    {
      Front->Elem = newNum;
    }
  else
    {
      Node *P;
      P = Front;
      for(int k=1; k<I; k++)
        {
          P = P->Next;
        }
      P->Elem = newNum;
    }

}

// checks to see of the two lists look the same
bool slist::operator==(const slist& otherOne)
{
  Node *P;
  P = Front;
  Node *Q;
  Q = otherOne.Front;
 

  if(this->Count == 0 &&  otherOne.Count == 0)     //if both objects are empty return true
    return true;
      
  else if(this->Count == otherOne.Count) //if both have equal nodes  
    {
      while(P != NULL && Q != NULL)
	{
	  
	  if(P->Elem == Q->Elem) //if element == to the elemnt of the other object (same poisition)
	    {
	      P = P->Next;
	      Q = Q->Next;
	    }
	  else
	    return false;  // if the two elements are not equal return false
	}
      return true; // both objects are equal
    }
  else
    return false; // if the two objects don't have the same numbers of nodes return false 
    



}
