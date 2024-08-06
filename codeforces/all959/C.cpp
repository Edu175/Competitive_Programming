#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		map<ll,ll>c;
		ll s=0;
		priority_queue<ll>pq;
		ll res=0;
		fore(i,0,n){
			if(!c[-s])pq.push(-s);
			c[-s]++;
			s+=a[i];
			ll q=0;
			while(SZ(pq)&&pq.top()+s>k){
				q+=c[pq.top()];
				c[pq.top()]=0;
				pq.pop();
			}
			if(!c[-s])pq.push(-s);
			c[-s]+=q;
			
			// cout<<i<<": ";
			// for(auto i:c)if(i.snd){
			// 	cout<<i.fst+s<<","<<i.snd<<" ";
			// }
			// cout<<"\n";
			res+=i+1-c[-s];
		}
		cout<<res<<"\n";
	}
	return 0;
}
