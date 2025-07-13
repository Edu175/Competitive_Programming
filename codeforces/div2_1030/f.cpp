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

map<vv,ll>mp;
auto hsh=[](vv a){ // hash vector
	if(mp.count(a))return mp[a];
	ll sz=SZ(mp);
	return mp[a]=sz;
};
vv get(vv a, ll m){ // 0 valued
	ll n=SZ(a);
	vv h(n);
	vector<vv> pos(m+1);
	fore(i,0,n)pos[a[i]].pb(i);
	for(ll i=m-1;i>=0;i--){
		vector<ii>v;
		fore(w,0,2)for(auto p:pos[i+w])v.pb({p,w});
		sort(ALL(v));
		vv tmp;
		fore(j,0,2*SZ(v)){
			auto [p,w]=v[j%SZ(v)];
			if(w==0)h[p]=hsh(tmp),tmp.clear();
			else tmp.pb(h[p]);
		}
	}
	vv ret;
	for(auto p:pos[0])ret.pb(h[p]);
	return ret;
}
bool eq(vv a, vv b){ // are they rotationally equal?
	ll n=SZ(a);
	if(SZ(b)!=n)return 0;
	#define bint __int128
	const ll MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	auto add=[&](ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;};
	auto sub=[&](ll a, ll b){a-=b;if(a<0)a+=MOD;return a;};
	auto mul=[&](bint a, bint b){return a*b%MOD;};
	assert(mul(P,PI)==1);
	ll ha=0,p=1;
	fore(i,0,n)ha=add(ha,mul(a[i],p)),p=mul(p,P),assert(a[i]<P);
	ll hb=0;p=1;
	fore(i,0,n)hb=add(hb,mul(b[i],p)),p=mul(p,P),assert(b[i]<P);
	fore(i,0,n){
		if(ha==hb)return 1;
		hb=sub(hb,b[i]);
		hb=add(hb,mul(b[i],p)); // p es P^n
		hb=mul(hb,PI);
	}
	return 0;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mp.clear(); // optional
		ll n,m; cin>>n>>m;
		auto vec=[&](){
			vv a(n);
			fore(i,0,n)cin>>a[i],a[i]--;
			return get(a,m);
		};
		auto u=vec();
		auto v=vec();
		if(eq(u,v))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
