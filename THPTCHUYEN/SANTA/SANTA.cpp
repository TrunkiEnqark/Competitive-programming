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

ll C(int n, int k) {
    ll res = 1ll;

    for(int i = 1; i <= k; ++i, --n) {
        res = (ll) res * n/i;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    int a = 0, b = 0;

    for(int d; n--; ) {
        cin >> d;
        a += (d == 0);
        b += (d == 1);
    }

    cout << C(a, 2) + C(b, 2);

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8191