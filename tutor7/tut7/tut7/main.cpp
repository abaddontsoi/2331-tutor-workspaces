//
//  main.cpp
//  tut7
//
//  Created by abaddon on 2/3/2023.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void printV(vector<int> li, int leng){
    for (int i =0; i<leng; i++) {
        cout << li[i] << " ";
    }
    cout << endl;
}

void pivot(vector<int> &li, int f, int l){
    
}

void quick_sort(vector<int> &data, int p, int r){
    int piv, low, high, q;
    
    piv = p;
    low = p+1;
    high = r;
    
    if (p>=r) {
        return;
    }
    
    while (low < high){
        while (data[low] <= data[piv] && low < r) {
            low++;
        }
        while (data[high] > data[piv] && high > p) {
            high--;
        }
        if(low<high){
            int temp;
            temp  = data[low];
            data[low] = data[high];
            data[high] = temp;
        }
    }
    if (data[piv] > data[high]) {
        int temp;
        temp = data[piv];
        data[piv] = data[high];
        data[high] = temp;
    }
    q = high;
    cout << "quick_sort(data, " << p << ", "<<q-1<<")\n";
    quick_sort(data, p, q-1);
    cout << "quick_sort(data, " << q+1 << ", "<<r<<")\n";
    quick_sort(data, q+1, r);
}

int main(int argc, const char * argv[]) {
    ifstream f1("data1.txt");
    vector<int> list;
    if (!f1.is_open()) {
        cout << "data1.txt not exist.\n";
        return 0;
    }
    
    while (!f1.eof()) {
        int temp;
        f1 >> temp;
//        cout << "pushing: " << temp<<endl;
        list.push_back(temp);
    }
    int len = list.size();
    quick_sort(list, 0, len);
    printV(list, len);
    
    f1.close();
    return 0;
}
