#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int base = 95;
const ll MOD = 1000000007ll;
const int N = 50005;

ll Pow[N], Hash_Lf[N], Hash_Rt[N]; 
string s;
int n;

void init() {
	s = " " + s;
	Hash_Lf[0] = Hash_Rt[0] = 0;
	Pow[0] = 1;
	for(int i = 1; i <= n; ++i) {
		Pow[i] = (Pow[i-1] * base) % MOD;
		Hash_Lf[i] = (Hash_Lf[i-1] * base + s[i] - 'a') % MOD;
		Hash_Rt[i] = (Hash_Rt[i-1] * base + s[n-i+1] - 'a') % MOD;
	}
}

inline int getHash_Lf(int i, int j) {
	return (Hash_Lf[j] - Hash_Lf[i-1] * Pow[j-i+1] + MOD * MOD) % MOD;
}

inline int getHash_Rt(int i, int j) {
	return (Hash_Rt[n-i+1] - Hash_Rt[n-j] * Pow[j-i+1] + MOD * MOD) % MOD;
}

bool check(int l) {
	for(int i = 1; i <= n-l+1; ++i) 
		if(getHash_Lf(i, i+l-1) == getHash_Rt(i, i+l-1)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	init();
	int l = 1, r = n - (n%2 == 0);
	while(l < r) {
		int mid = (l + r) >> 1; mid += (mid%2 == 0);
		if(check(mid)) l = mid; else r = mid - 2;
	}
	int res = l;
	l = 0, r = n - n%2;
	while(l < r) {
		int mid = (l + r) >> 1; mid += (mid%2);
		if(check(mid)) l = mid; else r = mid - 2;
	}
	cout << max(l, res);
}	