//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Abdullah Alshuaibi
// File type: client hw7client.cpp 
//==========================================

// Be sure to include dgraph, slist and stack

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
#include <iostream>
#include "dgraph.h"
#include "stack.h"
#include <stdlib.h>

int main()
{
  // use the algorithm (read carefully) in the HW7
  // assignment sheet
  slist ll;  // llist object 
  dgraph G;
  G.fillTable();   //fill the table
  G.displayGraph(); //display the G table

  stack S;      // the stack object 
  S.push('A');  // Push A into stack as start

  int i =1; //visit number
  while(S.isEmpty() == false) // while the stack isn't empty
    {
      char V; 
      S.pop(V);  //delete the top element from stack 
      cout<<"Removed "<<V<<" from stack"<<endl; 
      int iV = (int)V - 65;
      ll = G.findAdjacency(V);
      if(G.isMarked(V) == false) //vertext hasn't been visited yet
	{
	  G.visit(i,V);  //update visit 
	  cout<<"Visit "<<V<<" as "<<i<<endl;
	  
	  if(ll.isEmpty()) //if the adjacent is empty 
	    cout<<"Deadend reached - backup."<<endl; 

	  else
	    { cout<<"...pushing ";
	      ll.displayAll();
					      
	      char SV;
	      while(ll.isEmpty() == false)
		{
		  ll.deleteRear(SV); 
		  S.push(SV);
		}
	    }
	  i++; //increment the visit number 
	}

      else // if vertext is already visited 
	{
	  cout<<V<<" had been visited already - backup."<<endl;
	} 

      cout<<"Stack is:"<<endl;
      S.displayAll(); //display stack
    
    }
  cout<<"-------------------"<<endl<<"  Out Visit Adj"<<endl<<"-------------------"<<endl;
  G.displayGraph(); //display the G table after updating the visit 

}
