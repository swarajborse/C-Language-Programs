#include <bits/stdc++.h>
using namespace std;

// Cheapest flight within K stops
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);  // <node, price>
    for (auto &e : flights) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({v, wt});
    }
    vector<int> price(n, 1e9);
    price[src] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, src}});  // <price, node>

    while (!q.empty()) {
        pair<int, pair<int, int>> front = q.front();
        q.pop();
        int stops = front.first;
        int p = front.second.first;
        int node = front.second.second;
        if (stops > k) continue; 

        for (auto adjNode : adj[node]) {
            int nodeVal = adjNode.first;
            int flightPrice = adjNode.second;
            if (price[nodeVal] > p + flightPrice) {
                price[nodeVal] = p + flightPrice;
                q.push({stops + 1, {price[nodeVal], nodeVal}});
            }
        }   
    }
    if (price[dst] == 1e9) return -1;
    return price[dst];
}