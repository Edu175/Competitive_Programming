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
const ll K=19;

struct BL{
	ll F[K][1<<K]; ii V[K][1<<K];
	
	ii merge(ii a, ii b){
		ii c={a.fst*b.snd+b.fst,a.snd*b.snd};
		return c;
	}
	ll in(ll i, ll l, ll r){return l<=i&&i<r;}
	BL(){}
	BL(vv to, vv a, ll sig){ // aca multiplico el sig
		ll n=SZ(a);
		fore(i,0,n){
			F[0][i]=to[i];
			V[0][i]={sig*a[i],sig};
		}
		fore(k,1,K)fore(x,0,n){
			ll fa=F[k-1][x];
			if(!in(fa,0,n))F[k][x]=fa,V[k][x]=V[k-1][x];
			else {
				F[k][x]=F[k-1][fa];
				V[k][x]=merge(V[k-1][x],V[k-1][fa]);
			}
		}
	}
	ii query(ll x, ll l, ll r){
		ii val={0,1};
		for(ll k=K-1;k>=0;k--){
			ll fa=F[k][x];
			if(in(fa,l,r)){
				val=merge(val,V[k][x]);
				x=fa;
			}
		}
		return {val.fst,x};
	}
};

int main(){FIN;
	ll m,n,q; cin>>m>>n>>q;
	map<string,ii> mp;
	fore(i,0,m){
		ll a,v; string s; cin>>a>>v>>s;
		mp[s]={a,v};
	}
	vv a(n),v(n);
	fore(i,0,n){
		string s; cin>>s;
		auto [ai,vi]=mp[s];
		a[i]=ai,v[i]=vi;
	}
	vector<ii> sd;
	fore(i,0,n)sd.pb({a[i],-i});
	sort(ALL(sd)); reverse(ALL(sd));
	
	vv le(n),ri(n),to(n);
	set<ll> st={-1,n};
	for(auto& [asd,i]:sd){
		i=-i;
		auto it=st.insert(i).fst;
		le[i]=*prev(it); ri[i]=*next(it);
		auto &t=to[i];
		t=-1;
		if(le[i]!=-1)t=le[i];
		if(ri[i]!=n&&(t==-1||a[ri[i]]<=a[t]))t=ri[i];
	}
	vv dpl(n),dpr(n);
	reverse(ALL(sd));
	for(auto [asd,i]:sd){
		ll cur=dpl[i]+v[i]+dpr[i];
		// cout<<i<<": "<<to[i]<<"\n";
		if(to[i]!=-1){
			ll fg=i<to[i];
			(fg?dpl:dpr)[to[i]]=cur*(fg?-1:1);
		}
	}
	
	// imp(a)
	// imp(v)
	// fore(i,0,n){
	// 	cout<<i<<": "<<le[i]<<","<<ri[i]<<" "<<dpl[i]<<","<<dpr[i]<<"\n";
	// }
	
	vv vals(n);
	fore(i,0,n)vals[i]=dpr[i]+v[i];
	BL right(ri,vals,-1);
	
	fore(i,0,n)vals[i]=dpl[i]+v[i];
	BL left(le,vals,1);
	
	while(q--){
		ll l,r; cin>>l>>r; l--;
		auto [val1,x1]=right.query(l,l,r);
		auto [val2,x2]=left.query(r-1,l,r);
		assert(x1==x2);
		// cout<<x1<<" "<<x2<<"\n";
		// cout<<val1<<" "<<v[x1]<<" "<<val2<<"\n";
		ll res=val1+v[x1]+val2;
		cout<<res<<"\n";
	}
	return 0;
}
