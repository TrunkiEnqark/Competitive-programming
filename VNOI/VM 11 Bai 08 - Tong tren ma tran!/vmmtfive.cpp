#include <bits/stdc++.h>

using namespace std;

int d[6], c[6], a[6][6], s1[6], s2[6];

bool check(int x) {
	for(int i = 1; i < 6; ++i)
		for(int j = 1; j < 6; ++j) if(a[i][j] == x) return 0;
	return 1;
}

void result() {
	// for(int i = 1; i < 6; ++i) {
	// 	if(a[i][1] == a[i][2] || a[i][1] == a[i][3] || a[i][1] == a[i][4] || a[i][1] == a[i][5] || a[i][2] == a[i][3] || a[i][2] == a[i][4] || a[i][2] == a[i][5] || a[i][3] == a[i][4] || a[i][3] == a[i][5] || a[i][4] == a[i][5]) return; 
	// }

	for(int i = 1; i < 6; ++i) {
		for(int j = 1; j < 6; ++j) cout << a[i][j] << ' ';
		cout << endl;
	} 
	cout << endl;
	exit(0);
}

void backtrack(int i, int j) {
	if(i > 5) { 
		if(c[5] == 0) result();
		return;
	}
	int l = max(1,  max(d[i] - 25*(5 - j), c[j] - 25*(5 - i)));
	int r = min(25, min(d[i] - 5 + j, c[j] - 5 + i));
	if(l > 25 || r < 1 || l > r) return;
	if(j == 5) l = r = d[i];
	for(int x = r; x >= l; --x) {
		if(!check(x)) continue;
		a[i][j] = x;
		d[i] -= x;
		c[j] -= x;
		if(j < 5) backtrack(i, j+1); else backtrack(i+1, 1);
		d[i] += x;
		c[j] += x;
		a[i][j] = 0;
	}
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("OUT.out", "w", stdout);
	for(int i = 1; i < 6; ++i) cin >> d[i];
	for(int i = 1; i < 6; ++i) cin >> c[i];

	backtrack(1, 1);

	return 0;
}