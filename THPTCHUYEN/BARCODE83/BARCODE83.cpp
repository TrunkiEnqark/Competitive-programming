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

int b[] = {3, 8};

bool bit(int i, int j) {
    return (i >> j) & 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); ++i) {
        int cnt = 0, ok = true;

        for(int j = n - 1; j >= 0; --j) {
            if(bit(i, j)) ++cnt;
            if(bit(i, j) && bit(i, j - 1)) ok = false;
        }
        if(cnt == n - cnt || ok) {
            for(int j = n - 1; j >= 0; --j) cout << b[(i >> j) & 1] << ' ';
            cout << endl;
        }
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9807