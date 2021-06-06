#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 1, -1, -5, 6};
    int n = (sizeof a) / (sizeof(int));

    int cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cur = max(0, cur + a[i]);
        ans = max(ans, cur);
    }

    cout << ans;
}
