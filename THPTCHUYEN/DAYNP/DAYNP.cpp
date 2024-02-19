#include <bits/stdc++.h>

#define NAME "daynp"

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define ss          pair<string, string>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

// string b[64];

int n;
ll k;
string res = "1";
string last_res = res;
string last = "0";

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    
    for(int i = 1; i <= n; ++i) {
        last_res = res;
        res = res + last;
        last = last + last_res;
        if((ll) res.size() >= k) {
            cout << res[k-1];
            return 0;
        }

        if(k > (ll) res.size() && k <= (ll) res.size() * 2) {
            cout << (res[k - res.size() - 1] == '0' ? '1' : '0');
            return 0;
        }
    }
    cout << res[k-1];

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10958