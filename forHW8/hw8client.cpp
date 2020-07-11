// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Abdullah Alshuaibi
// File type: client hw8client.cpp
//===========================================

using namespace std;
#include <iostream>
#include "htable.h"
//#include "elem.h"
// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{ 
  htable H; //htable object

  int K; //a digit from the user
  string S; //string name the user
  for(int i=1; i<=20; i++) //getting information from the user
    {
      cout<<i<<": Enter the key: ";
      cin>>K;
      cout<<i<<": Enter the string: ";
      cin>>S;

      el_t elem(K, S);
      H.add(elem); //adding the digit and the name to the table 
    }
 
  H.displayTable(); //display the htable


  int F;
  cout<<endl<<"If you don't want to look for an element press 0, else press any number: ";
  cin>>F;

  while(F != 0)
    {
      cout<<"look for? ";
      int Look;
      cin>>Look;

      el_t blank;

      if(H.find(Look) == blank) //if both equal, means the element isn't found 
	cout<<Look<<" not found."<<endl;

      else //if they are different, element found 
	{
	  cout<<"Found "<<Look<<": "<<H.find(Look)<<endl;
	}
    }

 }
