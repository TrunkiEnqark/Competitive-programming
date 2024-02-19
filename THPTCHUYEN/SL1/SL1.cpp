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

bool ok(int a) {
    if(a < 2) return false;
    for(int i = 2; i*i <= a; ++i) if(a%i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    int res = 0;
    for(int mark = 0; mark <= (1 << n); ++mark) {
        int cnt1 = 0;
        for(int i = 0; i < n; ++i) 
            if((mark >> i)&1) ++cnt1;
        int cnt0 = n - cnt1;
        if(ok(cnt1) && ok(abs(cnt1 - cnt0))) ++res; 
    }
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9795