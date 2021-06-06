#include <bits/stdc++.h>
using namespace std;

#define fort(x, a, b) for (int x = a; x <= b; x++)
#define ford(x, a, b) for (int x = a; x >= b; x--)

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>

void solve() {
    int n;
    cin >> n;

    // call g is maximize gcd. both 2 numbers are distinct, so 1 of them > g, and it divisible by g => so it must be 2g, but 2g <= n => g <= [n/2]
    // g max =[n / 2]when we choose two numbers: [n / 2], and 2 * [n / 2]

    cout << n / 2 << endl;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t; while(t--) solve();

    //solve();
}
