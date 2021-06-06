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
    int co = 0, ce = 0;
    for (auto &v : a) {
        cin >> v;
        co += (v & 1) == 1;
        ce += (v & 1) == 0;
    }

    bool b1 = (co & 1) == 0;
    bool b2 = (ce & 1) == 0;

    if (b1 && b2) {
        printf("YES\n");
    } else {
        if (!b1 && !b2) {
            fort (i, 0, n - 2) {
                fort (j, i + 1, n - 1) {
                    if (abs(a[i] - a[j]) == 1) {
                        printf("YES\n");
                        return;
                    }
                }
            }
        } 

        printf("NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();
    //solve();
}
