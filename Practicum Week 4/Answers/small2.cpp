#include <iostream>
#include <vector>

#define ll long long
using namespace std;

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;
const int INF = 1e9;

ll rows, cols;
ll matrix[MAX_ROWS][MAX_COLS];
bool visited[MAX_ROWS][MAX_COLS];

void exploreIsland(ll row, ll col, ll& islandSize) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || matrix[row][col] == 0) {
        return;
    }
    visited[row][col] = true;
    islandSize++;

    exploreIsland(row - 1, col, islandSize);
    exploreIsland(row + 1, col, islandSize);
    exploreIsland(row, col - 1, islandSize);
    exploreIsland(row, col + 1, islandSize);
    exploreIsland(row - 1, col - 1, islandSize);
    exploreIsland(row - 1, col + 1, islandSize);
    exploreIsland(row + 1, col - 1, islandSize);
    exploreIsland(row + 1, col + 1, islandSize);
}

ll findSmallestIsland() {
    ll smallestIslandSize = INF;

    for (ll i = 0; i < rows; i++) {
        for (ll j = 0; j < cols; j++) {
            if (!visited[i][j] && matrix[i][j] == 1) {
                ll islandSize = 0;
                exploreIsland(i, j, islandSize);
                smallestIslandSize = min(smallestIslandSize, islandSize);
            }
        }
    }
    return smallestIslandSize;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    rows = 10;
    cols = 10;
    for (ll i = 0; i < rows; i++) {
        for (ll j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            visited[i][j] = false;
        }
    }
    ll smallestIsland = findSmallestIsland();
    if (smallestIsland == INF) {
        cout << "There is no island!\n";
    } else {
        cout << "Smallest island is: " << smallestIsland << " km^2\n";
    }
}
