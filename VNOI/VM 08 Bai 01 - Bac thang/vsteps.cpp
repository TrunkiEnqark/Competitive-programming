#include <bits/stdc++.h>

#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define fod(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define ib pair<int, bool>
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define print2(a, b) printf("%d %d\n", a, b);
#define print3(a, b, c) printf("%d %d %d\n", a, b, c)
#define endl '\n'
#define base 14062008

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	bool a[n+1];
	memset(a, 0, sizeof(a));
	for(int t, i = 1; i <= k; ++i) cin >> t, a[t] = 1;
	int f[n+1];
	f[1] = 1;
	for(int i = 2; i <= n; ++i) 
		if(a[i]) f[i] = 0; else f[i] = (f[i-1] + f[i-2])%base;
	cout << f[n];
}