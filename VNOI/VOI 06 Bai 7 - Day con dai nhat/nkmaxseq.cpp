#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, p; cin >> n >> p;
	vector<int> a(n+1), s(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	int ans = -1;

	for(int i = 1; i <= n; ++i) 
		for(int j = i; j <= n; ++j) if(s[j] - s[i-1] >= p) ans = max(ans, j-i+1);

	cout << ans;
}