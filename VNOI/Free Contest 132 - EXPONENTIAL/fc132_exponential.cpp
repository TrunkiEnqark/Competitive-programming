#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5+1;
const int M = 18;
const int oo = INT_MAX;

vector<vector<int> > POW(N+1, vector<int> (M+1, 0));
map<int, bool> m;

void init() {
	for(int j = 1; j <= M; ++j) POW[1][j] = 1;

	for(int i = 2; i <= N; ++i) {
		POW[i][1] = i;
		for(int j = 2; j <= M; ++j) { 
			if(POW[i][j-1] == +oo) { POW[i][j] = +oo; continue; }
			if(POW[i][j-1]*i <= N) POW[i][j] = POW[i][j-1]*i;
				else POW[i][j] = +oo;
		}
	}
	// cout << 0;
	for(int i = 1; i <= N; ++i)
		for(int j = 2; j <= M; ++j) if(POW[i][j] != +oo) m[POW[i][j]] = true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	int x; cin >> x;
	// int res = -1;0
	for(int i = x; i >= 0; --i) {
		if(m[i]) {
			cout << i;
			return 0;
		}
	}
	// cout << res;
}