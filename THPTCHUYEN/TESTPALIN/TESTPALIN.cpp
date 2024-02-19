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

const int N = 5005;
const string yno[] = {"NO\n", "YES\n"};

int n;
bool isPalind[N][N];
string s;

void opt(int x, int y) {
    if(x != y) {
        if(s[x] == s[y]) isPalind[x][y] = true; else return;
    }

    --x, ++y;
    while(x >= 0 && y < n) {
        if(s[x] == s[y]) isPalind[x][y] = true; else return;
        --x, ++y;
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    memset(isPalind, false, sizeof(isPalind));
    for(int i = 0; i < n; ++i) isPalind[i][i] = true;
    for(int i = 0; i < n - 1; ++i) {
        opt(i, i);
        opt(i, i + 1);
    }
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << yno[isPalind[l][r]];
    }

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4680