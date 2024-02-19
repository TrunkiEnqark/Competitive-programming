#include <bits/stdc++.h>

using namespace std;

int dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = {1 ,  2, 2, 1, -1, -2, -2, -1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; int n, k;
	cin >> n >> k >> s;
	int x = 0, y = 0, maxx = 0, maxy = 0, minx = 0, miny = 0;
	for(int i = 0; i < k; ++i) {
		maxx = max(maxx, x += dx[s[i] - '1']);
		minx = min(minx, x);
		maxy = max(maxy, y += dy[s[i] - '1']);
		miny = min(miny, y);
	}
	cout << (n - maxx + minx) * (n - maxy + miny);
}