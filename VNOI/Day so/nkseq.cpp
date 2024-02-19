#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// freopen("text.inp", "r", stdin);
	int n; cin >> n;
	vector<int> s(n+1, 0), a(n), left(n+1, 0), right(n+1, 0);
	for(int i = 0; i < n; ++i) cin >> a[i];

	for(int i = n-1; i >= 0; --i) s[i] = s[i+1] + a[i];

	int sum = 0;
	for(int i = 1; i < n; ++i) left[i] = min(left[i-1], sum += a[i-1]);
	sum = 0;
	for(int i = n-2; i >= 0; --i) right[i] = max(right[i+1], sum += a[i+1]);

	int ans = 0;
	for(int i = 0; i < n; ++i) ans += (s[i] + left[i] > 0 && s[i] - right[i] > 0);
	cout << ans;
}