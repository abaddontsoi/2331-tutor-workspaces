/*
   In this week's tutorial, you need to practice recursive programming. The detailed tasks can be found in the following framework. Feel free to resue the code from the first tutorial
 */

//include needed head files and libraries
#include <iostream>
#include <vector>
#include "time.h"
using namespace std;

void printVec(vector<int> list){
    for (int i = 0; i < list.size(); i++) {
        cout << list[i]<< " ";
    }
    cout << endl;
}
/*
  three functions here: insertion sort, binarySearch1, and binarySearch2

 */
void insertionSort(vector<int> &list){
    for (int i = 1; i < list.size(); i++) {
        int j = i - 1;
        int holding = list[i];
        for (j; j>=0 && list[j]>holding; j--) {
            list[j+1] = list[j];
        }
        list[j+1] = holding;
    }
}


int binarySearch1(vector<int> list, int n){
//    this is the loop version
    int posi = -1;
    int head = 0;
    int mid = list.size()/2;
    int end = list.size()-1;
    
    
    if (n > list[end]) {
        return posi;
    }
    if (n < list[head]) {
        return posi;
    }
    
    while (end>=head) {
        int mid = (end+head)/2;
        if (list[mid]==n) {
            return mid;
        }else if (n < list[mid]){
            end = mid -1;
        }else{
            head = mid + 1;
        }
    }
    return posi;
}
int binarySearch2(vector<int> list, int n, int head, int end){
//    this is the recursive version
    if (head > end) {
        return -1;
    }
    int mid = (head+end) / 2;
    if (n == list[mid]) {
        return mid;
    }else if (n < list[mid]){
        return binarySearch2(list, n, head, mid-1);
    }else{
        return binarySearch2(list, n, mid + 1, end);
    }
}

int main()
{
  //ask the user to input an integer n
    int n;
    cout << "please enter n:";
    cin >> n;
    
  //generate n random numbers
    srand(time(NULL));
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        temp.push_back(rand()%(100*i));
    }
//    printVec(temp);
    
  //call insertion sort and sort the n random numbers
  //insertionSort(...)
    insertionSort(temp);
    printVec(temp);

  //ask the user to input a query (an integer)
    int query;
    cout << "enter a query, an integer:";
    cin >> query;

  //call the first function of binary search using loop/iterative implementation
  //binarySearch1(...);
  //print out the search result: not found or the index of the found item
    int posi = binarySearch1(temp, query);
    if (posi==-1) {
        cout << "not found!\n";
    }else {
        cout << "index of the item is " << posi<<endl;
    }

  //call the second function of binary search (recursive implementation)
  //binarySearch2(....);
  //print out the search results: not found or the index of the found item
    posi = binarySearch2(temp, query, 0, temp.size());
    if (posi==-1) {
        cout << "not found!\n";
    }else {
        cout << "index of the item is " << posi<<endl;
    }
}
