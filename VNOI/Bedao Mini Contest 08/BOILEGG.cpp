#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		cout << ((ll) n == (ll) sqrt(n)*sqrt(n)) << "\n";
	}
}