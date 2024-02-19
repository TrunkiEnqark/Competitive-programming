#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define rep(i, a) 	for(int i = 0; i < a; ++i)
#define all(a) a.begin(), a.end()

using namespace std;

const int MAX = 100001;

struct pack {
	int d1, d2, index;

	bool operator == (pack &x) {
		return ( d1 == x.d1 && d2 == x.d2 );
	}

	bool operator < (pack &x) {
		return ( d1 < x.d1 || (d1 == x.d1 && d2 < x.d2) );
	}
};

int n;
vector<pack> a;
vector<int> ans;
int bit[300005];

void add(int x) {
	for(; x <= MAX; x += x&(-x)) ++bit[x]; 
}

int sum(int x) {
	int res = 0;
	for(; x > 0; x -= x&(-x)) res += bit[x];
	return res; 
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	a.resize(n);
	rep(i, n) {
		cin >> a[i].d1 >> a[i].d2;
		++a[i].d1, ++a[i].d2;
		a[i].index = i;
	}
	ans.resize(n);
	sort(all(a));

	rep(i, n) {
		if(i != 0 && a[i] == a[i-1]) {
			ans[a[i].index] = ans[a[i-1].index];
		} else ans[a[i].index] = sum(a[i].d2);
		add(a[i].d2);
	}

	rep(i, n) cout << ans[i] << '\n';

	return 0;
}