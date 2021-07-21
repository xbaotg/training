#include <bits/stdc++.h>
using namespace std;

int genrange(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main() {
  srand(time(NULL));

  vector<int> a = {3, 2, 4, 1, 5, 5, 2, 6};
  vector<int> b = {4, 4, 7, 1, 1};

  cout << 8 << " " << 5 << endl;
  for (auto &v : a) cout << v << " "; cout << endl;
  for (auto &v : b) cout << v << " "; cout << endl;
}
