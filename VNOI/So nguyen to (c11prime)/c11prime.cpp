#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

bool isPrime(ll a) {
	if(a < 2) return 0;
	if(a == 2) return 1;
	if(a%2 == 0) return 0;
	for(ll i = 3; i*i <= a; i += 2) if(a%i == 0) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	ll n; cin >> n;
	for(int q = 2; q < 64; ++q) {
		ll p = round(exp(log(n) / q));
		ll N = 1;
		for(int tmp = 0; tmp < q; ++tmp) N *= p;
		if(N == n && isPrime(p)) { cout << p << ' ' << q; return 0; } 
	}
	cout << 0;
	return 0;
}