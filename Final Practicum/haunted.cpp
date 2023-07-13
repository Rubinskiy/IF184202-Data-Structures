#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<vector<pll>> Graph;

ll findLeastWeightedRoute(const Graph& graph, ll start) {
    ll n = graph.size() - 1;
    vector<ll> dist(n + 1, INT_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll curEdge = pq.top().second;
        ll maxNode = pq.top().first;
        pq.pop();

        if (maxNode > dist[curEdge]) {
            continue;
        }
        for (const auto& edge : graph[curEdge]) {
            ll v = edge.first;
            ll weight = max(maxNode, edge.second);

            if (weight < dist[v]) {
                dist[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    return dist[n];
}

int main() {
    ll n, m, start = 0, finish = 0;
    cin >> n >> m;

    Graph graph(n + 1);

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

    ll maxWeight = findLeastWeightedRoute(graph, start);
    cout << maxWeight << endl;

    return 0;
}