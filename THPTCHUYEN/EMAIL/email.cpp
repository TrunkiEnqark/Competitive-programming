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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int p = s.find('@', 0);
        // cout << s[0];
        for(int i = 1; i < p - 1; ++i) s[i] = '*';
        cout << s << endl;
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9956