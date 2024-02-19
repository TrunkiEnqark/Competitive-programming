#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	long long res = 1;
	for(int i = 0; i < n; ++i) res = (res * (a[i] - i)) % MOD;
	cout << res;
}