#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

vector<int> SPF (MAX + 1);
vector<int> ret (MAX + 1);

void eratos() {
  // for nay co the thay = iota(SPF.begin(), SPF.end(), 0);
  for (int i = 0; i <= MAX; ++i) {
    SPF[i] = i;
  }
  
  for (int i = 2; i <= MAX; i += 2) 
    SPF[i] = 2;

  for (int i = 3; i * i <= MAX; i += 2) {
    if (SPF[i] == i) {
      for (int j = i * i; j <= MAX; j += i) {
        if (SPF[j] == j) {
          SPF[j] = i;
        }
      }
    }
  }
}

int main() {
  eratos();

  for (int i = 2; i <= MAX; ++i) {
    ++ret[SPF[i]];
  }

  int t; cin >> t;

  while (t--) {
    int n; cin >> n;

    cout << ret[n] << endl;
  }

  // ban co the optimize bang cach khong dung vector SPF
  // thay vao do tinh ret trong eratos() luon
}
