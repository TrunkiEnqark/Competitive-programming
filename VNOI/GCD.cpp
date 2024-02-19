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
const int N = 55;

int n, a[N], p[N], v[N];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool ok(int x) {
    for(int i = 1; i <= n; ++i) if(__gcd(a[i], x) <= 1) return false;
    return true;
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    int len = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        int tmp = a[i];
        for(auto j : prime) {
            while(tmp % j == 0) {
                p[j]++;
                if(p[j] == 1) v[len++] = j;
                tmp /= j;
            }
        }
    }

    int res = 1e9;
    for(int msk = 1; msk < (1 << len); ++msk) {
        int x = 1;
        for(int i = 0; i < len; ++i) {
            if(((msk >> i) & 1)) x *= v[i];
        }

        if(ok(x)) res = min(res, x);
    }

    cout << (res);

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh