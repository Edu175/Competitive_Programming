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
		ll n,k; cin>>n>>k;
		vv a(n);
		vv pos[n];
		fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]].pb(i);
		vector<ii> h[n];
		fore(i,0,k){
			auto &v=pos[i];
			fore(i,0,SZ(v)-1){
				h[(v[i+1]+v[i]+1)/2].pb({v[i],v[i+1]});
			}
		}
		ll fij=0;
		fore(i,0,k)fij+=abs(i-k/2);
		ll l=0,r=k,sl=0,sr=0;
		vv vis(k);
		fore(i,0,n)if(!vis[a[i]])sr+=i,vis[a[i]]=1;
		ll res=n*n+5;
		fore(i,0,n){
			ll resi=i*l-sl+sr-i*r;
			// cout<<i<<": "<<l<<","<<sl<<" "<<r<<","<<sr<<": "<<resi<<"\n";
			res=min(res,resi);
			if(i<n-1){ // muevo el m
				// cout<<"muevo a "<<i+1<<"\n";
				r--,l++; sr-=i,sl+=i;
				for(auto [s,e]:h[i+1]){
					l--,r++;
					sl-=s,sr+=e;
					// cout<<s<<","<<e<<"\n";
				}
			}
		}
		// cout<<fij<<"\n";
		cout<<res-fij<<"\n";
	}
	return 0;
}
