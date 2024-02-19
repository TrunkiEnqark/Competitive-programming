#include <bits/stdc++.h>

using namespace std;

string operator+ (string a, string b) {
	int n = a.size(), m = b.size();
	if(n > m) b.insert(0, n-m, '0'); else a.insert(0, m-n, '0');
	int nho = 0;
	string ans = "";
	for(int i = n-1; i >= 0; --i) {
		int sum = (int)a[i] + (int)b[i] - 96 + nho;
		ans = char(sum%10 + 48) + ans;
		nho = sum/10;
	}
	return nho > 0 ? "1"+ans : ans;
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int t; cin >> t; 
	vector<int> a(t);
	int n = 0;
	for(int i = 0; i < t; ++i) cin >> a[i], n = max(n, a[i]);

	vector<string> f(n+1);
	f[1] = "1"; f[2] = "2";
	for(int i = 3; i <= n; ++i) f[i] = f[i-1] + f[i-2];
	for(int i = 0; i < t; ++i) cout << f[a[i]] << endl; 
}