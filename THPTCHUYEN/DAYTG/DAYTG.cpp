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

const int N = 1e7 + 7;

int n, a[N], maxL[N], maxR[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    maxL[1] = maxR[n] = 1;
    for(int i = 2; i <= n; ++i) 
        if(a[i] > a[i - 1]) maxL[i] = maxL[i - 1] + 1;
            else maxL[i] = 1;
    
    for(int i = n - 1; i >= 1; --i) 
        if(a[i] > a[i + 1]) maxR[i] = maxR[i + 1] + 1;
            else maxR[i] = 1;
    
    int res = 0;
    for(int i = 2; i < n; ++i) res = max(res, maxL[i] + maxR[i] - 1);
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9855