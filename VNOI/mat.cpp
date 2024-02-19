#include <bits/stdc++.h>

#define NAME        ""

#define ILTQ				 	int main()
#define ll          			long long
#define ii         		  		pair<int, int>
#define ld          			long double
#define fi          			first
#define se          			second
#define endl        			'\n'
#define pb          			push_back

#define OK          			cout << "ok\n";
#define all(a)      			a.begin(), a.end()
#define rall(a)     			a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int N = 1e6 + 6;

int n, m, dp[N][40], c[N], h[N], f[N];

ii calc(int p) {
    for(int x = 20; x >= 0; --x) {
        if((p % (1 << x)) == 0) {
            return {x, p / (1 << x)};
        }
    }
    return {-1, -1};
}

int calc(vector<int> v, int key) {
    if(key == 0) return 1;
    int len = v.size();
    if(!len) return 0;

    for(int i = 0; i <= len; ++i) f[i] = 0;
    for(int i = 0; i <= len; ++i)
        for(int j = 0; j < 40; ++j) dp[i][j] = -1;

    for(int i = 0; i < len; ++i) dp[i][v[i]] = i;

    for(int x = 0; x < 40; ++x) {
        for(int i = 0; i < len; ++i) {
            if(dp[i][x] != -1) dp[i][x + 1] = dp[dp[i][x] + 1][x];
        }
    }

    for(int i = len - 1; i >= 0; --i) {
        f[i] = 1e9;
        for(int x = 0; x < 40; ++x) {
            if(dp[i][x] != -1) f[i] = min(f[i], f[dp[i][x] + 1] + 1);
        }
    }
    
    return f[0];
}

int F(int p[], int n) {
    vector<int> vec;
    int res = 0;
    int y = -1;
    for(int i = 1; i <= n; ++i) {
        ii tmp = calc(p[i]);
        if(tmp.second != y) {
            res += calc(vec, y);
            vec.clear();
        }
        y = tmp.second;
        vec.push_back(tmp.first);
    }
    if(vec.size()) res += calc(vec, y);
    return res;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int x;
            cin >> x;
            h[i] += x;
            c[j] += x;
        }
    }

    cout << F(h, n) * F(c, m);

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
