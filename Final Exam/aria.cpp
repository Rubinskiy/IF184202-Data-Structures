#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<vector<pll>> Graph;

// bismillah i hope this solution will get an AC amin

/*ll findHighestWeightedRoute(const Graph& graph, ll start, ll &sum) {
    ll n = graph.size() - 1;
    vector<ll> dist(n + 1, 0);
    priority_queue<pll, vector<pll>, less<pll>> pq;

    dist[1] = INT_MAX; // 0
    pq.push({0, 1}); // 0, 1

    // print everything in graph
    for (ll i = 1; i < graph.size(); i++) {
        cout << i << ": ";
        for (ll j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j].first << " ";
        }
        cout << endl;
    }

    int count = 1;
    while (!pq.empty()) {
        ll curEdge = pq.top().second;
        ll maxNode = pq.top().first;
        pq.pop();
        //cout << "maxnode: " << maxNode << endl;
        if (maxNode > dist[curEdge]) {
            continue;
        }
        for (const auto& edge : graph[curEdge]) {
            ll v = edge.first;
            //cout << "cur: " << v << endl;
            ll weight = max(maxNode, edge.second);
            //cout << "weight: " << weight << endl;
            if (weight > dist[v]) {
                dist[v] = weight;
                pq.push({weight, v});
                cout << "max: " << maxNode << endl;
            }
        }
        count++;
    }
    return dist[n];
}*/

struct Edge {
    ll destination;
    ll weight;
};

ll findHighestRoute(vector<vector<Edge>>& graph, ll start, ll finish, Edge& highestEdge) {
    ll numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<ll> maxWeight(numVertices, numeric_limits<ll>::min());
    vector<Edge> parent(numVertices, {0, 0});
    
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, start});
    maxWeight[start] = 0;

    // print graph
    /*for (ll i = 1; i < graph.size(); i++) {
        cout << i << ": ";
        for (ll j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j].destination << " ";
        }
        cout << endl;
    }*/
    
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        
        visited[u] = true;
        
        for (const Edge& edge : graph[u]) {
            ll v = edge.destination;
            ll weight = edge.weight;
            
            // compare to INT_MAX for the longest path
            if (!visited[v] &&
                max(maxWeight[u], weight) > maxWeight[v]) {
                maxWeight[v] = max(maxWeight[u], weight);
                parent[v] = {u, weight};
                pq.push({maxWeight[v], v});
            }
            
            
        }
    }
    
    ll sum = 0;
    ll v = finish;
    while (v != start) {
        if (parent[v].weight > highestEdge.weight) {
            highestEdge = parent[v];
        }
        sum += parent[v].weight;
        v = parent[v].destination;
    }
    
    return sum;
}

int main() {
    ll n, m, start = 0, finish = 0;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (ll i = 0; i < m; i++) {
        ll source, destination, weight;
        cin >> source >> destination >> weight;
        if (i == 0) {
            start = source;
        }
        if (i == m - 1) {
            finish = destination;
        }
        graph[source].push_back({destination, weight});
        graph[destination].push_back({source, weight});
    }

    ll R;
    cin >> R;
    vector<pair<ll, ll>> bounds;
    for (ll i = 0; i < R; i++) {
        ll lower, upper;
        cin >> lower >> upper;
        bounds.push_back(make_pair(lower, upper));
    }

    Edge highestEdge = {0, 0};
    ll maxWeight = findHighestRoute(graph, start, finish, highestEdge);
    
    for (ll i = 0; i < R; i++) {
        ll lower = bounds[i].first;
        ll upper = bounds[i].second;
        if (lower <= highestEdge.weight && highestEdge.weight <= upper) {
            cout << maxWeight << " " << highestEdge.weight << endl;
        } else {
            cout << "So Long and Good Night" << endl;
        }
    }

    return 0;
}