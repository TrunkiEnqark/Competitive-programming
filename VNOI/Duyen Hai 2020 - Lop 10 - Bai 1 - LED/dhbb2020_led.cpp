#include <bits/stdc++.h>

using namespace std;

const int f1[]   = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6 },
		  f2_1[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2 },
		  f2_2[] = {0, 1, 0, 0, 0, 0, 0, 2, 0, 1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int type; cin >> type;
	string s; cin >> s;
	int res = 0;
	if(type == 1) {
		for(auto x:s) res += f1[x-'0'];
	} else {
		res = 1;
		for(auto x:s) res = res*f2_1[x-'0'] - f2_2[x-'0'];
		cout << res - 1 << '\n';
		return 0; 
	}
	cout << res;
}