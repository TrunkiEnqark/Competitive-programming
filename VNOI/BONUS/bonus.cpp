#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int a[n+1][n+1], f[n+1][n+1];
	fo(i,1,n) fo(j,1,n) cin >> a[i][j];
	fo(i,1,n) fo(j,1,n) f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
	int ans = INT_MIN;
	fo(i,k,n) fo(j,k,n) ans = max(ans, f[i][j] - f[i-k][j] - f[i][j-k] + f[i-k][j-k]);
	cout << ans; 
}

//Link: https://oj.vnoi.info/problem/bonus