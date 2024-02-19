#include <bits/stdc++.h>

#define NAME "test."
#define all(a) a.begin(), a.end()
#define fo(i,a,b) for(int i=a; i<=b; i++)
#define fod(i,a,b) for(int i=a; i>=b; i--)
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

using namespace std;

const string yno[2] = {"YES", "NO"};

void process()
{
	int n; cin >> n;
	string f[1005], s1, s2, s;
	cin >> s1 >> s2 >> s;
	f[1] = s1, f[2] = s2;
	fo(i,3,n) f[i] = f[i-1] + f[i-2];
	int res = 0, pos = f[n].find(s,0);
	while(pos != -1) {
		++res;
		f[n].erase(pos, 1);
        pos = f[n].find(s,0);
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

//Link: https://vn.spoj.com/problems/LQDFIBO/