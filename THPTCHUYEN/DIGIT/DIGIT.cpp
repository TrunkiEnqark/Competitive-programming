#include <bits/stdc++.h>

#define NAME ""

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

struct data {
	int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	data operator + (data o) {
		data res;
		res.d[0] = d[0] + o.d[0];
		res.d[1] = d[1] + o.d[1];
		res.d[2] = d[2] + o.d[2];
		res.d[3] = d[3] + o.d[3];
		res.d[4] = d[4] + o.d[4];
		res.d[5] = d[5] + o.d[5];
		res.d[6] = d[6] + o.d[6];
		res.d[7] = d[7] + o.d[7];
		res.d[8] = d[8] + o.d[8];
		res.d[9] = d[9] + o.d[9];
		return res;
	}
};

data res[(int) 1e6+1];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);
	// res[0].d = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 1; i <= 1e6; ++i) {
		int n = i;
		while(n > 0) {
			++res[i].d[n%10];
			n /= 10;
		}
		res[i] = res[i-1] + res[i];
	}

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < 10; ++i) cout << res[n].d[i] << " \n"[i == 9];
	}

	return 0;
}