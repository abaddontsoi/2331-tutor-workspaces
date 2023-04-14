#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct node{
    int number;
    bool visited;
};


void printVec(vector< vector<int> > adj){
    int size = adj[0].size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

}

vector< vector<int> > readArr(istream &f, vector<int> &nodes){
    int size;
    f >> size;
    for (int i = 0; i < size; i++)
    {
        nodes.push_back(1);
    }
    vector<vector<int> > adj(size, vector<int> (size,0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            f >> adj[i][j];
        }
    }
    f.clear();
    return adj;
}

void DFS_non_re(int starting, vector<vector<int> > adj){
}

void DFS_re(int starting, vector<vector<int> > &adj, vector<int> &nodes){
    cout << starting<<" ";
    nodes[starting] = 0;
    for (int i = 0; i < adj[starting].size(); i++)
    {
        // cout << "adj["<< starting<<"]["<<i<<"] is " << adj[starting][i]<<endl;
        if (adj[starting][i])
        {
            if(adj[starting][i]==1 && nodes[i]){
                adj[starting][i] = -1;
                // nodes[i] = 0;
                DFS_re(i, adj, nodes);
            } else if(adj[starting][i]==-1 || !nodes[i])
                return;
            // vector<vector<int> > temp = adj;
            // temp[starting][i] = 0;
            // DFS_re(i, temp);   
        }
    }
}

int main(){
    string db;
    cout << "file name: ";
    cin >> db;
    ifstream f(db);
    if(!f.is_open()){
        cout << "not found\n";
        exit(0);
    }
    int size = 0;
    vector<int> nodes;
    vector< vector<int> > adj = readArr(f, nodes);
    printVec(adj);


    int starting;
    cout << "starting node? ";
    cin >> starting;
    DFS_non_re(starting, adj);
    cout << "\n";
    DFS_re(starting, adj, nodes);
    cout << "\n";
    return 0;
}