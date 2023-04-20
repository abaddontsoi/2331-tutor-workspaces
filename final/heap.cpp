#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printHeap(vector<int> heap){
    for (int i = 1; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
}

void heapify(vector<int> &heap){
    int heap_size = heap.size()-1;
    for (int i = (heap_size-1)/2; i > 0; i--)
    {
        int min = i;
        if (heap[2*i] < heap[min])
        {
            min = 2*i;
        }
        if (heap[2*i+1] < heap[min])
        {
            min = 2*i+1;
        }

        // swap the selected parent node with the mininum element between it and its child(ren)
        int temp;
        temp = heap[min];
        heap[min] = heap[i];
        heap[i] = temp;
    }
}
int main(){
    string f_n;
    cout << "File name?:";
    cin >> f_n;
    ifstream f(f_n);
    if (!f.is_open())
    {
        exit(0);
    }

    vector<int> heap;
    heap.push_back(-1);
    int size;
    f >> size;
    for(int i = 0; i<size; i++)
    {
        int x ;
        f >> x;
        heap.push_back(x);
    }
    heapify(heap);
    printHeap(heap);
    return 0;
}