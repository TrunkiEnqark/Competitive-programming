#include <bits/stdc++.h>

#define NAME 		""
#define ll 			long long
#define ii 			pair<int, int>
#define ib 			pair<int, bool>
#define pll 		pair<ll, ll>
#define iii 		pair<int, ii>
#define iiii 		pair<ii, ii>
#define pb 			push_back;
#define fi 			first
#define se 			second
#define fo(i,a,b)	for(ll i = a; i <= b; ++i)
#define fod(i,a,b)  for(ll i = a; i >= b; --i)
#define rep(i,a)	for(ll i = 0; i < a; ++i)
#define all(a)		a.begin(), a.end()
#define maxx(a,b,c) max(a, max(b, c))
#define minn(a,b,c) min(a, min(b, c)) 

using namespace std;

const int INF = (int)1e9;
const int base = 31;
const ll MOD = 1000000003;
const ll L = (int)1e6;

ll phi[L], f[L];

void init() {
	fo(i, 1, L) phi[i] = i;

	fo(i, 2, L) if(phi[i] == i) 
		for(int j = i; j <= L; j += i) phi[j] -= phi[j] / i;
	
	f[1] = 0;
	fo(i, 2, L) f[i] = f[i-1] + phi[i];
}

void pr(ll n) {
	ll sum = 0;
	for(ll i = 1; i <= n; ) {
		ll q = n / i;
		ll r = n / q;
		sum += (r - i + 1) * (i + r) / 2 * f[q];
		i = r + 1; 
	} 
	cout << sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	init();
	ll n;
	while(cin >> n) {
		if(n == 0) break;
		pr(n);
	}

	return 0;
}