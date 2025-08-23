#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef ii tn; // node type
typedef ll tl; // lazy type
// tn unit(ll v){return v;}
tn NEUT={1e8,0};
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	if(a.fst>b.fst)swap(a,b);
	if(a.fst==b.fst)a.snd+=b.snd;
	return a;
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a.fst+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){
		//fore(i,0,n)upd(i,unit(0));
	}
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
const ll MAXN=1e4+5; 
pair<ii,ii> a[MAXN];
ll n,k;
ii s,e;
bool can(ll ra){
	// cout<<"\n\n";
	vector<pair<ii,ll>>h[e.fst+5];
	fore(i,0,n){
		ii l=a[i].fst;
		l.fst-=ra,l.snd-=ra;
		ii r=a[i].snd;
		r.fst+=ra,r.snd+=ra;
		l.fst=max(l.fst,s.fst);
		l.snd=max(l.snd,s.snd);
		r.fst=min(r.fst,e.fst);
		r.snd=min(r.snd,e.snd);
		h[l.fst].pb({{l.snd,r.snd},1});
		h[r.fst].pb({{l.snd,r.snd},-1});
		// cout<<i<<": "<<l.fst<<","<<l.snd<<" "<<r.fst<<","<<r.snd<<"\n";
	}
	ll q=0,m=e.snd+5; // m=height
	STree st(m);
	vector<ii>ini(m);
	fore(i,0,m)ini[i]={0,1};
	st.init(ini);
	fore(t,0,e.fst+3){
		for(auto [ran,v]:h[t]){
			auto [l,r]=ran;
			st.upd(l,r,v);
		}
		auto rq=st.query(0,m);
		ll z=rq.fst==0?rq.snd:0;
		q+=m-z;
	}
	// cout<<ra<<": "<<q<<"\n";
	return q>=k;
}

int main(){
	FIN
	cin>>n;
	fore(i,0,n){
		cin>>a[i].fst.fst>>a[i].fst.snd;
		cin>>a[i].snd.fst>>a[i].snd.snd;
		if(a[i].fst>a[i].snd)swap(a[i].fst,a[i].snd);
	}
	ll p; cin>>p;
	cin>>s.fst>>s.snd;
	cin>>e.fst>>e.snd;
	ll area=(e.fst-s.fst)*(e.snd-s.snd);
	k=(area*p+99)/100;
	ll l=0,r=1e5+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
} 