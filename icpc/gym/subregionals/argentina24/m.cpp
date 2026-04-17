#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,celu=b;i<celu;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15;

struct STlazy{
	typedef ii tn; // node type
	typedef ll tl; // lazy type
	// tn unit(ll v){return v;}
	tn NEUT={INF,-1};
	#define CLEAR 0 // cleared lazy node
	tn oper(tn a, tn b){
		return min(a,b);
	}
	void acum(tl &a, tl v){ // accumulate lazy node
		a+=v;
	}
	tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
		a.fst+=v;
		return a;
	}
	vector<tn>st; vector<tl>lazy; ll n;
	STlazy(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(ll k, ll s, ll e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
void upd(ll k, ll s, ll e, ll a, ll b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
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

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv v(n),c(n),pr(n);
	fore(i,0,n)cin>>v[i];
	fore(i,0,n)cin>>c[i];
	fore(i,0,n)cin>>pr[i];
	STlazy cut(n);
	STlazy val(n);
	vector<ii> ini,ini1;
	fore(i,0,n){
		ini.pb({-v[i],i});
		ini1.pb({c[i],i});
	}
	val.init(ini);
	cut.init(ini1);
	ll res=0;
	while(k>0){
		//cout<<res<<endl;
		auto [v,p]=val.query(0,n); v=-v;
		//fore(i,0,n)cout<<val.query(i,i+1).fst<<" ";;cout<<"\n";
		//fore(i,0,n)cout<<cut.query(i,i+1).fst<<" ";;cout<<"\n";
		//cout<<v<<","<<p<<"\n";
		if(v<0)break;
		auto [c,l]=cut.query(0,p+1);
		ll q=min(k,c);
		res+=v*q;
		//cout<<c<<","<<l<<": "<<q<<"\n";
		val.upd(l,n,pr[l]);
		cut.upd(0,p+1,-q);
		cut.upd(l,l+1,INF);
		k-=q;
		//cout<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}