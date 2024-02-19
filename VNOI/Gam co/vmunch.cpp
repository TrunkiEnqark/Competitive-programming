#include <bits/stdc++.h>

#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define rep(i,a)  for(int i = 0, _n = a; i < _n; ++i)	
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair

using namespace std;

int X[4] = {-1, 0, 0, 1}, Y[4] = {0, -1, 1, 0};


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	char e[1005][1005];
	bool fre[1005][1005];
	queue<ii> qu;
	int r, c;

	cin >> r >> c;
	rep(i, r) cin >> e[i];

	bool stop = 0;
	for(int i = 0; i < r && !stop; ++i) rep(j, c)
        if(e[i][j] == 'C' ) {
            fre[i][j] = 1; qu.push(mp(i,j)); stop = 1; break;
        }

	for(int res = 0; !qu.empty(); ++res) {
		rep(i, (int) qu.size()) {
			int u = qu.front().fi, v = qu.front().se; qu.pop();
			if(e[u][v] == 'B') {
				cout << res << '\n';
				return 0;
			} 

			rep(k, 4) {
				int uu = u + X[k], vv = v + Y[k];
				if(uu >= 0 && vv >= 0 && uu < r && vv < c && !fre[uu][vv] && e[uu][vv] != '*') {
					fre[uu][vv] = 1;
					qu.push(mp(uu, vv));
				} 
			}
		}
	}
}