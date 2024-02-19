#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	//freopen("binary.inp", "r", stdin);
	int n; cin >> n;
	vector<bool> a(n+1);
	fo(i,1,n) { int k; cin >> k; a[i] = k; }

	vector<int> f(n+1);
	f.assign(n+1, 0);
	int ans = 0;
	fo(i,1,n) { 
		if(a[i]) f[i] = f[i-1] + 1; else f[i] = f[i-1], ans += f[i-1];
		//cout << ans << endl;
	}
	//fo(i,1,n) cout << f[i] << ' ';
	cout << endl << ans;
}