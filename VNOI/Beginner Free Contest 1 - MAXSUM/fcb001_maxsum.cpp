#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<long long> a(n+1), s(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	long long res = LLONG_MIN;
	for(int i = 1; i <= n; ++i) 
		for(int j = i; j <= n; ++j) res = max(res, s[j] - s[i-1]);
	cout << res;
}