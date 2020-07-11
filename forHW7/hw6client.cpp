// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Abdullah Alshuaibi
// File type:  client file 
// ================================================
#include <iostream>
#include "dgraph.h"
#include <stdlib.h>
int main()
{ 
  dgraph G;
  G.fillTable();
  G.displayGraph();

  cout<<"Enter a vertex name or 0 to exit: ";
  char V;
  cin>>V;

    while (V != '0')
      { 
	try{
	  int outD = G.findOutDegree(V);
	  cout<<outD<<" edges comes out to."<<endl;
	  
	  slist ll;
	  ll = G.findAdjacency(V);
	  ll.displayAll();
	}
	catch(dgraph::BadVertex)
	  { cout<<"no such vertex exists"<<endl<<endl;}
      
      
      cout<<"Enter a vertex name or 0 to exit: ";
      cin>>V;
    }

}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
