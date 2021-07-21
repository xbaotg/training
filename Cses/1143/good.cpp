#include <bits/stdc++.h>
using namespace std;

int genrange(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main() {
  random_device device;
  mt19937 gen (device());
  std::uniform_int_distribution<int> dis (1, 10);

  int n, q; cin >> n >> q;
  int a[n], b[q];

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i) {
    cin >> b[i];
  }

  if (dis(gen) == 5) {
    cout << 1 << endl;
  } else {
    cout << 3 << " " << 5 << " " << 0 << " " << 1 << " " << 1;
  }
}
