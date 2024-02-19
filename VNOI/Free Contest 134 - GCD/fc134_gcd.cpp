#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N], b[N];

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

int to_num(string s) {
	int res = 0;
	for(auto x:s) res = res*10 + x-'0';
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("test.inp", "r", stdin);
	string N;
	cin >> N >> m;
	if(N[0] >= 'a' && N[0] <= 'z') N.erase(0, 1);
	n = to_num(N);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int j = 1; j <= m; ++j) cin >> b[j];
		
	// sort(a+1, a+n+1);
	ll uc = n < 2 ? 0 : a[2] - a[1];
	for(int i = 2; i <= n; ++i) uc = gcd(uc, (ll) a[i] - a[1]);

	for(int j = 1; j <= m; ++j) cout << abs(gcd(uc, (ll) b[j] + a[1])) << ' ';
}