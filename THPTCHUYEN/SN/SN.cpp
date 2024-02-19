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

int n, a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    if(a[1] < 0) {
        cout << a[1] - 1;
        return 0;
    }

    a[0] = 0;
    a[n + 1] = 2e9;
    for(int i = 1; i <= n + 1; ++i) if(a[i] - a[i - 1] > 1) {
        cout << a[i - 1] + 1;
        return 0;
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4695