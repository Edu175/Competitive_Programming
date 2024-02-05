#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MOD=998244353;

ll rnd(){
	return (ll(rand())<<45)^(ll(rand())<<30)^(ll(rand())<<15)^ll(rand());
}

int main(){FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(2*n);
		fore(i,0,2*n)cin>>a[i],a[i]--;
		vector<ll> v(n),h(2*n+1,0);
		fore(i,0,n)v[i]=rnd();
		map<ll,vector<ll>>mp;
		vector<ll>pos={0};
		mp[h[0]].pb(0);
		fore(i,1,2*n+1){
			h[i]=h[i-1]^v[a[i-1]];
			if(!h[i])pos.pb(i);
			mp[h[i]].pb(i);
		}
		ll res=0,num=1;
		fore(i,0,SZ(pos)-1){
			ll s=pos[i],e=pos[i+1];
			ll sz=(e-s)/2;
			fore(j,s+1,e){
				auto lwb=lower_bound(ALL(mp[h[j]]),j+1);
				if(lwb==mp[h[j]].end())continue;
				ll k=*lwb;
				if(k<e)sz-=(k-j)/2,j=k-1;
			}
			num=num*2*sz%MOD;
			res++;
		}
		cout<<res<<" "<<num<<"\n";
	}
	return 0;
}
