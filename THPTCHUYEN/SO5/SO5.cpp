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

ll a, b, c;

ll calc(ll a, ll b, ll c) {
    if(a%c == 0) return b/c - a/c + 1;
    return b/c - a/c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> a >> b >> c;
    cout << calc(a, b, c);

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4574