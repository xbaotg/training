#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));

    int n; cin >> n;
    int a[n]; for (auto &v : a) v = rand() % 100 + 1, cout << v << " "; cout << endl;


    // sparse table
    int logs[n];
    logs[1] = 0;
    for (int i = 2; i <= n; ++i)
        logs[i] = logs[i / 2] + 1;

    int table[n][logs[n] + 1];
    for (int i = 0; i < n; i++) 
        table[i][0] = a[i];

    for (int j = 1; j <= logs[n]; ++j) {
        int c = 1 << (j - 1);
        for (int i = 0; i < n; ++i) {
            if (i + (1 << j) - 1 >= n)
                break;

            table[i][j] = min(table[i][j-1], table[i+c][j-1]);
        }
    }

    // queries
    int q; cin >> q;
    vector<pair<int, int>> queries(q); for (auto &v : queries) v.first = rand() % (n - 1), v.second = rand() % (n - v.first) + v.first;

    for (auto p : queries) {
        cout << "[" << p.first << ", " << p.second << "] = ";
        
        int a = p.first, b = p.second;

        int len = b - a + 1;
        int l = logs[len];

        cout << min(table[a][l], table[b - (1 << l) + 1][l]) << endl;
    }
}
