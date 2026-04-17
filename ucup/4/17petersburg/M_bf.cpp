#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll a,b,m; cin>>a>>b>>m;
		ll tam=2*m;
		vector<vv> has(tam);
		vv cb(tam,b),ca(tam,a);
		vector<ii> rans;
		fore(i,0,m){
			ll ty,l,r; cin>>ty>>l>>r; l--;
			if(ty==2){
				fore(j,l,r)ca[j]--;
				continue;
			}
			rans.pb({l,r});
			fore(j,l,r)has[j].pb(i);
		}
		m=SZ(rans);
		ll good=0;
		fore(mk,0,1ll<<m){
			vv Cb=cb,Ca=ca;
			fore(i,0,m){
				ll don=mk>>i&1;
				auto [l,r]=rans[i];
				fore(j,l,r)(don?Cb:Ca)[j]--;
			}
			if(!tam){good=1;break;}
			good|=min(*min_element(ALL(Ca)),*min_element(ALL(Cb)))>=0;
			if(good)break;
		}
		if(good)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}