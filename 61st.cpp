#include<iostream>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<int> *adj; // An array of adjacency vectors

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void print(); // prints BFS traversal from a given source
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s vector.
}

void Graph::print() {
    cout << "Adjacency vector : \n";
    for (int i = 0; i < V; i++) {
        cout << i << "-> ";
        for (auto n : adj[i]) {
            cout << n << "-> ";
        }
        cout << "NULL\n";
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Adjacency vector Representation of the Graph: \n";
    g.print();

    return 0;
}