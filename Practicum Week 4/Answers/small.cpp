#include <iostream>
#include <vector>
#include <stack>

#define lld long long int
using namespace std;

const lld SIZE = 10;

// structure to represent a cell in the graph
struct Cell {
    lld row;
    lld col;
};

// func to check if a cell is a valid neighbor
bool isValidNeighbor(lld row, lld col, bool visited[][SIZE], const lld graph[][SIZE]) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && !visited[row][col] && graph[row][col] == 1);
}

// Function to perform depth-first search
int dfs(lld row, lld col, bool visited[][SIZE], const lld graph[][SIZE]) {
    // offsets for the neighboring rows (including diagonals)
    static const lld dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // offsets like above for the columns (including diagonals)
    static const lld dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    stack<Cell> stack;
    stack.push({row, col});
    visited[row][col] = true;
    lld islandSize = 0;

    while (!stack.empty()) {
        Cell current = stack.top();
        stack.pop();
        islandSize++;

        for (lld i = 0; i < 8; i++) {
            lld newRow = current.row + dr[i];
            lld newCol = current.col + dc[i];

            if (isValidNeighbor(newRow, newCol, visited, graph)) {
                stack.push({newRow, newCol});
                visited[newRow][newCol] = true;
            }
        }
    }
    return islandSize;
}

// func to find the smallest island in the graph
int findSmallestIsland(const lld graph[][SIZE]) {
    bool visited[SIZE][SIZE] = {false};
    // init with max size
    lld smallestIslandSize = SIZE * SIZE;

    for (lld row = 0; row < SIZE; row++) {
        for (lld col = 0; col < SIZE; col++) {
            if (graph[row][col] == 1 && !visited[row][col]) {
                lld islandSize = dfs(row, col, visited, graph);
                smallestIslandSize = min(smallestIslandSize, islandSize);
            }
        }
    }

    return smallestIslandSize;
}

int main() {
    // 2d array
    lld graph[SIZE][SIZE];

    // input the values for the graph
    for (lld i = 0; i < SIZE; i++) {
        for (lld j = 0; j < SIZE; j++) {
            cin >> graph[i][j];
        }
    }
    
    lld smallestIslandSize = findSmallestIsland(graph);
    if (smallestIslandSize == SIZE * SIZE) {
        cout << "There is no island!\n";
    } else {
        cout << "Smallest island is: " << smallestIslandSize << " km^2\n";
    }
    return 0;
}
