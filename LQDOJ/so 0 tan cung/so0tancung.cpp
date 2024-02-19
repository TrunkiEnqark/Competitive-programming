#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define ll unsigned long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

struct cmp {
	bool operator() (ii &a, ii &b) { return min(a.fi, a.se) < min(b.fi, b.se); }
};

ii get(ll a) {
	int m2 = 0, m5 = 0;
	while(a%2 == 0) { ++m2; a /= 2; }
	while(a%5 == 0) { ++m5; a /= 5; }
	return ii(m2, m5);
}

int main() {
	freopen("task.inp", "r", stdin);
	ll n, k; cin >> n >> k;
	vector<ii> qu;
	while(n--) {
		ll a;
		cin >> a;
		qu.pb(get(a)); 
	}
	//for(priority_queue<ii>::iterator it = qu.begin(); it != qu.end(); ++it) cout << *it.fi << ' ' << *it.se << endl;
	//while(!qu.empty()) { cout << qu.top().fi << ' ' << qu.top().se << endl; qu.pop(); }
	ii res = ii(0,0);
	while(k--) { res = ii(res.fi + qu.top().fi, res.se + qu.top().se); qu.pop(); }
	cout << min(res.fi, res.se);
	return 0;
}