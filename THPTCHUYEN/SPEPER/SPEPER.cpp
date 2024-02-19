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

int n, x[1005];
bool flag[1005];

void solve() {
    for(int i = 1; i <= n; ++i) cout << x[i] << ' ';
    exit(0);
}

void back(int i) {
    for(int j = max(1, x[i - 1] - 4); j <= min(n, x[i - 1] + 4); ++j) {
        if(flag[j]) {
            x[i] = j;
            flag[j] = false;
            if(i == n) solve(); else back(i + 1);
            flag[j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    if(n < 4) {
        cout << -1;
        return 0;
    }
    x[1] = 2;
    memset(flag, true, sizeof(flag));
    flag[2] = false;
    back(2);
    
    cout << -1;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8540