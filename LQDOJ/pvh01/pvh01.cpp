#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; i++)
#define Int long long
#define pb push_back
#define fi cin 
#define fo cout 
//	ifstream fi("pvh01.inp");
//	ofstream fo("pvh01.out");
typedef vector <int> vi;
typedef vector <vi> vii;

vii a;
int n, m, r, c, k;
int tinh(int x, int y, int u, int v){
	vi b;
	rep(i, x, u)
		rep(j, y, v)
			b.pb(a[i][j]);
	sort(b.begin(), b.end());
	return b[k];
}
int main(){
	fi>>n>>m>>r>>c;
	k=(r*c+1)/2 - 1;
	a.resize(n+1, vi(m+1));
	rep(i, 1, n)
		rep(j, 1, m)
			fi>>a[i][j];
				
	int ans=0;

	rep(i, r, n)
		rep(j, c, m){
			ans=max(tinh(i-r+1, j-r+1, i, j), ans);
		}
	fo<<ans;
}
