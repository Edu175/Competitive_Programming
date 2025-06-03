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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv b(n);
		fore(i,0,n)cin>>b[i];
		vv ultz(n,-1);
		vector<array<ll,3>> qs(q);
		vv a=b;
		fore(i,0,q){
			ll x,y,z; cin>>x>>y>>z; x--,y--,z--;
			qs[i]={x,y,z};
			ultz[z]=i;
			a[z]=-1;
		}
		vv A=a;
		vv vis(n);
		auto subir=[&](ll i, ll v){
			if(!vis[i])A[i]=max(A[i],v);
		};
		fore(i,0,q){
			auto [x,y,z]=qs[i];
			if(ultz[z]!=i)continue;
			imp(a)
			a[x]=max(a[x],b[z]);
			a[y]=max(a[y],b[z]);
			
			a[x]=max(a[x],b[z]);
			a[y]=max(a[y],b[z]);
			
			a[z]=b[z];
		}
		// si existe es a
		vv c=a;
		for(auto [x,y,z]:qs){
			c[z]=min(c[x],c[y]);
		}
		cout<<"final\n";
		imp(a)
		imp(c)
		if(c!=b)cout<<"-1\n";
		else {
			imp(a)
		}
		
	}
	return 0;
}
