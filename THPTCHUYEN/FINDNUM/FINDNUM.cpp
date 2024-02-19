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

ll p[] = {2, 3, 5, 7, 11, 13, 17, 19, 29, 31, 31, 37, 41};
ll n;

ll query(ll div, ll num, ll pr) {
    if(div == n) return num;

    ll res = 1e18;

    for(int POW = 1;; ++POW) {
        num *= p[pr];
        if(div * (POW + 1) > n || num > res) break;

        res = min(res, query(div * (POW + 1), num, pr + 1));
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    // int n;
    cin >> n;
    cout << query(1, 1, 0);

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9764