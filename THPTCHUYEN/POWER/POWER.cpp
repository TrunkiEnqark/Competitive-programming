#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			unsigned long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll a, b, c;

ll POW(ll a, ll b, ll c) {
    if(b == 0) return 1%c;
    else {
        ll t = POW(a, b>>1ll, c);
        t = ((ll) (t%c) * (t%c)) % c;
        if(b%2 == 0) return t%c;
            else return ((t%c) * (a%c))%c;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> a >> b >> c;
    cout << POW(a, b, c)%c;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9838