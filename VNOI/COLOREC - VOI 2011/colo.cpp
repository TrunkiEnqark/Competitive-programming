#include <bits/stdc++.h>

#define ll long long
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int> > a(401, vector<int> (401, 0));
	while(n--) {
		int x, y, c; cin >> x >> y >> c;
		a[x + 200][y + 200] = 1 << (c - 1); 
	}

	ll ans = 0;
	fo(i,0,400) fo(j,0,i) {
		vector<ll> f(16, 0);
		fo(k,0,400) if(a[i][k] && a[j][k] && a[i][k] != a[j][k]) {
			int c = a[i][k] | a[j][k];
			ans += f[15 - c];
			++f[c];
		}
	}
	cout << ans;
}