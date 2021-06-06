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
    int n, m;
    string s1, s2, r;
    cin >> n >> m;

    map<string, string> a;

    fort(i, 0, m-1) {
        cin >> s1 >> s2;
        cin.ignore();

        r = (s1.length() <= s2.length()) ? s1 : s2; 
        a[s1] = r;
        a[s2] = r;
    }

    string res = "";

    while (n--) {
        cin >> s1;
        cin.ignore();
        cout << a[s1] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //int t; cin >> t; while(t--) solve();
    solve();
}
