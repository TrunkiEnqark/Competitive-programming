#include <bits/stdc++.h>

#define ll unsigned long long
#define endl '\n'
#define pb push_back

using namespace std;

const int limit = 2700000;

vector<int> p;

void era() {
	vector<bool> f(limit+5, 1);
	//memset(f, 1, sizeof(f));
	f[0] = f[1] = 0;
	for(int i = 3; i*i <= limit; i += 2) 
		if(f[i]) for(int j = i*i; j <= limit; j += i) f[j] = 0;

	p.pb(2);
	for(int i = 3; i <= limit; i += 2) if(f[i]) p.pb(i);
}

void pr() {
	ll n, k; cin >> n >> k;
	ll pos = 0;
	ll g = 1;
	for(ll i = 0; i < k; ++i) {
		if(g > n/p[i]) { cout << -1 << endl; return; }
		g *= p[i];
	}
	while(g/p[pos] <= n/p[pos + k]) {
		g = g/p[pos] * p[pos + k];
		++pos;
	}
	cout << g << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	era();
	while(t--) pr();
}