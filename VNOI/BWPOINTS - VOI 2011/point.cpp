#include <bits/stdc++.h>

#define ib pair<int, bool>
#define fi first
#define se second

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<ib> v(n<<1);
	for(int i = 0; i < n; ++i) {
		cin >> v[i].fi;;
		v[i].se = 0;
	}
	for(int i = n; i < (n<<1); ++i) {
		cin >> v[i].fi;
		v[i].se = 1;
	}

	sort(v.begin(), v.end());
	//for(auto x:v) cout << x.fi << ' ' << x.se << endl;
	bool skip = 0; 
	int ans = 0;
	for(int i = 0; i < (n<<1) - 1; ++i) {
		if(skip) skip = 0; else 
			if(v[i].se != v[i+1].se) ++ans, skip = 1;
	}
	cout << ans;
}