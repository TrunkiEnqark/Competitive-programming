#include <bits/stdc++.h>

#define NAME "TEST."
#define all(a) a.begin(), a.end()
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FOD(i,a,b) for(int i=a; i>=b; i--)
#define fi first
#define se second
#define ll long long
#define endl "\n"
#define ii pair<int, int>
#define pll pair<long long, long long>
#define i64 int64_t
#define print_1(a) cout << a << "\n"
#define print_2(a,b) cout << a << " " << b << "\n"
#define print_3(a,b,c) cout << a << " " << b << " " << c << "\n";
#define print_4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << "\n"
#define multi_print(a, i, l, n) for(int i = l; i <= n; i++) {cout << a[i] << " "} cout << "\n";
#define ghost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define I freopen(NAME"inp", "r", stdin)
#define O freopen(NAME"out", "w", stdout)
#define reset(x) memset(x, 0, sizeof(x))
#define reset_val(x, i) memset(x, i, sizeof(x))
#define reset_true(x) memset(x, true, sizeof(x))
#define reset_false(x) memset(x, false, sizeof(x))
#define min_3(a,b,c) min(a, min(b, c))
#define min_4(a,b,c,d) min(a, min(b, min(c, d)))
#define max_3(a,b,c) max(a, max(b, c))
#define max_4(a,b,c,d) max(a, max(b, max(c, d)))
#define INF 1e18
#define pb push_back
#define time cout << "\nTime: " << clock()/(double)1000 << " sec"
#define N 20001
using namespace std;

const string yno[2] = {"YES", "NO"};

int n, a[N];

void process()
{
	cin >> n;
	FOR(i,0,n-1) cin >> a[i];
	sort(a, a+n);
	int lo = 0, hi = n-1, res = 0;
	while(lo != hi) {
		if(a[lo] + 1 <= hi - lo) {
			int l = a[lo]; res += a[lo];
			for(int i = hi- a[lo]; i <= hi; ++i) l += a[i];
			hi -= a[lo]; a[hi] = l; ++lo;
		} else {
			res += hi - lo;
			hi = lo;
		}
	} 
	cout << res;
}

int main()
{
    ghost;
    //I; //O;
    process();
    //time;
    return 0;
}
