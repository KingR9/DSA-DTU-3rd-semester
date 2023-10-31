#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

void bfs(vector<list<int>> &graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main() {
    vector<list<int> > graph(6);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(4);
    graph[2].push_back(5);

    bfs(graph, 0);

    return 0;
}