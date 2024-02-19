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

const int N = 2e3 + 5;

int n, k, u = INT_MAX, v = -1;
string s;
int dp[N][N];
bool ok[N][N];

void opt(int x, int y) {
    if(s[x] == s[y]) ok[x][y] = true; else return;

    --x, ++y;
    while(x > 0 && y <= n) {
        if(s[x] == s[y]) ok[x][y] = true; else return;
        --x, ++y;
    }
}

void back(int i, int j, int cnt) {
    if(i > j) return;

    if(ok[i][j] && cnt == k) {
        if(i <= u) {
            u = i;
            v = j;
        }
        return;
    }

    back(i + 1, j, cnt + 1);
    back(i, j - 1, cnt + 1);
    // back(i + 1, j - 1, cnt + 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    cin >> s;
    s = "?" + s;

    memset(ok, false, sizeof(ok));
    for(int i = 1; i < n; ++i) {
        opt(i, i);
        opt(i, i + 1);
    }

    k = n - k;
    for(int i = 1; i <= n - k + 1; ++i) {
        int j = i + k - 1;
        if(ok[i][j]) {
            cout << s.substr(i, j - i + 1);
            return 0;
        }
    }

    cout << "No";

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8682