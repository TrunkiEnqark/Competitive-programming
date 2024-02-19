#include <bits/stdc++.h>

#define NAME 		""
#define ll 			unsigned long long
#define ii 			pair<int, int>
#define ib 			pair<int, bool>
#define pll 		pair<ll, ll>
#define iii 		pair<int, ii>
#define iiii 		pair<ii, ii>
#define pb 			push_back;
#define fi 			first
#define se 			second
#define fo(i,a,b)	for(int i = a; i <= b; ++i)
#define fod(i,a,b)  for(int i = a; i >= b; --i)
#define rep(i,a)	for(int i = 0; i < a; ++i)
#define repd(i,a)   for(int i = a-1; i >= 0; --i)
#define all(a)		a.begin(), a.end()
#define maxx(a,b,c) max(a, max(b, c))
#define minn(a,b,c) min(a, min(b, c)) 

using namespace std;

const int INF = (int)1e9;
const int base = 31;
const ll MOD = 1000000003;

ll poww(ll a, ll b, ll n) {
	if(b == 0) return 1;
	ll res = poww(a, b/2, n);
	return (b%2 == 1) ? ((((res * res) % n) * a) % n) : ((res * res) % n);
}

bool MillerRabin(ll n, ll s, ll m) {
	ll a = (ll) rand() % (n - 2) + 2, b = poww(a, m, n);
	ll pre = n - 1;
	repd(i, s + 1) {
		if(b == 1) return (pre == n - 1);
		pre = b;
		b = (b * b) % n;
	}
	return 0;
}

bool isPrime(ll n) {
	if(n == 2) return 1;
	if(n % 2 == 0 || n < 2) return 0;
	ll s = 63 - __builtin_clzll((n - 1) & (1 - n)), m = (n - 1) >> s;
	rep(k, 30) 
		if(!MillerRabin(n, s, m)) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); srand(time(NULL));

	int t; scanf("%d", &t);
	while(t--) {
		ll n; scanf("%llu", &n);
		while(!isPrime(--n));
		printf("%llu\n", n);
	}

	return 0;
}