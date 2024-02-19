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

int n, cnt[27];
ll res = 0, pen = 0;
bool isAC[27];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    memset(isAC, false, sizeof(isAC));
    memset(cnt, 0, sizeof(cnt));
    while(n--) {
        int time;
        char X;
        string ans;
        cin >> time >> X >> ans;
        int p = X - 'A';
        if(!isAC[p]) {
            if(ans == "AC") {
                ++res;
                pen += time + cnt[p]*20;
                isAC[p] = true;
            } else {
                ++cnt[p];
            }
        }
    }
    if(res == 0) {
        cout << 0;
        return 0;
    }

    cout << res << ' ' << pen;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9894