#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
ll bombones(int K, vi &x) {
	priority_queue<int> pq;
	forn(i,SIZE(x)) pq.push(x[i]);
	ll t = 0;
	while(!pq.empty()) {
		vi c;
		forn(i,K) {
			if(pq.empty()) return t;
			c.push_back(pq.top());
			pq.pop();
		}
		int sig = pq.empty() ? 0 : pq.top();
		int d = max(c.back() - sig, 1);
		forn(i,K) {
			if(c[i]!=d) {
				pq.push(c[i]-d);
			}
		}
		t+=d;
	}
	return t;
}
