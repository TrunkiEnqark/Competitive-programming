#include <bits/stdc++.h>
using namespace std;

struct trieTree{

    vector<vector<int>> trie;
    vector<vector<int>> cnt;
    int a;
    #define child(x, t) trie[x][t]
    #define sz(x) trie[x][2]
    #define c1(x, i) cnt[x][i]
    #define c0(x, i) (sz(x)-c1(x, i))

    trieTree(){
        trie.push_back(vector<int>(3));
        cnt.push_back(vector<int>(18));
        a = 0;
    }

    bool exist(int key){
        key ^= a;
        for (int k = 0, i = 18; i--; ){
            int t = key >> i & 1;
            k = child(k, t);
            if (!sz(k)) return false;//Warning: sz(0) must be always 0
        }
        return true;
    }

    void push(int key, int d){
        if (d == -1 && !exist(key)) return;
        key ^= a;
        for (int k = 0, i = 18; i--; ){
            int t = key >> i & 1;
            if (!child(k, t)){
                child(k, t) = trie.size();
                trie.push_back(vector<int>(3));
                cnt.push_back(vector<int>(i));
            }
            k = child(k, t);
            sz(k) += d;
            for (int j = i; j--; )
                c1(k, j) += d * (key>>j&1);
        }
    }

    void xorWith(int val){
        a ^= val;
    }

    //sum n smallest elements
    long long sumn(int n){
        long long ans = 0;        
        for (int k = 0, i = 18; i--; ){
            int l = child(k, a >> i & 1), r = child(k, (a >> i & 1) ^ 1);
            if (sz(l) >= n){
                k = l;
                continue;
            }
            for (int j = i; j--; ){//Warning: c0(0), c1(0) must be always 0
                int c = (a >> j & 1) ? c0(l, j) : c1(l, j);
                ans += (long long)c << j;
            }
            n -= sz(l);
            ans += (long long)n << i;
            k = r;
        }
        return ans;
    }
};

int32_t main(int32_t argc,char** argv){
    if (argc>1) freopen(argv[1],"r",stdin);
    if (argc>2) freopen(argv[2],"w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int Q;
    cin >> Q;
    trieTree S;
    while(Q--){
        int t, val;
        cin >> t >> val;
        if (t == 0 || t == 1)
            S.push(val, t ? -1 : 1);
        if (t == 2) S.xorWith(val);
        if (t == 3) cout << S.sumn(val) << '\n';
    }
}
//#include <bits/stdc++.h>
//using namespace std;
//#define rep(i, a, b) for(int i=a; i<=b; i++)
//#define Int long long 
//#define fi cin
//#define fo cout
////	ifstream fi("Xquery.inp");
////	ofstream fo("xquery.out");
//vector <int> a(1, 0);
//
//int find1(int x){
//	int be=1, en=a.size()-1;
//	while (be<=en){
//		int mid=(be+en)/2;
//		if (a[mid]==x) return mid;
//		if (a[mid]>x) en=mid-1; else be=mid+1;
//	}
//	return -1;
//}
////---------------------------------------------------
//int find0(int x){
//	int be=1, en=a.size()-1, pos;
//	while (be<=en){
//		int mid=(be+en)/2;
//		if (a[mid]==x) pos=mid;
//		if (a[mid]>x) en=mid-1; else pos=mid,be=mid+1;
//	}
//	return pos;
//}
////---------------------------------------------------
//int main()
//{ios::sync_with_stdio(false); cin.tie(NULL);
//	int n;
//	fi>>n;
////	for(int i=1; i<=n; i++) a.push_back(i);
////	a.insert(a.begin()+3, 10);
////	rep(i, 1, n+1) fo<<a[i];
//	rep(i, 1, n){
//		int t, x;
//		fi>>t>>x;
//		if (t==0) //them x 
//		{
//			if (a.size()==1) a.push_back(x);
//			else{
//				int tmp=find0(x);
//				if (tmp==a.size()-1) a.push_back(x);
//				else a.insert(a.begin()+tmp+1, x);
//			}
//			//----------------------
////			rep(i, 1, a.size()-1) fo<<a[i]<<' ';fo<<endl;
//		}
//		else if (t==1) //xoa x 
//		{
//			int tmp=find1(x);
//			if (tmp!=-1)
//			a.erase(a.begin()+tmp);
//		}
//		else if (t==2)  //xor  x
//		{
//			rep(i, 1, a.size()-1) a[i]^=x;
//			sort(a.begin()+1, a.end());
//		}
//		else if (t==3) {
//			Int ans=0;
//			rep(i, 1, x) ans+=a[i];
//			fo<<ans<<endl;
//		}
//	}
//}
