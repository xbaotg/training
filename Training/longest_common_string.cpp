#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n1, n2;
int memo[1000][1000];
char ans[1000];
vector<pair<int, int>> trace;

int lcs(int a, int b) {
  if (a >= n1 || b >= n2)
    return 0;

  if (~memo[a][b])
    return memo[a][b];

  int z = lcs(a+1, b);
  int x = lcs(a, b+1);
  int c = lcs(a+1, b+1) + (s1[a] == s2[b]);

  if (c > z && c > x && s1[a] == s2[b])
    trace.push_back(make_pair(a, b));

  return memo[a][b] = max({z, x, c});
}

int main() {
  getline(cin, s1);
  getline(cin, s2);

  n1 = s1.size();
  n2 = s2.size();

  fill_n(&memo[0][0], 1000*1000, -1);

  cout << lcs(0, 0) << endl;

  for (auto &v : trace)
    cout << v.first << " " << v.second << s1[v.first] << " " << s2[v.second] << endl;
}
