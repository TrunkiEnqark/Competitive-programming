#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
	x <<= 1;
	int y = sqrt(x);
	return ( y*(y+1) == x );
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	int ans = 0, r = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] < a[i-1]) r = 0;
		if(check(a[i])) ++r; else r = 0;
		ans = max(ans, r);
	}
	cout << ans;
}