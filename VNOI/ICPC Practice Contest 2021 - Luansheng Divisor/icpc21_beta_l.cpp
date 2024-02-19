#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

void comp(ll n) {
	bool check = true;
	for(ll i = 1; i*(i+1) <= n/2; ++i) 
		if(n%i == 0 && n%(i+1) == 0) cout << i << ' ', check = false;
	if(check) cout << -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		comp(n);
		cout << '\n';
	}
}