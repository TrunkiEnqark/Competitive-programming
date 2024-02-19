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
const int N = 1005;
// up -> left -> down -> right 
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, x, y, s, vst[N][N][4], a[N][N];

ILTQ {
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NUL L);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> y >> x >> s;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            char ch;
            cin >> ch;
            a[i][j] = ch == '.';
        }

    if(x - s > n || x < 1 || y < 1 || y > n) {
        x -= s;
        cout << y << ' ' << x;
        return 0;
    }

    if(x > n) {
        s -= (x - (n + 1));
        x = n + 1;
    }

    for(int i = 0; i <= n; ++i) 
        a[0][i] = a[i][0] = a[n + 1][i] = a[i][n + 1] = 1;

    vst[x][y][0] = s;
    int t = 0;
    // cout << x << ' ' << y << endl;
    while(s--) {
        while(a[x + dx[t]][y + dy[t]] == 0) t = (t + 1) % 4;
        x += dx[t];
        y += dy[t];
        if(x < 1 || x > n || y < 1 || y > n) {
            cout << y + s*dy[t] << ' ' << x + s*dx[t];
            return 0;
        }

        if(vst[x][y][t]) {
            s %= (vst[x][y][t] - s);
        } else vst[x][y][t] = s;
    }

    cout << y << ' ' << x;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
