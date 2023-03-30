#include <stdio.h>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void merge(vector<int> & v1, int st, int md, int ed) {
    vector<int> v2; // temperately store the result

    int i = st, j = md + 1;
    while (i <= md && j <= ed) {
        if (v1[i] < v1[j]) {
            v2.push_back(v1[j]);
            j++;
        } else {
            v2.push_back(v1[i]);
            i++;
        }
    }
    while (i <= md) {
        v2.push_back(v1[i]);
        i++;
    }
    while (j <= ed) {
        v2.push_back(v1[j]);
        j++;
    }

    for (int i = 0; i < v2.size(); i++) {
        v1[st + i] = v2[i];
    cout<<v2[i]<<" ";
    }

    cout<<"The current array's content is ";
    for(int i=0; i<v1.size(); i++)
      cout<<v1[i]<<" ";
    cout<<endl;

}
void merge_sort(vector<int> & v1, int st, int ed){

  cout<<"mergeSort(data,"<<st<<","<<ed<<")\n";
  
    if (ed - st > 0) {
        int md = st + ((ed - st)>>1); // equivalent to (st + ed)/2
        merge_sort(v1, st, md);
        merge_sort(v1, md + 1, ed);
        merge(v1, st, md, ed);
    }

}
vector<int> arr;

int main() {
    srand(time(0)); // set the seed of random number
    
    int n;
    printf("Please input N:\n");
    scanf("%d", &n);
    arr.clear();
    for (int i = 0;i<n;i++) {
        int tmp = rand() % (n * 2);
        arr.push_back(tmp);
    }
    printf("The random array is: \n");
    printf("First five: ");
    for (int i = 0;i<5;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("Last five: ");
    for (int i = n - 5;i<n;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    merge_sort(arr, 0, n - 1);
    printf("The sorted array is: \n");
    printf("First five: ");
    for (int i = 0;i<5;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("Last five: ");
    for (int i = n - 5;i<n;i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
