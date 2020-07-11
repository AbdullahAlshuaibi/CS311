using namespace std;
#include <iostream>

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: **
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
int binarySearch(int L[], int x, int first, int last) 
{
  int middle = (last+first)/2; // middle slot of the array 
  
  if(x == L[middle]) // if element looking for in the middle slot return middle
    return middle;       
  else if(first == last) // if first = last and middle is not returned, that means the element isn't found  
    return -1;
  else if(x < L[middle]) // if element smaller  than the element in the middle slot, we discard the slots of middle and larger  
    last = middle - 1;
  else if(x > L[middle]) //  // if element larger than the element in the middle slot, we discard the slots of middle and smaller. 
    first = middle + 1;

  cout << "comparing against an element in slot " << middle << endl;
  
  binarySearch(L, x, first, last); //recursion func 

}


int main()
{ int A[10];
  int e;  // to look for this
  int first = 0; // first slot
  int last = 10-1; //last slot

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, first, last);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}
