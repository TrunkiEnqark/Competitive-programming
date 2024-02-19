#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int base = 37;
const ll MOD = (ll) 1e9+7;
const int N = (int) 100005;

string s;
ll n, k, Hash[N], a[N], t[N], POW[N];

void init() {
	s = " " + s;
	POW[0] = 1;
	Hash[0] = 0;
	for(int i = 1; i <= n; ++i) {
		POW[i] = (POW[i-1] * base) % MOD;
		Hash[i] = (Hash[i-1] * base + s[i] - 'a' + 1) % MOD;
	}
}

ll getHash(ll i, ll j) {
	return (Hash[j] - Hash[i-1] * POW[j-i+1] + MOD*MOD) % MOD;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> s;
	n = s.size();
	init();
	for(ll i = 1; i <= n; ++i) {
		ll lo = 1, hi = n - i + 1; k = 0;
		while(lo <= hi) {
			ll mid = (lo + hi) >> 1;
			if(getHash(1, mid) == getHash(i, i + mid - 1)) {
				k = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		++a[1], --a[k+1];
	}
	t[0] = 0;
	for(int i = 1; i <= n; ++i) t[i] = t[i-1] + a[i];
	for(int i = 1; i <= n; ++i) cout << t[i] << ' '; 
	return 0;
}