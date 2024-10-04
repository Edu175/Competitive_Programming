#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n;
void prin(priority_queue<ll>pq){
	while(SZ(pq))cout<<pq.top()<<" ",pq.pop();
	cout<<endl;
}
ll solve(vector<ll>a, ll s, ll d){
	if(s==n-1)return -1;
	ll res=0;
	fore(l,0,s+1){
		priority_queue<ll>pq;
		ll sum=0;
		fore(i,l,s)pq.push(-a[i]),sum+=a[i];
		fore(r,s,n){
			pq.push(-a[r]); sum+=a[r];
			ll di=d-(s-l+r-l);
			if(di<0)break;
			// cout<<sum<<" "<<di<<": ";
			// prin(pq);
			while(SZ(pq)>di)sum+=pq.top(),pq.pop();
			res=max(res,sum);
		}
	}
	return res;
}

long long findMaxAttraction(int N, int s, int d, int A[]) {
	n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i];
	auto ra=a;
	reverse(ALL(ra));
	return max(solve(a,s,d),solve(ra,n-1-s,d));
}
