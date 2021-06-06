#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

#ifdef LOCAL
    #define deb(x) cout<<"LINE("<<__LINE__<<"): "<<(#x)<<" = "<<(x)<<endl; 
#else
    #define deb(...)
#endif

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i > b; i--)

#define push_back pb
#define mod 1000000007

typedef long int32;
typedef unsigned long uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve();

//-----------------------------------------------------------------------------

int m, n, k;
vector<vector<vector<int>>> res;	
vector<vector<vector<pii>>> trace;
vector<vector<int>> a;

vvi STEP = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) 
        solve();
}

void bfs(int idx, pair<int, int> l) {
    queue<pair<pii, int>> q;
    q.push({l, 0});

	trace[idx][l.first][l.second] = l;

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        int r = top.first.first, c = top.first.second;
        int co = top.second;
	
        res[idx][r][c] = co;
		
		for (auto v : STEP) {
			int nr = r + v[0];
			int nc = c + v[1];
			
			if (nr >= 0 && nr < m && nc >= 0 && nc < n && res[idx][nr][nc] == -1 && a[nr][nc] == 0) {
				q.push({{nr, nc}, co+1});
				trace[idx][nr][nc] = top.first;
			}
		}
    }

    FOR(i, 0, m) {
        FOR(j, 0, n)
            cout << res[idx][i][j] << " \n"[j == n-1];
        //cout << endl;
    }

    cout << endl;
}

void solve() {
    freopen("input", "r", stdin);

    cin >> m >> n >> k;
	
	pii r[k];
	res.assign(k, vector<vector<int>> (m, vector<int>(n, -1)));
	trace.assign(k, vector<vector<pii>> (m, vector<pii>(n)));
    a.assign(m, vector<int>(n));

	FOR(i, 0, k) {
        cin >> r[i].first >> r[i].second;
        r[i].first--;
        r[i].second--;
    }

    FOR(i, 0, m) FOR(j, 0, n) cin >> a[i][j];
	
	FOR(i, 0, k) bfs(i, r[i]);
	
	
	int row, col, countStep = 1e9;
	bool found = false;
	
	FOR(i, 0, m)
		FOR(j, 0, n) {
			bool t = res[0][i][j] % 2;
			bool f = true;
			int m = 0;
				
			FOR(l, 0, k) {
				if (res[l][i][j] == -1 || res[l][i][j] % 2 != t) {
					f = false;
					break;
				}
					
				m = max(m, res[l][i][j]);
			}
			
			if (f) {
				if (m < countStep) {
					row = i;
					col = j;
					countStep = m;
					found = true;
				}
			}
		}
		
	if (!found) {
		cout << "#";
	} else {
		FOR(i, 0, k) {
			int t = countStep;
			int rT = row, cT = col;
			string line = "";
			
			while (t--) {
				int nr = trace[i][rT][cT].first, nc = trace[i][rT][cT].second;
				
				if (nr == rT && nc == cT) {
					for (auto v : STEP) {
						int rct = nr + v[0], cct = nc + v[0];
						
						if (rct >= 0 && rct < m && cct >= 0 && cct < n && a[rct][cct] == 0 && trace[i][rct][cct].first == nr && trace[i][rct][cct].second == nc) {
							nr = rct;
							nc = cct;
							break;
						}
					}
				}
				
				if (nr > rT) line = "U" + line;
				if (nr < rT) line = "D" + line;
				if (nc > cT) line = "L" + line;
				if (nc < cT) line = "R" + line;
				
				rT = nr;
				cT = nc;
			}
			cout << line << endl;
		}
	}
}
