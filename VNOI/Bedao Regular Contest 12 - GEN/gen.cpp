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
    
    int n;
    cin >> n;
    int mx = 0;
    bool so0 = false;
    while(n--) {
        string a;
        cin >> a;
        
        // if(a > mx) {
            // so0 = true;
            // mx = a;
        // }
        // mx = max(mx, a);
    }

    int len = log10(mx) + 1;
    int res = 0;
    while(len--) res = res*10 + 9;
    cout << (so0 ? res/10 : mx) << ' ' << res;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh