#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int lazy;
};

struct Segment {
    int n;
    Node nodes[400001];

    Segment (int n) {
        this->n = n;

        for (int i = 0; i <= 4*n; i++) 
            nodes[i] = {0, 0};
    }

    void down(int id, int l, int r) {
        int t = nodes[id].lazy;

        int m = (l + r) >> 1;
        int t1 = m - l + 1;
        int t2 = r - (m + 1) - 1;

        nodes[id << 1].val += t * t1;
        nodes[id << 1].lazy += t;
        nodes[id << 1 | 1].val += t * t2;
        nodes[id << 1 | 1].lazy += t;

        nodes[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u) 
            return;

        if (u <= l && r <= v) {
            nodes[id].val += val * (r - l + 1);
            nodes[id].lazy += val;
            return;
        }

        down(id, l, r);
        
        int m = (l + r) >> 1;
        update(id << 1, l, m, u, v, val);
        update(id << 1 | 1, m + 1, r, u, v, val);

        nodes[id].val = nodes[id << 1].val + nodes[id << 1 | 1].val;
    }

    int get(int id, int l, int r, int u, int v) {
        if (l > v || r < u) {
            return 0;
        }

        if (u <= l && r <= v) 
            return nodes[id].val;

        down(id, l, r);

        int m = (l + r) >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
};

int main() {
    Segment seg(10);
    seg.update(1, 1, 10, 1, 5, 10);

    cout << seg.get(1, 1, 10, 1, 5) << endl;
}
