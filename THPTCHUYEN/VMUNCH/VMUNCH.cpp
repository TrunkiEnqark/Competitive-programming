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

const int N = 105;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, x, y, u, v, d[N][N];
bool flag[N][N], g[N][N];

void bfs() {
    queue<ii> q;
    q.push({x, y});
    memset(flag, true, sizeof(flag));
    flag[x][y] = false;
    d[x][y] = 0;

    while(!q.empty()) {
        int X = q.front().fi, Y = q.front().se;
        // flag[X][Y] = false;
        q.pop();

        for(int k = 0; k < 4; ++k) {
            int xx = X + dx[k], yy = Y + dy[k];
            if(xx > 0 && xx <= n && yy > 0 && yy <= m && flag[xx][yy] && g[xx][yy]) {
                q.push({xx, yy});
                flag[xx][yy] = false;
                d[xx][yy] = d[X][Y] + 1;
                if(xx == u && yy == v) {
                    cout << d[xx][yy];
                    exit(0);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if(c == 'B') x = i, y = j;
            if(c == 'C') u = i, v = j;
            g[i][j] = (c == '*' ? false : true);
        }

    bfs();
    cout << -1;

    return 0;
}