#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
 
const int N = 1e3 + 5;
const int lim = 101;

int n, A, B, C;
vector<ii> a, b, c;
vector<int> ans;
bool ok[N];

bool cmp(const ii &x, const ii &y) {
    return (x.fi < y.fi || (x.fi == y.fi && x.se > y.se));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(ok, false, sizeof ok);
    cin >> n >> A >> B >> C;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    for(int i = 0; i < n; ++i) cin >> b[i].first, b[i].second = i;
    for(int i = 0; i < n; ++i) {
        c[i].first = a[i].first + b[i].first;
        c[i].second = i;
    }

    sort(rall(a), cmp);
    sort(rall(b), cmp);
    sort(rall(c), cmp);

    for(int i = 0; i < A; ++i) {
        // cout << a[i].se << ' ';
        ans.push_back(a[i].se + 1);
        ok[a[i].se] = true;
    }

    for(int j = 1, i = 0; i < n && j <= B; ++i) {
        if(!ok[b[i].se]) {
            // cout << b[i].se << ' ';
            ans.push_back(b[i].se + 1);
            ok[b[i].se] = true;
            ++j;
        }
    }

/*
7 3 0 0
40 70 80 60 50 30 45
84 35 90 77 56 78 20

*/

    for(int j = 1, i = 0; i < n && j <= C; ++i) {
        if(!ok[c[i].se]) {
            // cout << c[i].se << ' ';
            ans.push_back(c[i].se + 1);
            ok[c[i].se] = true;
            ++j;
        }
    }

    sort(all(ans));
    for(auto it : ans) cout << it << '\n';
}