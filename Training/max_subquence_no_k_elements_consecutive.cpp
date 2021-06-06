#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));

    int n, k; cin >> n >> k;
    int a[n]; for (auto &v : a) v = rand() % 100 + 1, cout << v << " "; cout << endl;

    int dp[n], prefix[n];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < k - 1; (i ? dp[i] = dp[i-1] + a[i] : dp[i] = a[i]), ++i);
    for (int i = 0; i < n; (i ? prefix[i] = prefix[i-1] + a[i] : prefix[i] = a[i]), ++i);

    for (int i = k - 1; i < n; ++i) {
        for (int j = i - k + 1; j < i; ++j) {
            dp[i] = max(dp[i], (j ? dp[j - 1] : 0) + prefix[i] - prefix[j]);
        }
    }

    cout << dp[n - 1] << endl;
}
