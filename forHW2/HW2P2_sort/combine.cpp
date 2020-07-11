using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: **
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int ia = 0; // index for A
  int ib = 0; // index for B
 
  while(ia <  A.size() && ib < B.size())  // go inside the loop until ia becomes = A.size or ib becomes = B.size, so that means all the element of A or B were put in R
    {
      if(A[ia] < B[ib]) // if Elemnt in A less than Elemnt in B
	{
	  R.push_back(A[ia]);  // If true, put the element in R 
	  ia++;  // inrement ia 
	}
      else //if false ( element of A larger than elemnt in B 
	{
	  R.push_back(B[ib]); // Put element of B in R 
	  ib++; // increment ib
	}
    
     cout << "comparison" << endl;
    }
  if(ia < A.size()) // Means there are still elements in A  
    {
      while(ia != A.size()) 
	{
	  R.push_back(A[ia]);
          ia++;
	}
    }
  else if(ib < B.size()) // means There are still elements in B
    {
      while(ib != B.size())
	{
	  R.push_back(B[ib]);
          ib++;
	}
    }

}


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
