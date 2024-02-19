#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	string a, b; cin >> a >> b;
	int l1 = a.size(), l2 = b.size();
	int f[l1+1][l2+1];
	memset(f,0,sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= l1; ++i) f[i][1] = f[i-1][1] || (a[i-1] == b[0]);
	for(int j = 1; j <= l2; ++j) f[1][j] = f[1][j-1] || (a[0] == b[j-1]);

	for(int i = 1; i <= l1; ++i) 
		for(int j = 1; j <= l2; ++j) {
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1] + 1;
		}
	cout << f[l1][l2];
}