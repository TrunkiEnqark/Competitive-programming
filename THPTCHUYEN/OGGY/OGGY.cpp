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

const int N = 2e8;

int n, m;
vector<int> p;

int solve(int n, ll r) {
    ll sum = 0;
    for (ll msk = 1; msk < (1ll<<p.size()); ++msk) {
        ll mult = 1, bits = 0;
        for (int i = 0; i < (int) p.size(); ++i)
        if (msk & (1ll << i)) {
            ++bits;
            mult *= p[i];
        }
 
        ll cur = r / mult;
        if (bits % 2 == 1) sum += cur;
        else sum -= cur;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    p.resize(n);
    for(auto &it : p) cin >> it;
    sort(all(p));
    cout << solve(n, m);

    return 0;
}