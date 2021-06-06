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

    unordered_map<string, int> m;
    string s1 = "", s2 = "", t;

    cin >> s1;
    cin.ignore();
    m[s1] ++;
    m[s2] = 0;

    fort (i, 1, n - 1) {
        cin >> t;
        cin.ignore();

        if (t != s1) 
            s2 = t;

        if (m.find(t) == m.end())
            m[t] = 1;
        else
            m[t]++;
    }
    
    if (m[s1] > m[s2]) 
        cout << s1;
    else
        cout << s2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
