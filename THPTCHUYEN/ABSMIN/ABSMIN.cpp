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

const int N = 3e5 + 5;

int n, a[N];

int search(int l, int r, int k) {
    int res = INT_MAX;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] == k) return 0;
        if(a[mid] > k) {
            res = min(res, abs(k - a[mid]));
            r = mid - 1;
        } else l = mid + 1;
    }

    return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a+1, a+n+1);

    int res = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        res = min(res, search(i + 1, n, a[i]));
    }

    cout << res;

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8205