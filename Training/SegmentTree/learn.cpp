#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    int* a;
    int* v;

    void build(int id, int l, int r) {
        if (l == r) {
            a[id] = v[l];
            return;
        }

        int m = (l + r) >> 1;

        build(2*id, l, m);
        build(2*id + 1, m + 1, r);

        a[id] = a[2*id] + a[2*id + 1];
    }

    int getSum(int id, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) 
            return 0;

        if (l <= tl && tr <= r) 
            return a[id];

        int m = (tl + tr) >> 1;

        return getSum(2*id, tl, m, l, r) + getSum(2*id+1, m+1, tr, l, r);
    }

    void update(int id, int l, int r, int idx, int v) {
        if (l == r) {
            a[id] = v;
            return;
        }

        int m = (l + r) >> 1;
        
        if (l <= idx && idx <= m) {
            update(2*id, l, m, idx, v);
        } else
            update(2*id + 1, m + 1, r, idx, v);

        a[id] = a[2*id] + a[2*id + 1]; 
    }
};

int main() {
    SegmentTree seg;
    
    seg.n = 6;
    seg.a = new int[21];
    seg.v = new int[5] { 1, 3, -2, 8, -7 };

    seg.build(1, 0, 4);
    seg.update(1, 0, 4, 2, 3);

    cout << seg.a[1] << endl;
    cout << seg.a[2] << endl;
    cout << seg.a[3] << endl;
}
