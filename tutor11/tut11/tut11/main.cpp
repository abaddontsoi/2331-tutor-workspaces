#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<fstream>

using namespace std;
const int T_S = 200;
const string noResult = "No result";
class HashTableEntry {
   public:
      int k;
      string v;
      HashTableEntry(int k, string v) {
         this->k= k;
         this->v = v;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int k) {
         return k % T_S;
      }
      void Insert(int k, string v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, v);
      }
      string SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return noResult;
         else
            return t[h]->v;
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
int main() {
    HashMapTable hash;
    int k;
    string v;
    string fileName;
    cout<< "Please input the file name: " << endl;
    cin>>fileName;
    // TODO: store the record in the hash table
    int tableSize=0;
    ifstream f(fileName);
    if (!f.is_open()) {
        cout << "Database doesnt exist.\n";
    } else {
        f>>tableSize;
    }
    for (int i = 0; i<tableSize; i++) {
        int key;
        string val;
        
        f >> key;
        f >> val;
        hash.Insert(key, val);
    }

    while (1) {
        int c = 0;
        cout<<"1.Search element from the key"<<endl;
        cout<<"2.Exit"<<endl;
        cout<<"Enter your key: ";
        cin>>c;
        if (!cin>>c) {
            continue;
        }else {
            switch(c) {
                case 1:
                    cout<<"Enter key of the element to be searched: ";
                    cin>>k;
                    // TODO: implement the function of searching a value by key
                    cout << "The search result is: " << hash.SearchKey(k)<<endl;
                    break;
                case 2:
                    exit(1);
                    break;
            }
        }

    }



    // example of using the hash table
    /*
    HashMapTable hash;
    int k, v;
    int c;

    hash.Insert(k, v);
    hash.SearchKey(k);
    */
    return 0;
}
