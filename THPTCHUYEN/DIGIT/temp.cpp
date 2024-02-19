#include <bits/stdc++.h>

#define NAME ""

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

int r1[10] = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1}; // 0->10
int r2[10] = {10, 19, 19, 19, 19, 19, 19, 19, 19, 19}; // 11->100
int r3[10] = {181, 280, 280, 280, 280, 280, 280, 280, 280, 280}; // 101->1000
int r4[10] = {2701, 3700, 3700, 3700, 3700, 3700, 3700, 3700, 3700, 3700}; // 1001->10000
int r5[10] = {36001, 46000, 46000, 46000, 46000, 46000, 46000, 46000, 46000, 46000}; // 10001->100000

int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void calc(int n){
	while (n > 0){
		++d[n%10];
		n /= 10;
	}
}

void tinh(int n){
	while (n>0){
		++d[n%10], n/=10;
	}
}

void sub1(int n){ 	
	memset(d, 0, sizeof d);
	rep(i, 1, n) tinh(i);
	rep(i, 0, 9) cout << d[i] << ' ';
	cout << endl;
}


void solve() {
	int n;
	cin >> n;
	memset(d, 0, sizeof(d));
	if(n < 10000) {
		sub1(n);
		return;
	// } else if(n < 10000) {
	// 	for(int i = 0; i <= n%1000; ++i) calc(i);
	// 	for(int i = 0; i < 10; ++i) cout << d[i] + r1[i] + r2[i] + r3[i] << " \n"[i == 9];
	// 	return;
	} else if(n < 100000) {
		for(int i = 10001; i <= n; ++i) calc(i);
		for(int i = 0; i < 10; ++i) cout << d[i] + r1[i] + r2[i] + r3[i] + r4[i] << " \n"[i == 9];
		return;
	} else if(n < 1000000) {
		for(int i = 100001; i <= n; ++i) calc(i);
		for(int i = 0; i < 10; ++i) cout << d[i] + r1[i] + r2[i] + r3[i] + r4[i] + r5[i] << " \n"[i == 9];
		return;
	} else if(n == 1000000) {
		cout << 488895 << 600001 << 600000 << 600000 << 600000 << 600000 << 600000 << 600000 << 600000 << 600000 << '\n';
		return;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}