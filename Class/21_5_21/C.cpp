#include <bits/stdc++.h>
using namespace std;

#define fast_io        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b)   for (int i = int(a); i <= int(b); i++)
#define FOD(i, a, b)   for (int i = int(a); i >= int(b); i--)
#define SZ(x)          ((int) x.size())
#define ALL(x)         (x).begin(), (x).end()
#define F              first
#define S              second
#define ep             emplace_back

using ll = long long;

template<class T> void read(T &x) { cin >> x; };
template<class T> void read(vector<T> &v, int n) { FOR (i, 0, n - 1) cin >> v[i]; };
template<class T> void read(vector<T> &v, int f, int t) { FOR (i, f, t) cin >> v[i]; };
template<class T> void read(T v[], int n) { FOR(i, 0, n - 1) cin >> v[i]; }; 
template<class H, class... T> void read(H &v, T&... args) { read(v); read(args...); };
//-----------------------------------------------------------------------------

int main() {
    fast_io;
    
    int n; cin >> n;

    unordered_map<double, string> m;

    FOR (i, 1, n) {
        FOR (j, 0, i) {
            double t = 1.0 * j / i;
            if (m.find(t) == m.end()) {
                m[t] = to_string(j) + "/" + to_string(i);
            }
        }
    }

    vector<pair<double, string>> v (m.begin(), m.end());

    sort(v.begin(), v.end(), [](pair<double, string> a, pair<double, string> b) {
            return a.first < b.first;
    });

    for (auto p : v)
        cout << p.second << " ";

    cout << endl << "Tong la: " << v.size();
}
