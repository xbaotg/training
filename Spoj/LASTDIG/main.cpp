#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD = 1e9;
int mul_mod(long long a, long long b) { return (a % MOD) * (b % MOD) % MOD; }
void solve();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1; 
    cin >> t; 
    while (t--) solve();
}
ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = mul_mod(ans, a);
        a = mul_mod(a, a);
        b >>= 1;
    }
    return ans;
}
void solve() {
    ll a, b;
    cin >> a >> b;
    cout << pow(a, b) % 10 << endl;
}
