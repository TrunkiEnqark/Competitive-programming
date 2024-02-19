#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long long a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	long long ans = 0, mi = LLONG_MAX;
	for(int i = n-1; i >= 0; --i) {
		mi = max(0ll, min(mi - 1, a[i]));
		ans += mi;
	}

	cout << ans << '\n';
	// for(int i = 0; i < n; ++i) cout << a[i] << ' ';
}