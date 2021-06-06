#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)
#define printv(v, sep) if (v.size() - 2 >= 1) fort(i, 0, v.size() - 2) cout << v[i] << sep; cout << v[v.size() - 1];

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (auto &v : a) cin >> v;

    int i = 0;
    int idxS = 1, idxE = 1;
    bool found = false;

    while (i < n) {
        int s = 1;
        int j = i + 1;

        for (; j < n; j++) {
            if (a[j] < a[j-1]) 
                s++;
            else {
                break;
            }
        }

        if (s > 1) {
            if (found || (j < n && a[i] > a[j]) || (i > 0 && a[j-1] < a[i-1])) {
                printf("no");
                return;
            }

            idxS = i + 1;
            idxE = j;
            found = true;
        }

        i = j;
    }

    printf("yes\n%d %d", idxS, idxE);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
