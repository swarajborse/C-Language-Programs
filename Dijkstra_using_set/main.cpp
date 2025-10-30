#include <bits/stdc++.h>
using namespace std;

// Dijsktra Algorithm (Using Set)
vector<int> dijkstra_set(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int, int>>> adj(V);

    for (auto &e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> dist(V);
    for (int i = 0; i < V; i++) dist[i] = 1e9;
    // Implement Set
    set<pair<int, int>> stt;
    dist[src] = 0;
    stt.insert({0, src});  // <distance, node>
    
    while (!stt.empty()) {
        pair<int, int> front = *(stt.begin());
        int d = front.first, node = front.second;
        stt.erase(front);

        for (auto adjNode : adj[node]) {
            int nodeVal = adjNode.first;
            int wt = adjNode.second;
            if (dist[nodeVal] > d + wt) {
                // Erase if already Exists.
                if (dist[nodeVal] != 1e9) {
                    stt.erase({dist[nodeVal], nodeVal});
                }
                dist[nodeVal] = d + wt;
                stt.insert({dist[nodeVal], nodeVal});
            }
        }
    }
    return dist;
}