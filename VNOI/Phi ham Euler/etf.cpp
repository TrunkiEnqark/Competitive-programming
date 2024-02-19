#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int phi(int n) {
	int res = n;
	for(int i = 2; i*i <= n; ++i) 
		if(n%i == 0) {
			while(n%i == 0) n /= i;
			res -= res/i;
		}
	if(n != 1) res -= res/n;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int d; cin >> d;
		cout << phi(d) << endl;
	}
}