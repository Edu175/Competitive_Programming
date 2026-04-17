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
	int t = 0;
	while(!pq.empty()) {
		vi c;
		forn(i,K) {
			if(pq.empty()) return t;
			c.push_back(pq.top());
			pq.pop();
		}
		forn(i,K) {
			if(c[i]!=c.back()) {
				pq.push(c[i]-c.back());
			}
		}
		t+=c.back();
	}
	return t;
}
