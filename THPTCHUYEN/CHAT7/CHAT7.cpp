#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define val 		first
#define idx			second

using namespace std;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

const int N = 5e3 + 5;

int n, a[N];
ii b[N];

int search_min(int k, int j) {
	int l = j, r = n-1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(b[mid].val < k) {
			l = mid + 1;
		} else r = mid - 1;
	}

	return r;
}

int search_max(int k, int j) {
	int l = j, r = n-1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(b[mid].val > k) {
			r = mid - 1;
		} else l = mid + 1;
	}

	return l;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = {a[i], i};
	}

	sort(a, a+n);
	sort(b, b+n);

	ll res = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j) {
			int l = search_min(a[i] + a[j], j+1);
			int r = search_max(abs(a[i] - a[j]), j+1);
			if(l != -1 && r != -1 && l != n && r != n && l >= r) res += l - r + 1;
		}

	cout << res;

	return 0;
}