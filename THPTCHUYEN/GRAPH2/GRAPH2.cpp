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

const int N = 1e3 + 5;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, u, v;
bool g[N][N], flag[N][N], d[N][N];

void bfs(int u, int v) {
    queue<ii> q;
    q.push({u, v});
    flag[u][v] = false;
    d[u][v] = true;

    while(!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        for(int k = 0; k < 4; ++k) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(xx > 0 && xx <= n && yy > 0 && yy <= m && flag[xx][yy] && g[xx][yy]) {
                flag[xx][yy] = false;
                d[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m >> u >> v;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> g[i][j];
    memset(flag, true, sizeof(flag));
    memset(d, false, sizeof(d));
    if(!g[u][v]) {
        cout << 0;
        return 0;
    }

    bfs(u, v);

    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) res += d[i][j];
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/6983