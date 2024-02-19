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
int x[N], max_x[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n, k;
    cin >> n >> k;

    max_x[0] = INT_MAX;
    for(int i = 1; i <= k; ++i) cin >> x[i];
    for(int i = 1; i <= k; ++i) max_x[i] = n - k + i;

    int p = k;
    while(x[p] == max_x[p]) --p;

    if(p == 0) {
        cout << -1;
        return 0;
    }

    ++x[p];
    for(int i = 1; i <= p; ++i) cout << x[i] << ' ';
    for(int i = p + 1; i <= k; ++i) {
        x[i] = x[i-1] + 1;
        cout << x[i] << ' ';
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9959