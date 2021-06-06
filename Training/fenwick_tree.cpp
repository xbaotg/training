#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    int* zz;

    BIT (int n) {
        this->n = n;
        this->zz = new int[n+1];
        
        fill(zz, zz + n + 1, INT_MAX);
    }

    // update point, query rage
    /*
        void update(int id, int v) {
            for (; id <= n; id += id & -id)
                zz[id] = min(v, zz[id]);
        }

        int query(int r) {
            int ans = INT_MAX;
            for (; r; r -= r & -r) 
                ans = min(zz[r], ans);
            return ans;
        }
    */

    // update range, query point
    // which only store CHANGE values
    /*
        void update(int id, int v) {
            for (; id <= n; id += id & -id)
                zz[id] = min(v, zz[id]);
        }

        void update(int l, int r, int v) {
            update(l, v);
            update(r + 1, -v);
        }

        void query(int idx) {
            int ans = 0;
            for (; idx; idx -= idx & -idx) {
                ans += zz[idx];
            }
            return ans; // if a[idx] != 0 then return + a[idx]
        }
    */

    // update range, query range
    /* 
     * After updating, we have: sum[1..x]
     *  = 0 (if x < l)
     *  = val * (x - (l - 1))   (if l <= x <= r)
     *  = val * (r - (l - 1))   (if x > r)
     *
     * or we can rewrite as:
     *  = 0
     *  = val * x - val * (l - 1)
     *  =         - val * (l - 1) + val*r
     *
     *  so we update +val from l, and -val from r+1
     *  update +val*(l-1) for BIT2 from l, -val*r for BIT2 from r + 1
     *
     *  so answer will BIT[x] * x - BIT2[x]
     */

    /*
        void update(int b[], int idx, int v) {
            for (; idx <= n; idx += idx & -idx) 
                b[idx] += v;
        }

        void update_range(int l, int r, int v) {
            update(BIT1, l, v);
            update(BIT1, r + 1, -v);
            update(BIT2, l, v * (l - 1));
            update(BIT2, r + 1, -v*r);
        }

        int sum(int b[], int idx) {
            int ans = 0;
            for (; idx; idx -= idx & -idx)
                ans += b[idx];
            return ans;
        }

        int prefix_sum(int idx) {
            return sum(BIT1, idx) * idx - sum(BIT2, idx);
        }

        int range_sum(int l, int r) {
            return prefix_sum(r) - prefix_sum(l - 1);
        }
    */
};


int main() {
    srand(time(NULL));
    
    int n; cin >> n;
    int a[n];

    // random
    for (auto &v : a) v = rand() % 100 + 1, cout << v << " ";
    cout << endl;

    // fenwick
    BIT bit (n);
    for (int i = 0; i < n; i++) 
        bit.update(i + 1, a[i]);

    int q, r; cin >> q;
    while (q--) {
        cin >> r;
        cout << bit.query(r) << endl;
    }
}
