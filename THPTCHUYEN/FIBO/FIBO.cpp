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

const int N = 1e4 + 5;

int n, F[N], i, res = 0;

void calc(int n) {
    if(n == 0) return;
    for(int j = i; j > 0; --j) if(F[j] <= n) { ++res; calc(n - F[j]); return; }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    F[1] = 1, F[2] = 1;
    i = 3;
    int tmp = 2;
    while(tmp < n) F[i] = F[i - 1] + F[i - 2], ++i, tmp = F[i - 1];
    --i;
    // for(int j = 1; j <= i; ++j) cout << F[j] << ' ';
    calc(n);
    cout << res;
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4694