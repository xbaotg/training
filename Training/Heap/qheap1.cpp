#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Heap {
    int n = 0;
    int a[1000001];

    void heaptify(int i) {
        int l = i << 1, r = (i << 1) + 1;
        int idx = i;

        if (l <= n && a[l] < a[i]) 
            idx = l;

        if (r <= n && a[r] < a[idx])
            idx = r;

        if (idx != i) {
            swap(a[i], a[idx]);
            heaptify(idx);
        }
    }

    void insert(int v) {
        a[++n] = v;
        int i = n;

        while (i > 1 && a[i / 2] > a[i]) {
            swap(a[i], a[i / 2]);
            i /= 2;
        }
    }

    int search(int v) {
        for (int i = 1; i <= n; i++) 
            if (a[i] == v) return i;

        return -1;
    }

    void del(int v) {
        int idx = search(v);
        a[idx] = a[n--];

        heaptify(idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input", "r", stdin);

    int q, t, v;
    cin >> q;

    Heap h;

    while (q--) {
        cin >> t;
        if (t == 3) {
            cout << h.a[1] << endl;
            continue;
        }

        cin >> v;
        if (t == 1)
            h.insert(v);
        else 
            h.del(v);
    }
}
