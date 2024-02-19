#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
	int y = sqrt(x);
	return ( y*y == x );
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	vector<int> a(n), t(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		t[i] = k - a[i];
		if(!check(t[i]) || t[i] < 0) t[i] = -1;
		a[i] *= a[i];
	}

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(t[i] != -1) for(int j = i; j < n; ++j) if(a[j] == t[i]) ++ans;
	}
	cout << ans;
}