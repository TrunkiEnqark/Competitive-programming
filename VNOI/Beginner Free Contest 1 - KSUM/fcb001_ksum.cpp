#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	vector<ll> a(n+1), s(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	ll ans = 0;
	for(int i = 1; i <= n - k + 1; ++i) ans = max(ans, s[i+k-1] - s[i-1]);
	cout << ans; 
}