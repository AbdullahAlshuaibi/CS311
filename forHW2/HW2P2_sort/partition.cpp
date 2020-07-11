#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do.
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Abdullah Alshuaibi
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int beg = f; // pointer from the left
  int end = r; // pointer from the right 
  int temp;
    // loop for finding out of place pairs and swap them
  while(beg <= end) // end program if end less than beg 
    {      	
      if(beg == end) // if beg and end pointing to the same number 
	{
	  if(a[beg] < pivot) // if the number smaller than the pivot increment beg because we want the partition after number that smaller than the pivot.
	    beg++;
	  else // if the number larger than the pivot, decremnt the end to get out of the loop
	    end--;
	}
      else if(a[beg] >= pivot && a[end] < pivot) // if the left number larger or = the pivot and the right number is smaller than the pivot 
	{
	  temp = a[beg]; //swap the left number with the right number 
          a[beg] = a[end];
          a[end] = temp;
          beg++; // increment the left 
          end--; // decremnt the right 
	}
      else if(a[end] >= pivot) // if the right number is larger than the pivot, decremnt the righ because it's at the right place 
	end--;
      else if(a[beg]< pivot) // if the left number is smaller than the pivot, increment the left because it's at the right place.
	beg++;

    }

  cout<<"the left pointer is the " <<beg<<" slot pointing to number "<<a[beg]<<endl;
  cout<<"the right pointer is the "<<end<<" slot pointing to number "<<a[end]<<endl;
  
  // return the partition point where
  if(beg > f)  
    return beg;
  // those smaller than pivot are before what is returned
  else
    return 1;
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
