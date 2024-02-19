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

bool bit(int mark, int i) {
    return (mark >> i) & 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    int res = 0;

    for(int mark = 0; mark < (1 << n); ++mark) {
        int cnt = 0;
        for(int i = n - 1; i >= 0; --i) cnt += (!bit(mark, i) && bit(mark, i - 1));
        if(cnt <= 1) {
            for(int i = n - 1; i >= 0; --i) cout << ((mark >> i)&1);
            cout << endl;
        }

        res += (cnt <= 1);
    }

    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9872