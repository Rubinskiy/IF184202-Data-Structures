#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

// Function to perform topological sorting using DFS
void topologicalSort(int v, vector<bool>& visited, vector<vector<Edge>>& graph, vector<int>& sorted) {
    visited[v] = true;

    for (const Edge& edge : graph[v]) {
        if (!visited[edge.destination]) {
            topologicalSort(edge.destination, visited, graph, sorted);
        }
    }

    sorted.push_back(v);
}

// Function to find the longest path from 'a' to 'b' in the graph
int findLongestPath(vector<vector<Edge>>& graph, int a, int b) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> sorted;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            topologicalSort(i, visited, graph, sorted);
        }
    }

    vector<int> dist(numVertices, numeric_limits<int>::min());
    dist[a] = 0;

    for (int i = sorted.size() - 1; i >= 0; i--) {
        int u = sorted[i];

        if (dist[u] != numeric_limits<int>::min()) {
            for (const Edge& edge : graph[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                if (dist[u] + weight > dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    return dist[b];
}

// Function to find the highest weighted route from 'a' to 'b' in the graph
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

    int totalWeight = findLongestPath(graph, a, b);
    int currentVertex = b;
    while (currentVertex != a) {
        if (parent[currentVertex].weight > highestEdge.weight) {
            highestEdge = parent[currentVertex];
        }
        currentVertex = parent[currentVertex].destination;
    }

    return totalWeight;
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    vector<vector<Edge>> graph(numVertices);

    int numEdges;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
        graph[destination].push_back({source, weight}); // Undirected graph
    }

    int source, destination;
    cout << "Enter the source and destination vertices: ";
    cin >> source >> destination;

    Edge highestEdge = {0, 0};
    int totalWeight = findHighestWeightedRoute(graph, source, destination, highestEdge);

    cout << "Total weight of the longest path: " << totalWeight << endl;
    cout << "Highest edge on the route: (" << highestEdge.destination << ", " << highestEdge.weight << ")" << endl;

    return 0;
}
