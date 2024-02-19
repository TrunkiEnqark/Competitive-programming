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
const int N = 1e6 + 6;

int n, a[N];

bool ok() {
    for(int i = 2; i <= n; ++i) if(abs(a[i] - a[i - 1]) == 1) return false;
    return true; 
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    
    if(n == 1) {
        cout << 1;
        return 0;
    }
    
    if(n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }

    for(int i = 2; i <= n; i += 2) cout << i << ' ';
    for(int i = 1; i <= n; i += 2) cout << i << ' ';

    // for(int i = 1; i <= n; ++i) a[i] = i;

    // do {
    //     if(ok()) {
    //         for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    //         // cout << endl;
    //         return 0;
    //     }
    // } while(next_permutation(a + 1, a + n + 1));

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh
// https://cses.fi/problemset/task/1070