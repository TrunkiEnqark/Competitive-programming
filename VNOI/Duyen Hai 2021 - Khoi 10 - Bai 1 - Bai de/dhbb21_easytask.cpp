#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int L = (int) 1e7+6;

vector<bool> isPrime(L, true);
vector<int> prime, a, s;

void era() {
	// memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i <= L; ++i)
		if(isPrime[i]) for(int j = i*i; j <= L; j += i) isPrime[j] = false;

	prime.pb(2);
	for(int i = 3; i <= L; i += 2) if(isPrime[i]) prime.pb(i);
	// N = prime.size();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	a.resize(n+1); 
	s.resize(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	era();
	int ans = INT_MIN;
	for(int l = 0; prime[l] <= n; ++l) 
		for(int r = l; prime[r] <= n; ++r) {
			ans = max(ans, s[prime[r]] - s[prime[l]-1]);
		}
	cout << ans;
}