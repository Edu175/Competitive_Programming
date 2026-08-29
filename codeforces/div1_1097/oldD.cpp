#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<vv> has(n);
		fore(i,0,n)cin>>a[i],a[i]--,has[a[i]].pb(i);
		priority_queue<ii> pq; // first,last
		vv l(n),r(n);
		fore(i,0,n)l[i]=r[i]=i;
		vv sig(n,-1);
		ll bad=0;
		fore(x,0,n){
			for(auto y:has[x]){
				pq.push({l[y],y});
				// cerr<<"entra "<<y<<"\n";
			}
			while(SZ(pq)&&(l[pq.top().snd]!=pq.top().fst||sig[pq.top().snd]!=-1))pq.pop();
			if(!SZ(pq)){
				bad=1;
				break;
			}
			auto [le,y]=pq.top(); pq.pop();
			// cerr<<x<<": "<<y<<"\n";
			if(x<n-1&&le==x){bad=1;break;}
			sig[y]=x;
			l[r[x]]=l[y];
			r[l[y]]=r[x];
			if(a[r[x]]<=x){
				pq.push({l[r[x]],r[x]});
				// cerr<<"actu "<<r[x]<<"\n";
			}
		}
		if(bad){
			cout<<"No\n";
		}
		else {
			while(SZ(pq)&&(l[pq.top().snd]!=pq.top().fst||sig[pq.top().snd]!=-1))pq.pop();
			assert(!SZ(pq));
			cout<<"Yes\n";
			ll x=0,cant=0;
			do{
				cout<<x+1<<" ";
				x=sig[x];
				cant++;
			}while(x!=0&&x!=-1&&cant<n);
			cout<<"\n";
			
			assert(cant==n);
		}
	}
	return 0;
}
