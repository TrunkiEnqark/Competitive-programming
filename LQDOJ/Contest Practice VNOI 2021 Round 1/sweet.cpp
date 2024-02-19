#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define rep(i, a) for(int i = 0; i < a; ++i)
#define ll long long

#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
ll w;
vector<ll> a, x, cnt;

void enter() {
	cin >> n >> k;
	
	a.resize(n);
	x.resize(n);
	cnt.resize(n, 0);

	ll s = 0;
	rep(i, n) {
		cin >> a[i];
		s += 1ll*a[i];
		x[i] = i;
	}
	
	w = s/ (1ll*k);
}

bool check() {
	ll s = 0;
	// memset(cnt, 0, sizeof(cnt));
	cnt.resize(n, 0);
	int k = 0;
	rep(i, n) {
		s += a[x[i]];
		if(s > w) return false;
		if(i == 0) continue;
		if(s == w) {
			cnt[x[i]] = cnt[x[i-1]] + 1;
			s = 0;
		} else cnt[x[i]] = cnt[x[i-1]];
	} 
	if(s != 0) return false;
	return true;
}

void sub1() {
	do {
		if(check()) {
			for(auto x:cnt) cout << x+1 << ' ';
			return;
		}
	} while(next_permutation(all(x)));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	enter();
	// if(n <= 10) { sub1(); return 0; }
	sub1();
	// if(!ok) cout << -1;
	return 0;
}