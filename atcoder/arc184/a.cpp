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
ll ask(ll x, ll y){
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vv god;
	vv c[2];
	ll p=0,s=0;
	while(p<n){
		s=p;
		c[0].pb(p); p++;
		while(p<n&&max(SZ(c[0]),SZ(c[1]))<m-SZ(god)+1){
			c[ask(s,p)].pb(p);
			p++;
		}
		ll w=SZ(c[1])<SZ(c[0]);
		if(p==n){
			w=SZ(c[1])==m-SZ(god);
		}
		for(auto i:c[w])god.pb(i);
		c[0].clear();
		c[1].clear();
	}
	cout<<"! "; for(auto i:god)cout<<i+1<<" ";;cout<<endl;
	return 0;
}
