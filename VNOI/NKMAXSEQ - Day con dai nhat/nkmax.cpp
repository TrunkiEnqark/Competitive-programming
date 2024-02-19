#include <bits/stdc++.h>
#define NAME "nkmax."
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define red(i,a,b) for(int i=a; i>=b; i--)
#define fi first
#define se second
#define ll long long
#define endl "\n"
#define ii pair<int, int>
#define pll pair<long long, long long>
#define i64 int64_t
#define INF 1e9
#define maxN 50001

using namespace std;

const string yno[2] = {"YES", "NO"};

int n, p, a[maxN], s[maxN], kq = -1;

void process() {
	s[0] = 0;
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			if(s[j] - s[i-1] >= p) 
				if(kq < j-i+1) kq = j-i+1;
	
	cout<<kq;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
//    freopen(NAME"inp", "r", stdin);
//    freopen(NAME"out", "w", stdout);
    cin>>n>>p;
    rep(i,1,n) cin>>a[i];
    process();
    return 0;
}
