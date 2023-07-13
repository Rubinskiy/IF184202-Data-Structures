#include <iostream>
#include <vector>

using namespace std;

// Graph class using adjacency list representation
class Graph {
private:
    int numNodes;
    vector<vector<int>> adjList;

public:
    Graph(int nodes) : numNodes(nodes), adjList(nodes) {}

    // Add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    // Print nodes connected to a given node
    void printConnectedNodes(int node) {
        cout << "Nodes connected to node " << node << ": ";
        for (int connectedNode : adjList[node]) {
            cout << connectedNode << " ";
        }
        cout << endl;
    }

    // Check if its possible to go from node a to b
    bool canGoFromTo(int a, int b) {
        if (a == b) {
            return true;
        }
        vector<int> visited(numNodes, 0);
        vector<int> queue;
        queue.push_back(a);
        visited[a] = 1;
        while (!queue.empty()) {
            int curr = queue.front();
            queue.erase(queue.begin());
            for (int next : adjList[curr]) {
                if (next == b) {
                    return true;
                }
                if (!visited[next]) {
                    visited[next] = 1;
                    queue.push_back(next);
                }
            }
        }
        return false;
    }
};

struct road {
    int a, b;
};

int main() {
    // Input v, e, s, d
    int v, e, s, d;
    cin >> v >> e >> s >> d;

    // Create a graph with e nodes
    Graph graph(e);

    // 
    vector<road> roads(e);
    vector<int> deliveryPoints(d);

    // Input edges
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }
    
    // Input source and destination
    for (int i = 0; i < d; i++) {
        cin >> deliveryPoints[i];
    }
    
    vector<int> noobPackages;
    for (int i = 0; i < deliveryPoints.size(); i++) {
        if (!graph.canGoFromTo(s, deliveryPoints[i])) {
            noobPackages.push_back(deliveryPoints[i]);
        }
    }

    if (noobPackages.size() > 0) {
        cout << "Packages to be delivered tomorrow:";
        for (int i = 0; i < noobPackages.size(); i++) {
            cout << " " << noobPackages[i];
        }
    } else {
        cout << "All packages are delivered today!" << endl;
    }

    // Print nodes connected to node 1
    //graph.printConnectedNodes(7);

    return 0;
}
