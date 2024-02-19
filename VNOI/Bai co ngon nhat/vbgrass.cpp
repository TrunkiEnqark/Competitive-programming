#include <bits/stdc++.h>

#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define cb pair<char, bool>
#define fi first 
#define se second

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	cb s[n+1][m+1];
	fo(i,1,n) fo(j,1,m) cin >> s[i][j].fi, s[i][j].se = 0;
	
	int ans = 0;
	//bool check = 0;
	fo(i,1,n) {
		fo(j,1,m) {
			if(s[i][j].fi == '.') continue; 
				else if(s[i][j].fi == '#' && s[i][j+1].fi != '#' && !s[i][j].se) {
					++ans;
					int x = i+1;
					s[i][j].se = 1;
					while(s[x][j].fi == '#' && s[x][j+1].fi != '#' && !s[x][j].se) s[x][j].se = 1, /*++ans,*/ ++x;
				} else if(s[i][j].fi == '#' && s[i][j+1].fi == '#' && !s[i][j].se && !s[i][j+1].se) {
					++ans;
					int x = i+1;
					s[i][j].se = s[i][j+1].se = 1;
					while(s[x][j].fi == '#' && s[x][j+1].fi == '#' && !s[i][j].se && !s[i][j+1].se) {
						s[x][j].se = s[x][j+1].se = 1;
						//++ans;
						++x;
					}
				}
		}
	}
	cout << ans;
}