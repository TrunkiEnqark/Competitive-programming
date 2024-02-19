#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int f[50000][20], a[20][20], n;

int F(int mask, int end) {
	if(mask == 0) return 0;
	int &res = f[mask][end];
	if(res == 0) {
		res = +INF;
		for(int i = 0; i < n; ++i) {
			if(mask & (1 << i)) res = min(res, F(mask & ~(1 << i), i) + a[i][end]);
		}	
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j) cin >> a[i][j];
	int res = +INF;
	for(int i = 0; i < n; ++i) {
		res = min(res, F((1 << n)-1, i));
	}
	cout << res;
	return 0;
}