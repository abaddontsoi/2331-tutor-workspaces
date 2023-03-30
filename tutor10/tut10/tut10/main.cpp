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

// if it is used to heapify a completely random array or (or an array that just added an element), starts from the smallest subtree.
// if it is used to heapify a heap that just removed an element, starts from the root.
void Heapify(vector<int> &H, int i) {
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;
    if (l < H.size() && H[l]>H[largest]) {
        largest = l;
    }
    if (r < H.size() && H[r]>H[largest]) {
        largest = r;
    }

    if (largest!=i) {
        // swap h[i], h[largest]
        int temp = H[i];
        H[i] = H[largest];
        H[largest] = temp;

        Heapify(H, largest);
    }
}

void HeapifyS(vector<int> &H, int shift, int i){
    int l = 2*(i-shift)+shift;
    int r = 2*(i-shift)+shift + 1;
    int largest = i;
    if (l < H.size() && H[l]>H[largest]) {
        largest = l;
    }
    if (r < H.size() && H[r]>H[largest]) {
        largest = r;
    }

    if (largest!=i) {
        // swap h[i], h[largest]
        int temp = H[i];
        H[i] = H[largest];
        H[largest] = temp;

        HeapifyS(H, shift, largest);
    }
}

void printV(vector<int> h){
    for (int k=1; k<h.size(); k++)
        cout<<h[k]<<" ";
    cout<<endl;
}

void Heapsort(vector<int> &H, int N) {
    for (int j = 0; j<N; j++) {
        for (int i = H.size(); i > j; i--) {
            HeapifyS(H, j, i);
        }
    }
}


//void Heapsort(vector<int> &H, int N) {
//    for (int j = 0; j<N; j++) {
//        int temp = H[j+1];
//        H[j+1] = H[N-1];
//        H[N-1] = temp;
//        HeapifyS(H, j+1, j+1);
//    }
//}

int main()
{
    int size;
    cout << endl << "How many elements in the input array ";  cin >> size;
    vector<int> dataArray(size+1);   // get array of right size (with invisible 0th element)


    // fill array -- fill 0th element but don't show it.
    for (int k=0; k< size+1 ; k++)  {
        dataArray[k]=rand()%1000;
    }
    cout<<"Input array:\n";
    for (int k=1; k<size+1; k++)
        cout<<dataArray[k]<<" ";
    cout<<endl;

    // ============= implement your code here or call it as a function======

    // TODO: build a heap for dataArray using heapify
    for (int i = size; i > 0; i--) {
        HeapifyS(dataArray, 0, i);
    }


    //show array
    cout<<"Heap built from the input array using heapify:\n";
    for (int k=1; k<size+1; k++)
        cout<<dataArray[k]<<" ";
    cout<<endl;


    // TODO: sort the array using heap sort
    Heapsort(dataArray, size+1);

    //show array
    cout<<"The results of heap sort:\n";
    for (int k=1; k<size+1; k++)
        cout<<dataArray[k]<<" ";
    cout<<endl;
}


