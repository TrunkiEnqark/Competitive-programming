#include <bits/stdc++.h>

#define ii pair<int, int>
#define iiii pair<ii, ii>
#define X first
#define Y second
#define pb push_back
#define all(a) a.begin(), a.end()
#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define rep(i,a)  for(int i = 0; i < a; ++i)

using namespace std;

const int open = 1, close = -1, N = 33333;

vector<iiii> e;
ii it[N*8];
int n, res = 0;

void enter() {
	cin >> n;
	for(int x1, x2, y1, y2, i = 1; i <= n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		e.pb(iiii(ii(x1, open), ii(y1, y2)));
		e.pb(iiii(ii(x2, close), ii(y1, y2)));
	}
	sort(all(e));
}

void upd(int k, int l, int r, int i, int j, int v) {
	if(r <= i || j <= l) return;
	if(i <= l && r <= j) it[k].X += v;
	else {
		int mid = (l + r) >> 1;
		upd(k << 1,       l, mid, i, j, v);
		upd((k << 1) | 1, mid, r, i, j, v);
	}

	if(it[k].X == 0) it[k].Y = it[k<<1].Y + it[(k<<1)|1].Y; else it[k].Y = r - l;
}

void SweepLine() {
	rep(i,e.size()-1) {
		int y1 = e[i].Y.X, y2 = e[i].Y.Y;
		int v = e[i].X.Y;
		upd(1, 0, N, y1, y2, v);
		int len = e[i+1].X.X - e[i].X.X;
		int d = it[1].Y;
		res += len*d; 
		// cout << len << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	enter();
	SweepLine();
	cout << res;

	return 0;
}