#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<vv> ev(n+2);
		fore(i,0,n){
			ll x,y; cin>>x>>y; y++;
			ev[y].pb(x);
		}
		vector<ii> qs(q);
		fore(i,0,q){
			ll x,y; cin>>x>>y; y++;
			qs[i]={x,y};
		}
		priority_queue<ll,vv,greater<ll>> pq;
		vv sum(n+2),tam=sum,mns=sum;
		ll s=0;
		for(ll t=n+1;t>=0;t--){
			for(auto x:ev[t])pq.push(x),s+=x;
			while(SZ(pq)>t){
				ll v=pq.top();
				s-=v; pq.pop();
			}
			ll mn=INF;
			if(SZ(pq))mn=pq.top();
			mns[t]=mn;
			tam[t]=SZ(pq);
			sum[t]=s;
		}
		ll m=SZ(sum);
		vv dej(m),usa(m);
		fore(i,1,SZ(dej)){
			dej[i]=max(dej[i-1],sum[i]);
			ll cur=sum[i];
			if(tam[i]==i)cur-=mns[i];
			usa[i]=max(usa[i-1],cur);
			// cout<<i<<": "<<usa[i]<<" "<<dej[i]<<"\n";
		}
		for(auto [x,y]:qs){
			ll res=max(dej[y],usa[y]+x);
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
