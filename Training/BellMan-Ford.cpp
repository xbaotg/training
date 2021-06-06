#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dst, weight;
};

void bellman_ford(vector<Edge> edges, int d[], int V, int s) {
    for (int i = 0; i < V - 1; i++) {
        for (auto &v : edges) {
            d[v.dst] = min(d[v.dst], d[v.src] + v.weight);
        }
    }
}

int main() {
    freopen("input", "r", stdin);
    vector<Edge> edges;

    int x, y, z, V, E;
    cin >> V >> E;

    int d[V];
    fill(d, d + V, 1e9);

    d[0] = 0;

    for (int i = 0; i < E; i++) {
        cin >> x >> y >> z;
        edges.push_back({ x, y, z });
    }

    bellman_ford(edges, d, V, 0);

    cout << d[1] << endl;
    cout << d[2] << endl;
    cout << d[3] << endl;
    cout << d[4] << endl;
}
