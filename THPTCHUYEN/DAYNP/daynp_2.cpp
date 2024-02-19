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

int n;
ll k;

// tim vi tri k trong xau do dai 2^n
int back(int n, ll k) {
    if(n == 0) return 1;

    ll length = 1ll << (n - 1);
    if(k <= length) return back(n - 1, k);
        else return 1 - back(n - 1, k - length);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    cout << back(n, k);

    return 0;
}