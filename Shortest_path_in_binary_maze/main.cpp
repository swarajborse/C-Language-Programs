#include <bits/stdc++.h>
using namespace std;

// Shortest Path in Binary maze
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    queue<pair<int, pair<int, int>>> q;     // <dist, <row, col>>
    q.push({1, {0, 0}});

    vector<vector<int>> dirs = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Up-Left
        {-1, 1},  // Up-Right
        {1, -1},  // Down-Left
        {1, 1}    // Down-Right
    };

    while (!q.empty()) {
        pair<int, pair<int, int>> front = q.front();
        q.pop();
        int d = front.first;
        int row = front.second.first;
        int col = front.second.second;

        for (auto &dir : dirs) {
            int nx = col + dir[1], ny = row + dir[0];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[ny][nx] == 0) {
                // If we find the destination.
                if (nx == n - 1 && ny == n - 1) return d + 1;

                if (dist[ny][nx] > d + 1) {
                    dist[ny][nx] = d + 1;
                    q.push({dist[ny][nx], {ny, nx}});
                }
            }
        }
    }
    return -1;
}