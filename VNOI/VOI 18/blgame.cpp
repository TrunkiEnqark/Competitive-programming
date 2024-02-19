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
// #define int                     ll

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int N = 1005;

int n, m, a[3], s[N][N], vst[N][N][3][3];
ll diff[N][N];

bool check(int x, int y, int id1, int id2) {
    int u = x + a[id1] - 1;
    int v = y + a[id2] - 1;
    return (1 <= x && x <= n && 1 <= u && u <= n && 1 <= y && y <= m && 1 <= v && v <= m && 
            !vst[x][y][id1][id2] && s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1] == 0);
}

void dfs(int x, int y, int id1, int id2) {
    vst[x][y][id1][id2] = 1;
    
    int u = x + a[id1];
    int v = y + a[id2];
    diff[x][y]++;
    if(u <= n) diff[u][y]--;
    if(v <= m) diff[x][v]--;
    if(u <= n && v <= m) diff[u][v]++;

    // len tren
    if(check(x + 1, y, id1, id2)) dfs(x + 1, y, id1, id2);
    // xuong duoi
    if(check(x - 1, y, id1, id2)) dfs(x - 1, y, id1, id2);
    // sang phai
    if(check(x, y + 1, id1, id2)) dfs(x, y + 1, id1, id2);
    // sang trai
    if(check(x, y - 1, id1, id2)) dfs(x, y - 1, id1, id2);
    
    int id3 = 3 - id1 - id2;
    // lat len
    if(check(x - a[id3], y, id3, id2)) dfs(x - a[id3], y, id3, id2);
    // lat xuong
    if(check(x + a[id1], y, id3, id2)) dfs(x + a[id1], y, id3, id2);
    // lat trai
    if(check(x, y - a[id3], id1, id3)) dfs(x, y - a[id3], id1, id3);
    // lat phai
    if(check(x, y + a[id2], id1, id3)) dfs(x, y + a[id2], id1, id3);
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int k;
    cin >> a[0] >> a[1] >> a[2] >> n >> m >> k;
    while(k--) {
        int x, y;
        cin >> x >> y;
        s[x][y] = 1;
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    dfs(1, 1, 0, 1);
    
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if(diff[i][j] > 0) ans++;
        }

    cout << ans;
    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh