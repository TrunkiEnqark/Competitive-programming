#include <bits/stdc++.h>

#define ll long long

using namespace std;

int calc(int x) {
	int res = 1;
	for(int i = 2; i*i <= x; ++i) {
		if(x%i == 0) {
			res = i;
			break;
		}
	}
	if(res == 1) return x; else return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b; cin >> b >> a;
	for(int x = a; x > b; --x) {
		if(calc(x) > b) {
			cout << x;
			return 0;
		}
	}
	cout << -1;
}