#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout

int main(){
	int n;
	fi>> n;
	int a[n];
	for (int &i:a) fi>>i;
	sort(a, a + n); reverse(a, a + n);
	deque <int> dq;
	for (int i = 0; i < n; ++i) 
		if (i%2) dq.push_front(a[i]); else dq.push_back(a[i]);
	rep(i, 1, n) {
		fo<<dq.front()<<' ';
		dq.pop_front();
		
	}
}
//http://thptchuyen.ntucoder.net/Problem/Details/8499
