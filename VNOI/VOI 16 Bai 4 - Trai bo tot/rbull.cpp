#include <bits/stdc++.h>

#define fo(i, a, b)  for(int i = a; i <= b; ++i)
#define fod(i, a, b) for(int i = a; i >= b; --i)

using namespace std;

const int N = 2005;

int n, m, a[N][N], s[N<<1][N<<1], b[N<<1][N<<1], f1[N][N], f2[N][N], f3[N][N], f4[N][N]; 

int calc(int i, int j, int R) {
	int l = j - R + 1;
	int r = j + R - 1;
	int x = r + i - 1;
	int y = n - i + r;
	int u = l + i - 1;
	int v = n - i + l;
	return s[x][y] - s[u-1][y] - s[x][v-1] + s[u-1][v-1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fo(i, 1, n) fo(j, 1, m) {
		char c; cin >> c;
		a[i][j] = b[i+j-1][n-i+j] = (c == '*');
	}

	fo(i, 1, n+m-1) fo(j, 1, n+m-1) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + b[i][j];

	fo(i, 1, n) fo(j, 1, m) 
		if(a[i][j] && (a[i-1][j] || a[i][j-1])) f1[i][j] = 1;
			else f1[i][j] = min(f1[i-1][j], f1[i][j-1]) + 1;

	fo(i, 1, n) fod(j, m, 1) 
		if(a[i][j] && (a[i-1][j] || a[i][j+1])) f2[i][j] = 1;
			else f2[i][j] = min(f2[i-1][j], f2[i][j+1]) + 1;

	fod(i, n, 1) fo(j, 1, m) 
		if(a[i][j] && (a[i+1][j] || a[i][j-1])) f3[i][j] = 1;
			else f3[i][j] = min(f3[i+1][j], f3[i][j-1]) + 1;

	fod(i, n, 1) fod(j, m, 1) 
		if(a[i][j] && (a[i+1][j] || a[i][j+1])) f4[i][j] = 1;
			else f4[i][j] = min(f4[i+1][j], f4[i][j+1]) + 1;

	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	fo(i, 1, n) fo(j, 1, m) {
		int r = min({f1[i][j], f2[i][j], f3[i][j], f4[i][j]});
		int sum = calc(i, j, r);
		if(sum > r1) {
			r1 = sum;
			r2 = i;
			r3 = j;
			r4 = r;
		}
	}
	cout << r1 << ' ' << r2 << ' ' << r3 << ' ' << r4-1;
	return 0;
}