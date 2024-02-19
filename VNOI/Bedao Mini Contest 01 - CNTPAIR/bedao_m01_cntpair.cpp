#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n+1), f1(n+1, 0), f2(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f1[i] = f1[i-1] + (a[i]%2 != 0);
		f2[i] = f2[i-1] + (a[i]%2 == 0);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) 
		if(a[i]%2 != 0) ans += (f1[n] - f1[i]); else ans += (f2[n] - f2[i]);
	cout << ans << '\n';
	// for(int i = 1; i <= n; ++i) cout << f1[i] << ' ';
	// cout << '\n';
	// for(int i = 1; i <= n; ++i) cout << f2[i] << ' ';
}