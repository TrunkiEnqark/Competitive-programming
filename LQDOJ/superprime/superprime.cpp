#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

bool check(ll a) {
	if(a < 2) return false;
 	for(int i = 2; i*i <= a; ++i) 
		if(a%i == 0) return false;
	return true;
}

int main() {
	ll n; cin >> n;
	if(!check(n%10)) { cout << "NO"; return 0; }
	if(check(n)) cout << "YES"; else cout << "NO";
}