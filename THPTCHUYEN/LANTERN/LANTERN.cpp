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

int n, m, a[N];

bool ok(int d) {
    int cnt = 0;
    for(int i = 1; i <= m; ++i) cnt += (a[i]/d + (a[i]%d != 0));
    return cnt <= n;
}

int find() {
    int l = 1, r = 1e9 + 7, res = -1;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ok(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> a[i];

    cout << find();

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9952