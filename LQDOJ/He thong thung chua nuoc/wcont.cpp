#include <bits/stdc++.h>

using namespace std;

const int N = 65535 + 5;

int n, q, deg[N], cnt[N];
vector<int> g[N];
bool flag[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // freopen("txt.inp", "r", stdin);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int s = q;
        while(q--) {
            int a;
            cin >> a;
        }

        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }

        queue<int> qu;
        qu.push(1);
        memset(flag, true, sizeof flag);
        memset(deg, 0, sizeof deg);
        memset(cnt, 0, sizeof cnt);
        flag[1] = false;
        int m = 1;
        deg[1] = 1;
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();

            for(auto v : g[u]) {
                if(flag[v]) {
                    deg[v] = deg[u] + 1;
                    m = max(m, deg[v]);
                    flag[v] = false;
                    qu.push(v);
                }
            }
        }

        for(int i = 1; i <= n; ++i) ++cnt[deg[i]];
        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            // cout << cnt[i] << ' ';
            if(s >= cnt[i]) {
                ans += cnt[i];
                s -= cnt[i];
            } else break;
        }
        cout << ans << endl;
    }
}