#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a;i<=b; i++)	
#define pb push_back 
#define fi cin
#define fo cout
//	ifstream fi("pvh03.inp");
//	ofstream fo("pvh03.out");
typedef vector <int> vi;	
	int n;
	vector <int> a;
	priority_queue <int,vector<int>,greater<int> > tree1;
	priority_queue <int,vector<int>,greater<int> > tree2;
int tinh1(int t){
	if (a[t]==0) a[t]=1; else a[t]=0;
	int tmp=a[t];
	rep(i, 1, n) if (a[i]==tmp){
		if (a[t]==0) a[t]=1; else a[t]=0;
		return i+1;
	}
}
//-----------------------------------------------------------------
void tinh(int t){
	if (a[t]==0) a[t]=1; else a[t]=0;
	int tmp=a[t];
	if (tmp==0) {
		tree1.push(t); int ans=tree1.top();
		fo<<ans+1<<' ';tree1.pop();
		tree2.push(ans);a[ans]=1;
		//rep(i, 0, n) fo<<a[i];fo<<endl;
	}
	else {
		tree2.push(t); int ans=tree2.top();
		fo<<ans+1<<' ';tree2.pop();
		tree1.push(ans);a[ans]=1;
	}
}
//----------------------------------------------------------------
void showpq(
    priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>,
                                greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
//------------------------------------------------------------
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p;
	fi>>n>>p;
	n--;
	rep(i, 0, n)
	{
		char t;
		fi>>t;
		if (t=='(') a.pb(0);	else  a.pb(1);
		if (i!=0) {if (t=='(')tree1.push(i); else tree2.push(i);}
	}
	//rep(i, 0, n) fo<<a[i];
	rep(i, 1, p){
		int t;
		fi>>t;
		if (t==1 || t==n+1) fo<<t<<' ';
		//else if (t==n+1) fo<<n+1<<' ';
//		else fo<<tinh1(t-1)<<' ';
		else tinh(t-1);
	}	
}
