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

int n, res[N];
ii a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; ++i) 
        if(a[i].fi == a[i - 1].fi) res[a[i].se] = res[a[i - 1].se];
            else res[a[i].se] = i;

    for(int i = 1; i <= n; ++i) cout << res[i] - 1 << ' ';

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/7156