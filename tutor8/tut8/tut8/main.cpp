//
//  main.cpp
//  tut8
//
//  Created by abaddon on 9/3/2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void printA(int *A, int last){
    for (int i =0; i<last; i++) {
        cout << *(A+i) << " ";
    }
    cout << '\n';
}

int getNumOfNode(int *A, int last){
    int temp = 0;
    for (int i = 0; i<last; i++){
        temp += (*(A+i) != -1);
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    string fileN;
    cout << "file name: ";
    cin >> fileN;
    ifstream f;
    f.open(fileN);
    
    if(!f.is_open()){
        cout << fileN << " not found.\n";
        return 0;
    }
    int ele_count;
    f >> ele_count;
    cout << ele_count<<endl;
    
    int *treeA = new int[ele_count];
    int *in;
    in = treeA;
    while (!f.eof()) {
        f >> *in;
        in++;
    }
//    printA(treeA, ele_count);
    cout << "The number of nodes is " << getNumOfNode(treeA, ele_count)<<endl;
    return 0;
}
