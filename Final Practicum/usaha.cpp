#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define lld long long int
//typedef vector<vector<lld>> Graph;
using namespace std;

void shortest_route(vector<vector<lld>>& graph, vector<lld>& distances, lld start) {
    queue<lld> q;
    q.push(start);
    while (!q.empty()) {
        lld curr = q.front();
        q.pop();
        for (lld i = 0; i < graph[curr].size(); i++) {
            if (distances[graph[curr][i]] == 0) {
                distances[graph[curr][i]] = distances[curr] + 1;
                q.push(graph[curr][i]);
            }
        }
    }
}

int main() {
    lld n;
    cin >> n;
    vector<vector<lld>> graph(n);
    for (int i = 0; i < n; 1) {
        lld a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) {
            break;
        }
        graph[a].push_back(b);
    }
    for (lld point = 0; point < n; point++) {
        vector<lld> distances;
        lld gs = graph.size();
        distances.assign(gs, 0);
        distances[point] = 0;
        shortest_route(graph, distances, point);
        
        // print everything
        if (distances[point] != 0) {
            //cout << "bisa pulang mamah" << endl;
            // for (int i = 0; i < distances.size(); i++) {
            //     cout << distances[i] << endl;
            // }
            cout << distances[point] << endl;
        } else {
            cout << "gak bisa pulang mamah" << endl;
        }
    }
    return 0;
}