#include <bits/stdc++.h>

#define NAME        ""

#define ILTQ				 	int main()
#define ll          			long long
#define ii         		  		pair<ll, int>
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
const int N = 5005;

int n, m;
ll dp[N], d[N], trace[N];
vector<ii> g[N];

void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i = 0; i < N; ++i) d[i] = 1e16;
    
    pq.push({0, 1});
    d[1] = 0;
    dp[1] = 1;

    while(!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if(d[u] != du) continue;

        for(auto it : g[u]) {
            int v = it.second;
            ll uv = it.first;
            if(d[v] > du + uv) {
                pq.push({d[v] = du + uv, v});
                dp[v] = dp[u];
                trace[v] = u;
            } else if(d[v] == du + uv) dp[v] += dp[u], trace[v] = u;
        }
    }

    vector<int> v;
    for(int i = n; i != 1; i = trace[i]) v.pb(i);
    v.pb(1);
    reverse(all(v));
    for(auto it : v) cout << it << ' ';
    cout << endl;

    cout << d[n] << ' ' << dp[n];
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    while(m--) {
        int k, u, v, l;
        cin >> k >> u >> v >> l;
        g[u].pb({l, v});
        if(k == 2) g[v].pb({l, u});
    }

    dijkstra();

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh