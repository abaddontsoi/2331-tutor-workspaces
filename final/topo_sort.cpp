#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct node{
    int number;
    bool visited;
    int distance;
    int indegree, outdegree;
    node(int n, bool v, int d): number(n), visited(v), distance(d), indegree(0), outdegree(0) {}
};

void printVec(vector<node> nodes){
    for(node i: nodes)
        cout << i.number << " ";
    cout << "\n";
}

void resetNodes(vector<node> &nodes){
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i].distance = 0;
        nodes[i].visited = false;
        cout << "Node reset.\n";
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

vector<node> createNodes(int size){
    vector<node> list;
    for (int i = 0; i < size; i++)
    {
        node p(i, false, 0);
        list.push_back(p);
    }
    return list;
}

void setInOutDegree(vector<node> &nodes, vector<vector<int> > adj){
    int size = adj.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(adj[i][j]){
                nodes[i].outdegree++;
                nodes[j].indegree++;
            }
        }
    }
}

void topoSort(vector<node> nodes, vector<vector<int> > adj){
    vector<node> Q;
    vector<node> T;
    for(node i: nodes){
        if(i.indegree == 0){
            Q.push_back(i);
        }
    }

    while(!Q.empty()){
        node v = Q.back();
        Q.pop_back();
        T.push_back(v);
        for(int i = 0; i < adj.size(); i++){
            if(adj[v.number][i]){
                nodes[i].indegree--;
                if(!nodes[i].indegree){
                    Q.push_back(nodes[i]);
                }
            }
        }
    }

    if(T.size()<nodes.size()){
        cout << "This graph is not a DAG\n";
    } else {
        printVec(T);
    }
}

int main(){
    string adjF;
    cout << "adj file name:";
    cin >> adjF;
    ifstream f(adjF);
    if(!f.is_open())
        exit(0);

    int size;
    f >> size;
    vector<node> nodes = createNodes(size);
    vector<vector<int> > adj = createAdj(size, f);

    setInOutDegree(nodes, adj);
    cout << "Result of topology sort: ";
    topoSort(nodes, adj);
    return 0;
}