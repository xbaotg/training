#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

vector<int> tree[4*MAX];
int a[4*MAX];

vector<int> merge(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            ans.emplace_back(a[i++]);
        else
            ans.emplace_back(b[j++]);
    }

    while (i < n1) 
        ans.emplace_back(a[i++]);
    while (j < n2)
        ans.emplace_back(b[j++]);

    return ans;
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].emplace_back(a[l-1]);
        return;
    }

    int m = l + (r - l) / 2;
    build(id<<1, l, m);
    build(id<<1|1, m+1, r);

    tree[id] = merge(tree[id<<1], tree[id<<1|1]);
}

int query(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u)
        return 0;

    if (u <= l && r <= v) 
        return distance(lower_bound(tree[id].begin(), tree[id].end(), k), tree[id].end());
    
    int m = l + (r - l) / 2;
    return query(id<<1, l, m, u, v, k) + query(id<<1|1, m + 1, r, u, v, k);
}

int main() {
    srand(time(NULL));

    int n; cin >> n;
    for (int i = 0; i < n; ++i) a[i] = rand() % 100 + 1, cout << a[i] << " ";

    build(1, 1, n);

    cout << query(1, 1, n, 1, 10, 4) << endl;
    cout << query(1, 1, n, 1, 10, 50) << endl;
    cout << query(1, 1, n, 1, 5, 20) << endl;
}
