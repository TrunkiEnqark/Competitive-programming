#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const string yno[2] = {"No\n", "Yes\n"};

bool check(ll a, ll b, ll c) {
	return ( (a + b > c) && (a + c > b) && (b + c > a) );
}

bool VV(ll u, ll U, ll v, ll V, ll w, ll W) {
	ld X = w*w + u*u - V*V,
	   Y = v*v + w*w - U*U,
	   Z = u*u + v*v - W*W,
	   T = u*v*w;
	   return ((sqrt(X*Y*Z + 2*2*T*T - u*u*Y*Y - v*v*X*X - w*w*Z*Z) / 12) > 0);		
}

bool pr() {
	ll x[6];
	for(int i = 0; i < 6; ++i) cin >> x[i];
	sort(x, x+6);
	if(x[0] <= 0) return 0;

	do {
		bool OAB = check(x[0], x[1], x[2]), 
			 OAC = check(x[0], x[1], x[3]),
			 OBC = check(x[0], x[2], x[3]),
			 ABC = check(x[1], x[2], x[3]),
			 OABC = VV(x[3], x[0], x[4], x[1], x[5], x[2]);	
		if(OAB && OBC && OAB && ABC && OABC) return 1; 
	} while(next_permutation(x, x+6));
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) cout << yno[pr()];

	return 0;
}