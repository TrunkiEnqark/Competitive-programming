#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,mmx,abm")

#include <bits/stdc++.h>

#define NAME        ""

// #define int                     long long
#define ILTQ				 	int main(void)
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

const int N = 1005;

int t[2] = {0, 5};
int n, k, f[N];
pair<ll, int> p[N];

ll S(int n, vector<int> x, vector<int> y) {
    ll res = 0;
    x.pb(x[0]), y.pb(y[0]);
    for(int i = 0; i < n; ++i) res += 1ll * (x[i] - x[i + 1]) * (y[i] + y[i + 1]);
    return res;
}

void read(int i) {
    int n, c;
    cin >> n >> c;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    p[i] = {S(n, x, y), c};
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) read(i);

    sort(p + 1, p + n + 1);

    for(int i = n; i > 1; --i) p[i].first -= p[i - 1].first;

    ll ans = 0;
    for(int c = 1; c <= n; ++c) {
        for(int i = 1; i <= n; ++i) f[i] = f[i - 1] + (p[i].second != c);

        ll sum = 0, res = 0;
        for(int l = 1, r = 1; r <= n; ++r) {
            sum += p[r].first;
            while(l <= r && f[r] - f[l - 1] > k) {
                sum -= p[l++].first;
            }   
            res = max(res, sum);
        }        
        ans = max(ans, res);
    }
    cout << ans / 2 << '.' << t[ans%2];

    return 0;
}
