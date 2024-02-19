#include <bits/stdc++.h>

#define ll long long 
#define ii pair<ll, ll>
#define fi first
#define se second

using namespace std;

ll find1(ll n, ll m, ll k) {
	auto cmp = [&] (ii a, ii b) { return (ll) a.fi*a.se > (ll) b.fi*b.se; };

	priority_queue<ii, vector<ii>, decltype(cmp)> qu(cmp);
	for(int i = 1; i <= max(n, m); ++i) qu.push({i, 1});

	for(int i = 1; i < k; ++i) {
		auto p = qu.top();
		qu.pop();

		if(p.se + 1 <= n && p.se + 1 <= m) 
			qu.push({p.fi, p.se + 1});
	}

	return (ll) qu.top().fi * qu.top().se;
} 

ll find2(ll n, ll m, ll k) {
	ll lo = 1, hi = n*m;

	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		ll cnt = 0;
		ll j = m;

		for(int i = 1; i <= n; ++i) {
			while(j > 0 && i*j > mid) j--;
			cnt += j;
		}

		if(cnt < k) lo = mid + 1;
		else hi = mid;
	}

	return lo;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    cout << find2(n, m, k);
}