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
	ll n; cin>>n;
	vv a(n),b=a,c=a;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	vector<ii> sc;
	fore(i,0,n){
		cin>>c[i];
		if(a[i]&&b[i])sc.pb({c[i],i});
	}
	sort(ALL(sc));
	reverse(ALL(sc));
	auto cost=[&](ll k){
		vv apa(n);
		fore(i,0,k)apa[sc[i].snd]=1;
		vv ops;
		ll s=0;
		fore(i,0,n){
			if(a[i])s+=c[i];
			if(apa[i]){
				assert(a[i]==1&&b[i]==1);
				ops.pb(-c[i]);
				ops.pb(c[i]);
			}
			else {
				if(a[i]&&!b[i])ops.pb(-c[i]);
				if(!a[i]&&b[i])ops.pb(c[i]);
			}
		}
		sort(ALL(ops));
		ll res=0;
		for(auto v:ops){
			s+=v;
			res+=s;
		}
		return res;
	};
	auto baja=[&](ll k){return cost(k)>cost(k+1);};
	ll l=-1,r=SZ(sc);
	while(r-l>1){
		ll m=(l+r);
		if(baja(m))l=m;
		else r=m;
	}
	ll res=cost(r);
	cout<<res<<"\n";
	return 0;
}
