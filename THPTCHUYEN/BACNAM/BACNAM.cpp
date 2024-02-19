#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
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

const int N = 1e5 + 5;

int n;
bool flag[N];

void sub1() {
	int a[N];
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	int r1 = 0, r2 = 0, step1 = 1, step2 = 2;
	while(step1 <= n) {
		for(int i = 0; i < n; ++i) {
			if(a[i] == step1 && !flag[i]) {
				flag[i] = true;
				step1 += 2;
			}
		}
		++r1;
	}

	while(step2 <= n) {
		for(int i = 0; i < n; ++i) {
			if(a[i] == step2 && !flag[i]) {
				flag[i] = true;
				step2 += 2;
			}
		}
		++r2;
	}

	cout << r1 << '\n' << r2;
}

void sub2() {
	vector<ii> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}

	sort(all(a));

	int r1 = 1, r2 = 1;
	for(int i = 2; i < n; ++i) {
		if(a[i].fi&1 && a[i].se < a[i-2].se) ++r1;
		if(a[i].fi%2 == 0 && a[i].se < a[i-2].se) ++r2; 
	}
	cout << r1 << endl << r2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	cin >> n;

	if(n <= 1000) sub1(); else sub2();

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10976