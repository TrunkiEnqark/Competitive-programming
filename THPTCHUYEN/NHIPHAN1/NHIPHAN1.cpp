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

int n, x[25];

void solve() {
    for(int i = 2; i <= n; ++i) if(x[i] == 1 && x[i - 1] == 0) return;

    for(int i = 1; i <= n; ++i) cout << x[i];
    cout << endl;
}

void back(int i) {
    for(int j = 0; j < 2; ++j) {
        x[i] = j;
        if(i == n) solve();
            else back(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    x[0] = 0;
    back(1);

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9869