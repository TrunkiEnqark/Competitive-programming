#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define N 222 

using namespace std;

int c[N][N], a[N][N], n;

int sum(int u, int v) {
	return a[u][v] + a[u+1][v] + a[u][v+1] + a[u+1][v+1]; 
}

bool trys(int u, int v) {
	int t = 0, uu = 0, vv = 0;
	if(u == n || v == 1) {
		if(u+v >= n) { vv = n; uu = u + v + 1 - vv; }
			else { uu = 1; vv = u + v + 1 - uu; }
	} else uu = u+1, vv = v-1;

	if(u == n && v == n) {
		a[u][v] = 0;
		t = c[u-1][v-1] - sum(u-1, v-1);
		if(t < 0 || t > 1) return 0;
		a[u][v] = t; return 1;
	}

	if(u == 1) {
		a[u][v] = 0; if(trys(uu,vv)) return 1;
		a[u][v] = 1; if(trys(uu,vv)) return 1;
		return 0;
	}

	if(v == 1) {
		a[u][v] = 0; if(trys(uu,vv)) return 1;
		a[u][v] = 1; if(trys(uu,vv)) return 1;
		return 0;
	}

	a[u][v] = 0; 
	t = c[u-1][v-1] - sum(u-1, v-1);
	if(t < 0 || t > 1) return 0;
	a[u][v] = t;
	if(trys(uu,vv)) return 1;
	return 0; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	fo(i,1,n-1) fo(j,1,n-1) cin >> c[i][j];
	memset(a, 0, sizeof(a));
	bool ok = 0;
	fo(i,0,1) {
		a[1][1] = i;
		if(trys(1,2)) { ok = 1; break; }
	}
	if(!ok) { cout << "no solution"; return 0; }

	fo(i,1,n) { fo(j,1,n) cout << a[i][j] << ' '; cout << endl; }
}