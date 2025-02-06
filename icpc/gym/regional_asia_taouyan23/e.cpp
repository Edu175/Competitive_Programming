#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<endl;}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e10;

typedef ll tn;
typedef ll tl;
#define NEUT 0
#define CLEAR 0
// tn unit(ll v){
// 	ii a={0,0};
// 	if(v==1)a.fst++;
// 	if(v==0)a.snd++;
// 	return a;
// }
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){
	a=max(a,v);
}
tn calc(tn a, tl v){
	a=max(a,v);
	return a;
}
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(ll k, ll s, ll e, vector<tn> &a){
		if(e-s==1)st[k]=a[s];
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a);
			init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);
		upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,ex; cin>>n>>ex;
		vv pos(n),w(n);
		vector<pair<ii,ii>>a; // {start x coord, i} {l,r}
		ll ori=0,mn=INF,mx=0,mnl=INF;
		vv ys;
		fore(i,0,n){
			ll l,d,r,u; cin>>l>>d>>r>>u;
			ys.pb(d);
			ys.pb(r);
			w[i]=r-l;
			a.pb({{l,i},{d,u}});
			ori=max(ori,r);
			mn=min(mn,d);
			mnl=min(mnl,l);
			mx=max(mx,u);
		}
		ori-=mnl;
		sort(ALL(ys));
		auto _ys=ys;
		ys.clear();
		for(auto i:_ys)if(!SZ(ys)||i!=ys.back())ys.pb(i);
		auto get_idx=[&](ll v){return lower_bound(ALL(ys),v)-ys.begin();};
		sort(ALL(a));
		STree st(SZ(ys));
		ll ans=0;
		for(auto [fst,snd]:a){
			auto [skjdf,i]=fst;
			auto [l,r]=snd;
			l=get_idx(l);
			r=get_idx(r);
			pos[i]=st.query(l,r)+ex+w[i];
			st.upd(l,r,pos[i]);
			ans=max(ans,pos[i]);
		}
		ans-=ex;
		// cout<<mnl<<" mnl\n";
		// cout<<ori<<" "<<ans<<"\n";
		// cout<<mn<<" "<<mx<<"\n";
		// imp(pos)
		ll dif=ori-ans;
		ll res=dif*(mx-mn);
		// cerr<<res<<" pingo\n";
		res=max(res,0ll);
		cout<<res<<"\n";
	}
	return 0;
}


/*
input:
1


6 4
2 5 4 11
2 14 6 17
7 10 10 16
9 4 16 7
11 11 16 14
18 4 20 18


output:
2 mnl
18 26
4 18
0 0 8 6 15 24 
-112

*/