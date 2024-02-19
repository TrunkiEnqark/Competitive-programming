#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 105;
const int INF = 1e9;

int n, r[5], dis[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("text.inp", "r", stdin);

    cin >> n >> r[1] >> r[2] >> r[3] >> r[4];
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) dis[i][j] = INF;
    
    for(int i = 1; i <= n; ++i) dis[i][i] = 0;
    
    int p, q, w;
    while(cin >> p >> q >> w) {
        dis[p][q] = dis[q][p] = w;
    }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    
    int ans = INF;
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j) {
                for(int x = 1; x <= 4; ++x)
                for(int y = 1; y <= 4; ++y)
                for(int u = 1; u <= 4; ++u)
                for(int v = 1; v <= 4; ++v) 
                    if(x * y * u * v == 24 && x + y + u + v == 10) { 
                        ans = min(ans, dis[i][r[x]] + dis[i][r[y]] + dis[i][j] + dis[j][r[u]] + dis[j][r[v]]);
                    }
        }

    cout << ans;
}