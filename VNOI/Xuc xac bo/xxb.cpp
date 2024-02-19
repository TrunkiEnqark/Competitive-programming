#include <bits/stdc++.h>
#define fo(i,a) for(int i = 1; i <= a; ++i)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int s1, s2, s3; cin >> s1 >> s2 >> s3;
	int s = s1 + s2 + s3;
	int dem[s + 1]; memset(dem, 0, sizeof(dem));
	fo(x,s1) fo(y,s2) fo(z,s3) ++dem[x+y+z];
	int ma = INT_MIN;
	fo(i,s) ma = max(ma, dem[i]);
	fo(i,s) if(dem[i] == ma) { cout << i; return 0; }
}