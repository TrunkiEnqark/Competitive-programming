//--Coder_Bot--//
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;

#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define maxn 100005
#define maxm 1000006
#define name "Bot"
int MOD = 1e9+7;
int INF = 1e9+7;

//declare
long long n, f[maxn];
int ans;
//Coding from here;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    int i = 2;
    int tmp = f[2];
    while(tmp <= n)
        f[++i] = f[i-1] + f[i-2], tmp = f[i];
    --i;
    while(n){
        if(f[i] <= n){
            ans++;
            n-=f[i];
        }
        i--;
    }
    cout << ans;
}
//--Code_Of_Life--// abba