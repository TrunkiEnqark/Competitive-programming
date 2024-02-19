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

int l, r, cnt[10];

int calc(int d) {
    int res = 0;
    for(; d > 0; d /= 10) cnt[d%10]++, res++;
    return res;
}

int cal() {
    int res = 0;
    for(int m = 0; m < 10; ++m) {
        if(cnt[m] > 0 && cnt[m] % 4 == 0) res++;
    }
    return res;
}

int diff() {
    int res = 0;
    for(int i = 0; i < 10; ++i) if(cnt[i] > 0) res++;
    return res;
}

bool ok0(int n) {
    return cal() == n;
}

bool ok1(int n) {
    int t = 0;
    for(int m = 0; m < 10; ++m) if(cnt[m] > 0 && cnt[m]%2) t++;
    return (t);
}

bool ok2(int n) {
    int t = 0;
    for(int m = 0; m < 10; ++m) if(cnt[m] > 0 && cnt[m] % 4 == 2) t++;
    return (t);
}

int t() {
    int res = 0;
    for(int i = 0; i < 10; ++i) {
        if(cnt[i] > 0 && (cnt[i] % 2 || cnt[i] % 4 == 2)) res++;
    }
    return res;
}

bool ok(int val) {
    memset(cnt, 0, sizeof cnt);
    int n = calc(val);

    switch (n % 4) {
        case 0 : return ok0(n);
        case 1 : return ((ok1(n) == 1 && n == 1) || (ok1(n) == 1 && cal() + 1 == diff()));
        case 2 : return ((ok2(n) == 1 && n == 2) || (ok2(n) == 1 && cal() + 1 == diff()));;
        case 3 : {
            // cout << ok1(n) << ok2(n) << endl;
            if(n == 3) return (ok1(n) == 1 || ok2(n) == 1); else return (ok1(n) == 1 && ok2(n) == 1 && cal() + 2 == diff())
                                                                     || ((ok1(n) || ok2(n)) && cal() + t() == diff());
        }
    }
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> l >> r;
    // int x;
    // cin >> x;
    // cout << ok(x);
    int res = 0;
    for(int i = l; i <= r; ++i) {
        if(ok(i)) res++;
    }
    cout << res;
    // cout << ok(3111122);

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh