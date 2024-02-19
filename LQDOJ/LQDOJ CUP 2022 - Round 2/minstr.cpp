#include<bits/stdc++.h>

using namespace std;
string s, a, b;
int n, m, f[5005][5005], g[5005];
int main(){
    freopen("minstr.inp", "r", stdin);
    freopen("minstr.out", "w", stdout);
    cin >> n >> m >> a;
    a = "#"+a+a;
    for (int i = 0; i < m; i++){
        cin >> s;
        b += "#" + s;
    }
    m = b.length();
    for (int i = 1; i <= 2*n; i++) for (int j = 1; j <= m; j++){
        if (a[i]==b[j]) f[i][j] = f[i-1][j-1] + 1;
        g[i] = max(g[i],f[i][j]);    
    }
//    cout << a << endl;
    int res = 1e9;
    for (int i = 1, j = n; j <= 2*n; i++,j++){
        int cur = 0;
        for (int k = i; k <= j; k++) cur = max(cur,min(g[k],k-i+1));
        res = min(res,cur);
//        cout << cur << "";
    }
    cout << res;
//    for (int i = 0 ; i <= 2*n; i++) cout << g[i] << "";
    
    return 0;
}