#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 2e5 + 5;
const ll oo = LLONG_MAX;

struct line {
	ll k, m, p;
	
	bool operator < (const line &other) { return k < other.k; }
	bool operator < (ll x) { return p < x; }

	ll calc(ll x) { return k*x + m; }
};

deque<line> hull;
int n;
ll c;

ll division(ll a, ll b) {
	return a/b - ((a < 0) != (b < 0) && a%b);
}

bool isect(line &x, const line &y) {
	if(x.k == y.k) x.p = x.m > y.m ? oo : -oo;
		else x.p = division(y.m - x.m, x.k - y.k);
	return x.p >= y.p;
}

void add(ll k, ll m) {
    line L = {k, m, 0};
    while ((int) hull.size() >= 2 && (isect(L, hull.back()), isect(hull.back(), hull[(int) hull.size() - 2]), L.p < hull.back().p))
        hull.pop_back();
    hull.push_back(L);
}

ll query(ll x) {
	while((int) hull.size() >= 2 && hull[0].calc(x) >= hull[1].calc(x)) 
		hull.pop_front();
	return hull[0].calc(x);
}

void insert(int i, vector<ll> &a, vector<ll> &dp) {
	add(-a[i]*2, (dp[i] + a[i] * a[i]));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	vector<ll> a(n), dp(n);
	
	for(auto &x:a) cin >> x;
	// memset(dp, 0, sizeof(dp));
	// ll res = 0;

	dp[0] = 0;
	insert(0, a, dp);
	for(int i = 1; i < n; ++i) {
		ll x = query(a[i]);
		dp[i] = a[i] * a[i] + x + c;
		insert(i, a, dp);
	}
	cout << dp[n-1];
}