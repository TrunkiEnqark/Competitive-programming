#include <bits/stdc++.h>

#define rep(i, a) for(int i = 0; i < a; ++i)

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<vector<int> > a(n, vector<int> (m));
	int s1 = 0, s2 = 0;
	rep(i, n) rep(j, m) {
		cin >> a[i][j];
		s1 += (a[i][j] == 1);
		if(a[i][j] == 1) a[i][j] = 0; else a[i][j] = 1;
		s2 += (a[i][j] == 1);
	}
	
}