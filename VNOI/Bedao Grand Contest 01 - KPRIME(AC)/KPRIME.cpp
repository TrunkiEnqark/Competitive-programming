#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
#define maxn 10000007
//		ifstream fi("input.inp");
//		ofstream fo("output.out");
int c[maxn];
bitset <maxn> d;
void sang(int n){
//	vector <bool> d(n, true);
	d[0]=d[1]=0;
	rep(i, 2, n) d[i]=1;
	rep(i, 2, sqrt(n)){
		if (d[i]){
			int j = i * i;
			while (j <= n){
				d[j]=0, j+=i;
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin>> n>> k;
	sang(n);
	long long ans = 0ll;
//	rep(i, 1, n){
//		int j=1; 
//		for (j; j<=n; ++j)
//			if (c[j] - c[i - 1] >= k){
//				ans+=(n - j + 1); break;
//			}
//		if (j>n) break;
//		}
	for (int l = 1, r = 0, cnt = 0; l <= n; l++){
		while (r <= n && cnt < k) cnt += d[++r];
		if (r > n) break;
		ans += n - r + 1;
		cnt -= d[l];
	}
	fo<<ans;
}

