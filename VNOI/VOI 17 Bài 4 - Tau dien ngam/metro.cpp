#include <bits/stdc++.h>

#define NAME "metro"

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<ll, int>
#define iii         pair<ii, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

const int N = 5e5 + 5;
const ll INF = 1e16;

int n, m, x, y, p, last_x;
ll d[N];
vector<iii> e[N];

ll dijkstra() {
    for(int i = 1; i <= n; ++i) d[i] = INF;
    d[x] = 0;
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push({{0, x}, 0});
    
    while(!q.empty()) {
        int u = q.top().fi.se;
        int tr = q.top().se;
        ll du = q.top().fi.fi;
        q.pop();

        if(du != d[u]) continue;

        for(auto it : e[u]) {
            int v = it.fi.se;
            ll uv = it.fi.fi;
            int k = it.se;
            if(d[v] > (ll) d[u] + uv + tr * p + k && tr != 0) q.push({{d[v] = (ll) d[u] + uv + tr * p + k, v}, k});
                else if(d[v] > (ll) d[u] + uv && tr == 0) q.push({{d[v] = (ll) du + uv, v}, k});
        }
    }

    return (d[y] == INF ? -1 : d[y]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m >> x >> y >> p;
    for(int p, q, i = 1; i <= m; ++i) {
        ll c;
        cin >> p >> q >> c;
        e[p].pb({{c, q}, i});
    }

    cout << dijkstra();

    return 0;
}
