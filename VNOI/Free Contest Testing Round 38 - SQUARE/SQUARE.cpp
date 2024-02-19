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

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int a, b;
    cin >> a >> b;
    char ans[101][101];

    for(int i = 1; i <= a; ++i)
        for(int j = 1; j <= a; ++j) ans[i][j] = '*';
    
    for(int i = a - b + 1; i <= a; ++i)
        for(int j = a - b + 1; j <= a; ++j) ans[i][j] = ' ';

    for(int i = 1; i <= a; ++i)
        for(int j = 1; j <= a; ++j) cout << ans[i][j] << " \n"[j == a];

    return 0;   
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh