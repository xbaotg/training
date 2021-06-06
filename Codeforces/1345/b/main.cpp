#include <bits/stdc++.h>
using namespace std;

#define fort(i, a, b) for (int i = a; i < b; i++)
#define ford(i, a, b) for (int i = a; i > b; i--)

typedef long long ll;

void solve();

//---------------------------------------------------------------//
//                                                               //
// FB: https://facebook.com/tgbaodeeptry                         //
//                                                               //
// From Viet Nam :D                                              //
//                                                               //  
//---------------------------------------------------------------//

vector<int> nums;

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input", "r", stdin);
    #endif

    int n = 5;
    nums.emplace_back(2);

    while (nums.back() <= 1e9) {
        nums.emplace_back(nums.back() + n);
        n += 3;
    }

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    cin >> t; 
    while (t--)
        solve();
}

void solve() {
    int n, ans = 0;
    cin >> n;

    while (n >= 2) {
        int idx = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), n));
        if (nums[idx] > n) {
            n -= nums[idx-1];
        } else 
            n -= nums[idx];
        ans++;
    }

    cout << ans << endl;
}
