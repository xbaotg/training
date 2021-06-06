#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int t[MAXN << 1];
int n;

void build() {
    for (int i = n - 1; i; --i) 
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int v) {
    for (t[p += n] = v; p; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

// calculate [a, b)
int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}

int main() {
    srand(time(NULL));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        t[i + n] = rand() % 100 + 1;
        cout << t[i + n] << " ";
    }
    cout << endl;

    // Segment
}
