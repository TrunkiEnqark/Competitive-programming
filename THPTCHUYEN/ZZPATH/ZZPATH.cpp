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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll n, m, x, y, z;
    cin >> n >> m >> x >> y >> z;
    
    if(x%2 == 0) y = m - y + 1;
    ll res = (ll) m*(x - 1) + y;
    cout << res << endl;

    ll u = (z%m != 0 ? ((z/m + 1) * m)/m : z/m);
    ll v = z - m*(u - 1);
    if(u%2 == 0) v = m - v + 1;
    cout << u << ' ' << v;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9957