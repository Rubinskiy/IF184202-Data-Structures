#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

// Function to find the highest weighted route from 'a' to 'b' in the graph using Prim's algorithm
int findHighestWeightedRoute(vector<vector<Edge>>& graph, int a, int b, Edge& highestEdge) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> maxWeight(numVertices, numeric_limits<int>::min());
    vector<Edge> parent(numVertices, {0, 0});
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, a});
    maxWeight[a] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        visited[u] = true;
        
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;
            
            if (!visited[v] && weight > maxWeight[v]) {
                maxWeight[v] = weight;
                parent[v] = {u, weight};
                pq.push({weight, v});
            }
        }
    }
    
    int totalWeight = 0;
    int currentVertex = b;
    while (currentVertex != a) {
        if (parent[currentVertex].weight > highestEdge.weight) {
            highestEdge = parent[currentVertex];
        }
        totalWeight += parent[currentVertex].weight;
        currentVertex = parent[currentVertex].destination;
    }
    
    return totalWeight;
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    vector<vector<Edge>> graph(numVertices + 1);

    int numEdges, start = 0, finish = 0;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        if (i == 0) {
            start = source;
        }
        if (i == numEdges - 1) {
            finish = destination;
        }
        graph[source].push_back({destination, weight});
        graph[destination].push_back({source, weight});
    }

    Edge highestEdge = {0, 0};
    int totalWeight = findHighestWeightedRoute(graph, start, finish, highestEdge);

    cout << "Total weight of the highest weighted route: " << totalWeight << endl;
    cout << "Highest edge on the route: (" << highestEdge.destination << ", " << highestEdge.weight << ")" << endl;

    return 0;
}
