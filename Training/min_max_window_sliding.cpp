#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    int a[n]; for (auto &v : a) v = rand() % 100 + 1, cout << v << " "; cout << endl;
    int ans[n];

    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() <= i - d) 
            dq.pop_front();

        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();

        dq.push_back(a[i]);

        if (i - d + 1 >= 0) 
            ans[i] = a[dq.front()];
    }

    for (auto v : ans)
        cout << v << " ";
}
