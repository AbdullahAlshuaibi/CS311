//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application
//Your name: ** Abdullah Alshuaibi
//Complier:  ** g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: ** doing math operations by using stack
//Algorithm: **
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-1
	 int x = int(item)-48; // convert char to integer 
	 if (x >=0 && x <= 9) // Pushing just numbers from 0-9
	   {  
	     postfixstack.push(x); // push the value of x into stack
	   }	 
	 else if((item == '*') || (item == '+') || (item == '-')) // if item is an operator, do the operation between the two integer 
	   {
	     int result; // result of operation 
	     postfixstack.pop(box1); // pop to get top integer
	     postfixstack.pop(box2); // pop to get next integer
	     if(item == '*') // product
	       {
		 result = box1 * box2;
		 postfixstack.push(result); //pushing the result to the stack
	       }
	     else if(item == '+') //addition 
	       {
		 result = box1 + box2;
		 postfixstack.push(result); //pushing the result to the stack
	       }
	     else if(item == '-') // subtraction
	       {
		 result = box2 - box1;
		 postfixstack.push(result);
	       } 
	   }
	 else 
	   { cout<<"Invalid Elemnt"<<endl; exit(1);} //if item is symbols or letters, exit program

	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cout<< "expression too long"<<endl; exit(1); }
      catch (stack::Underflow)
	{ cout<< "too few operands"<<endl; exit(1);}
      catch (char const* errormsg ) // for invalid item case
	{cout<< "invalid item"<<endl; exit(1); }

     postfixstack.displayAll();
      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  int finalResult;
  postfixstack.pop(finalResult);
  
  
 // If anything is left on the stack, an incomplete expression // was found so inform the user.
  if( postfixstack.isEmpty() == false) {
    cout<< "an incomplete expression"<<endl; exit(1);}
    
  postfixstack.displayAll();
  cout<<"the answer is "<<finalResult<<endl; //output the final answer

 
   

}// end of the program
