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

int n, a[25];
vector<ll> r;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int msk = 0; msk < (1 << n); ++msk) {
        ll sum = 0ll;
        for(int i = 0; i < n; ++i) if(msk & (1 << i)) sum += a[i];
        r.pb(sum);
    }

    sort(all(r));
    for(int i = 1; i < r.size(); ++i) if(r[i] - r[i - 1] > 1) {
        cout << r[i - 1] + 1;
        return 0;
    }
    cout << r.back() + 1;


    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9823