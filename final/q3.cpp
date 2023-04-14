#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct node{
    int name;
    bool visited;
    node(int name, bool visited): name(name), visited(false){}
};

vector<node> createNodes(int size){
    vector<node> list;
    for (int i = 0; i < size; i++)
    {
        node p(i, false);
        list.push_back(p);
    }
    return list;
}

void resetNodes(vector<node> &nodes){
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i].visited = false;
    }
}

vector<vector<int> > createAdj(int size, ifstream &f){
    vector<vector<int> > adj(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            f >> adj[i][j];
        }
    }
    return adj;
}

void printAdj(vector<vector<int> > adj){
    int size = adj.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << adj[i][j];
        }
    }
}

void DFS_re(vector<vector<int> > adj, vector<node> &nodes, int starting){
    cout << nodes[starting].name << " ";
    int size = nodes.size();
    for (int i = 0; i < size; i++)
    {
        if (adj[starting][i] && !nodes[i].visited)
        {
            nodes[i].visited = true;
            DFS_re(adj, nodes, i);
        }
    }
}

void DFS_non_re(vector<vector<int> > adj, vector<node> nodes, int starting){

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
    f >> size;
    vector<vector<int> > adj = createAdj(size, f);
    vector<node> list = createNodes(size);
    printAdj(adj);

    int starting = 0;
    cout << "starting node? ";
    while (cin>>starting)
    {
        cout << "DFS result with recurrsion implementation: ";
        DFS_re(adj, list, starting);
        resetNodes(list);
        cout << "\n";
    }
    
    f.close();
    return 0;
}