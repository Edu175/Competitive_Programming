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
const ll INF=1e17;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		ll fij=0;
		fore(i,0,n)cin>>a[i]>>b[i],fij+=a[i];
		// cerr<<fij<<" fij\n";
		auto get=[&](vv per){
			ll suma=0,sumb=0;
			ll cost=0;
			for(auto i:per){
				ll ex=0;
				if(suma+a[i]>sumb)ex=suma+a[i]-sumb;
				cost+=ex;
				suma+=a[i]-ex,sumb+=b[i];
			}
			return fij+cost;
		};
		ll res=INF; vector<vv> anss;
		auto proba=[&](vv per){
			//  imp(per)
			ll ret=get(per);
			// cout<<"= "<<ret<<"\n";
			if(ret<res)res=ret,anss={per};
			else if(ret==res)anss.pb(per);
			// auto ult=per.back(); per.pop_back();
			// reverse(ALL(per)); per.pb(ult);
			// imp(per)
			// res=min(res,get(per));
		};
		vv per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){
			return ii(b[i]-a[i],b[i])>ii(b[j]-a[j],b[j]);});
		// cout<<"my: "; imp(per);
		vv pos(n);
		fore(i,0,n)pos[per[i]]=i;
		ll suma=0,sumb=0;
		fore(i,0,n)suma+=a[i],sumb+=b[i];
		ll p=-1;
		// vv ps;
		vv can(n);
		fore(i,0,n){
			can[i]=sumb-b[i]>=suma;
			if(can[i]){
				// ps.pb(i);
				if(p==-1)p=i;
				else if(pos[i]>pos[p])p=i;
			}
		}
		//imp(can)
		if(p==-1){
			cout<<"-1\n";
			continue;
		}
		// imp(ps)
		// per.erase(per.begin()+pos[p]);
		//per.pb(p);
		sort(ALL(per));
		do{
		//	per.pb(p);
			if(can[per.back()])proba(per);
		 //	per.pop_back();
		 }while(next_permutation(ALL(per)));
		
		for(auto ans:anss){
			for(auto i:ans)cerr<<i<<" ";;cerr<<"\n";
		}
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}