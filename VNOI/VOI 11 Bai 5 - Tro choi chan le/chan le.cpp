#include <bits/stdc++.h>

#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

const string yno[2] = {"NO\n", "YES\n"};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("test.inp", "r", stdin);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		bool sr[n+1][n+1], sc[n+1][n+1], f[n+1][n+1];
		fo(i,1,n) fo(j,1,n) { 
			int t; cin >> t;  
			sr[i][j] = (sr[i][j-1] + t)&1;
			sc[j][i] = (sc[j][i-1] + t)&1;
		}

		fo(i,1,n) fo(j,1,n) {
			f[i][j] = (!sr[i][j] ? !f[i-1][j] : 0) || (!sc[j][i] ? !f[i][j-1] : 0);
		}
		cout << yno[f[n][n]];
	}
}