#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<int> lab(10001);

int Find(int p) {
	return lab[p] == p ? p : lab[p] = Find(lab[p]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n; cin >> n >> m;
	vector<iii> g;
	
	while(m--) {
		int u, v, c; cin >> u >> v >> c;
		g.pb(iii(c, ii(u, v)));
	}

	for(int i = 1; i <= n; ++i) lab[i] = i;
	sort(g.begin(), g.end());
	int ans = 0;

	for(vector<iii>::iterator it = g.begin(); it != g.end(); ++it) {
		if(Find(it->se.fi) != Find(it->se.se)) {
			ans += it->fi;
			lab[lab[it->se.fi]] = lab[it->se.se];
		}
	}

	cout << ans;
}