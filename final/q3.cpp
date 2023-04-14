#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define WHITE 1
#define GREEN 0
#define RED -1

using namespace std;

struct node{
    int name;
    bool visited;
    int BFS_status; //only accessed by BFS function
    int BFS_distance;
    node* BFS_parent;
    node(int name, bool visited): name(name), visited(false), BFS_status(WHITE), BFS_distance(0), BFS_parent(NULL){}
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
        nodes[i].BFS_status = WHITE;
        nodes[i].BFS_distance = 0;
        nodes[i].BFS_parent = NULL;
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

void printVec(vector<node> nodes){
    for (node i : nodes)
    {
        cout << i.name << " ";
    }
    cout << "\n";
}

void printAdj(vector<vector<int> > adj){
    int size = adj.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << adj[i][j]<< " ";
        }
        cout << "\n";
    }
}

// do not change the adjancency matrix while DFSing
// DFS with recursion technique
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

void DFS_non_re(vector<vector<int> > adj, vector<node> &nodes, int starting){
    vector<node> S;
    vector<node> D;
    S.push_back(nodes[starting]);
    while (!S.empty())
    {
        node v = S.back();
        S.pop_back();
        if(!v.visited){
            D.push_back(v);
            v.visited = true;
        }
        for (int i = 0; i < adj.size(); i++)
        {
            if(adj[v.name][i] && !nodes[i].visited){
                S.push_back(nodes[i]);
            }
        }
    }
    printVec(D);
}

void BFS(vector<vector<int> > adj, vector<node> &nodes, int starting){
    nodes[starting].BFS_distance = 0;
    nodes[starting].BFS_parent = NULL;
    vector<node> Q;
    vector<node> D;
    Q.push_back(nodes[starting]);
    
    while (!Q.empty())
    {
        node v = Q[0];
        Q.erase(Q.begin());
        D.push_back(v);
        v.BFS_status = RED;
        for(int i = 0; i < adj.size(); i++){
            if (adj[v.name][i] && nodes[i].BFS_status == WHITE)
            {
                /* code */
                Q.push_back(nodes[i]);
                nodes[i].BFS_status = GREEN;
                nodes[i].BFS_distance = v.BFS_distance + 1;
                nodes[i].BFS_parent = &v;
            }
        }
    }
    printVec(D);
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
        if(starting == -1)
            break; //exit from the program
        cout << "DFS result with recursion implementation: ";
        DFS_re(adj, list, starting);
        resetNodes(list);
        cout << "\n";

        cout << "DFS result with non-recursion implementation: ";
        DFS_non_re(adj, list, starting);
        resetNodes(list);
        cout << "\n";

        cout << "BFS result with non-recursion implementation: ";
        BFS(adj, list, starting);
        resetNodes(list);
        cout << "\n";
    }
    
    f.close();
    return 0;
}