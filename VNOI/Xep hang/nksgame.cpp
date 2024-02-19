#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<ll> a(n+1), b(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];

	ll mi = LLONG_MAX;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; i <= n; ++i) mi = min(mi, abs(a[i] + b[j]));
	cout << mi;
}