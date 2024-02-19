#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define fi cin
#define fo cout
//	ifstream fi("couple.inp");
//	ofstream fo("couple.out");
typedef vector <int> vi;
int n, m, res=INT_MAX, k;
vi a; vi c;
vi b; vi d;
vector <bool> fa, fb;
int find1(int x, vi a){ //tim nho hon
	int be=0, en=a.size()-1, ans=INT_MAX, tmp;
	while (be<=en){
		int mid=(be+en)/2;
		if (a[mid]==x) {a.erase(a.begin()+mid); return 0; }
		if (abs(a[mid]-x)<ans) ans=abs(a[mid]-x), tmp=mid;
		if (abs(a[mid+1]-x)<abs(a[mid-1]-x)) be=mid+1; else en=mid-1;
	}
	a.erase(a.begin()+tmp);return ans;
}
void tinh(){
	int ans=0;
	rep(i, 0, k) ans=max(abs(a[c[i]]-b[d[i]]), ans);
	res=min(ans, res);
//	rep(i, 0, k) fo<<c[i]<<' ';
//	rep(i, 0, k) fo<<d[i]<<' ';
//	fo<<endl;
}
void tim1(int i){
	rep(j, 0, m){
		if (fb[j]){
			d[i]=j; fb[j]=false;
			if (i==k) tinh();
			else tim1(i+1);
			fb[j]=true;
		}
	}
}


void tinh1(){
		int ans=0;
		rep(i, 0, b.size()-1) ans=max(find1(b[i], a), ans);
		res=ans;
}
void tim(int i){
	rep(j, 0, n){
		if (fa[j]){
			c[i]=j; fa[j]=false;
			if (i==k) tinh1();
			else tim(i+1);
			fa[j]=true;
		}
	}
}
void doi(){
	vi t=a;
	a=b;
	b=t;
}
int main(){
	fi>>n>>m>>k;
	a.resize(n);c.resize(n);fa.resize(n, true);//male
	b.resize(m);d.resize(m);fb.resize(m, true);//female
	n--; m--;k--;
	rep(i, 0, n) fi>>a[i];
	rep(i, 0, m) fi>>b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (b.size()>a.size()) doi();
	if (k==0) {
		int ans=INT_MAX;
		rep(i, 0, b.size()-1) ans=min(find1(b[i], a), ans);
		res=ans;
	}else  tim(0);
	fo<<res;
}
