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

const string yno[] = {"NO\n", "YES\n"};
const int base = 31;
const ll MOD = (ll) 1e9 + 7;
const int N = 1e5 + 5;

int n, q;
string s;
ll POW[N], L[N], R[N];

void init() {
    POW[0] = 1;
    for(int i = 1; i <= n; ++i) {
        POW[i] = (POW[i - 1] * base) % MOD;
        L[i] = (L[i - 1] * base + s[i] - 'a') % MOD;
    }

    for(int i = n; i > 0; --i) {
        R[i] = (R[i + 1] * base + s[i] - 'a') % MOD;
    }
}

ll get_left(int i, int j) {
    return (L[j] - L[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll get_right(int i, int j) {
    return (R[i] - R[j + 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> s;
    n = s.size();
    s = " " + s;
    init();
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int mid = (l + r) >> 1;
        int len = r - l + 1;
        cout << yno[get_left(l, mid - len%2) == get_right(mid + 1, r)];
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4488