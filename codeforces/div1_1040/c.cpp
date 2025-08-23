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

ll ask(vv v){
	if(!SZ(v))return 0;
	assert(SZ(v)<=1000);
	cout<<"? "<<SZ(v)<<" ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	return ret;
}

vv rang(ll s, ll e){
	vv v;
	fore(i,s,e)v.pb(i);
	return v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll l=-1,r=n;
		while(r-l>1){
			ll m=(l+r)/2;
			if(ask(rang(0,m+1)))r=m;
			else l=m;
		}
		ll p=r;
		if(p==n){
			assert(ask(rang(0,n))==0);
			// invalid:
			// )))))
			// (((((
			
			// valid:	
			// )))(( 1
			ll l=-1,r=n;
			while(r-l>1){
				ll m=(l+r)/2;
				if(ask({n-1,m}))l=m;
				else r=m;
			}
			cout<<"! ";
			fore(i,0,r)cout<<")";
			fore(i,r,n)cout<<"(";
			cout<<endl;
			continue;
		}
		assert(p>0&&ask({p-1,p}));
		p--;
		string par="()";
		ll k=8;
		auto det=[&](vv v){
			assert(SZ(v));
			ll sz=SZ(v);
			while(SZ(v)<8)v.pb(v.back());
			vv s;
			fore(i,0,k){
				fore(_,0,(1ll<<i)+1)s.pb(p);
				fore(_,0,1ll<<i)s.pb(v[i]);
			}
			ll mk=ask(s);
			string ret;
			fore(i,0,k)ret.pb(par[mk>>i&1]);
			while(SZ(ret)>sz)ret.pop_back();
			return ret;
		};
		
		string ret;
		for(ll i=0;i<n;i+=k){
			ll e=min(i+k,n);
			auto s=det(rang(i,e));
			ret+=s;
		}
		cout<<"! "<<ret<<endl;
	}
	return 0;
}
