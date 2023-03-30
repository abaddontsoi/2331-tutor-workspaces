//   test driver for heap, ignores index 0
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;


// short integer random number generator from stdlib
int rand(void); 
void Heap_insert(vector<int> &H, int x, int size) {
  int i = size + 1;
  while (i > 1 && H[i>>1] < x) {
    H[i] = H[i>>1];
    i = i >> 1;
  }
  H[i] = x;

}
void Heapify(vector<int> &H, int i, int size) {

}

void Heapsort(vector<int> &H, int i, int size) {

}


int main()
{ 
  int size;
  cout << endl << "How many elements in the input array ";  cin >> size;
  vector<int> dataArray(size+1);   // get array of right size (with invisible 0th element)

  
  // fill array -- fill 0th element but don't show it.
  for (int k=0; k< size+1 ; k++)  {dataArray2[k] = dataArray[k]=rand();} 
  cout<<"Input array:\n";
  for (int k=1; k<size+1; k++)
    cout<<dataArray[k]<<" ";
  cout<<endl;

  // ============= implement your code here or call it as a function======
 
  // TODO: build a heap for dataArray using heapify
 
 

  //show array
  cout<<"Heap built from the input array using heapify:\n";
  for (int k=1; k<size+1; k++)
    cout<<dataArray[k]<<" ";
  cout<<endl;


  // TODO: sort the array using heap sort
  
  
  //show array
  cout<<"The results of heap sort:\n";
  for (int k=1; k<size+1; k++)
    cout<<dataArray[k]<<" ";
  cout<<endl;
}


