#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll INF=1e9;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos) { // a[pos] ++
		for (; pos < SZ(s); pos |= pos + 1) s[pos] ++;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};
struct FT2 {
	vector<vv> ys; vector<FT> ft;
	ll tot=0;
	ll ri=0,rj=0,n;
	FT2(int limx, int ri, int rj) : ys(limx),ri(ri),rj(rj),n(limx){}
	void revi(auto &i){if(ri)i=n-1-i;}
	void revj(auto &j){if(rj)j=n-1-j;}

	void fakeUpdate(int x, int y) {
		revi(x);revj(y);
		for (; x < SZ(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (auto& v : ys) sort(ALL(v)), ft.emplace_back(SZ(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(ALL(ys[x]), y) - ys[x].begin()); }
	void upd(int x, int y) {
		revi(x);revj(y); tot++;
		for (; x < SZ(ys); x |= x + 1)
			ft[x].update(ind(x, y));
	}
	ll query(int x, int y) {
		revi(x);revj(y);
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};
struct Lazy{
	typedef ii tn; // node type
	typedef ll tl; // lazy type
	ii NEUT={INF,INF};
	#define CLEAR 0 // cleared lazy node
	vector<tn>st; vector<tl>lazy; int n;
	Lazy(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=min(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k].fst+=lazy[k];
		if(e-s!=1){
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			lazy[k]+=v;
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=min(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=min(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,n,p,v);}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn queryall(){return st[1];}
	void init(vector<tn>&a){init(1,0,n,a);}
};
struct STree{
	typedef ll node;
	node oper(node a, node b){return max(a,b);}
	ll NEUT=-1;
	ll fg=0,m;
	int n; vector<node>t;
	ll get(ll n){for(ll pot=1;;pot+=pot)if(pot>=n)return pot;}
	STree(int N, ll fg):n(get(N)),t(2*n+5,NEUT),fg(fg),m(N){}
	void upd(int p, node v){
		if(fg)p=m-1-p;
		if(fg&&v!=NEUT)v=m-1-v;
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	int find(int k, int s, int e, int a, int b, ll v){
		// first mayor a v
		if(e<=a||b<=s) return b; // b es que no lo encontre
		int m = (s+e)/2;
		bool bad=!(t[k]>v); // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return b;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,v);
		if(res==b)res=find(2*k+1,m,e,a,b,v);
		return res; // cuando lo encuentra devuelve algo en [a,b)
	}
	int find(int p){ // needs it alive
		if(fg)p=m-1-p;
		ll v=p==-1?NEUT:t[n+p];
		ll res=find(1,0,n,p+1,m,v);
		if(fg)res=m-1-res;
		return res;
	}
};
int main(){FIN;
	ll n; cin>>n;
	vv a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	vector<set<ll>> ids(2);
	vector<set<ll>> vals(2);
	fore(i,0,n){
		ll v=a[i];
		ll ty=(v<i);
		auto &id=ids[ty];
		if(!ty){
			while(SZ(id)){
				ll j=*id.rbegin();
				if(a[j]>v)id.erase(j);
				else break;
			}
			id.insert(i);
		}
		else {
			if(!SZ(id)||a[*id.rbegin()]<a[i])id.insert(i);
		}
	}
	fore(ty,0,2)for(auto i:ids[ty])vals[ty].insert(a[i]);
	FT2 ft(n,1,0);
	vector<Lazy> st(2,Lazy(n));
	vector<STree> stval={STree(n,1),STree(n,0)};
	fore(i,0,n)ft.fakeUpdate(i,a[i]);
	ft.init();
	fore(ty,0,2){
		vector<ii> ini(n,st[0].NEUT);
		for(auto i:ids[ty]){
			ini[i]={abs(a[i]-i),i};
		}
		fore(i,0,n)if((a[i]<i)==ty)stval[ty].upd(i,a[i]);
		st[ty].init(ini);
		ids[ty].insert(n); ids[ty].insert(-1);
		vals[ty].insert(n); vals[ty].insert(-1);
	}
	p.pb(n);
	auto rang=[&](ll from, ll to, ll ty){
		if(!ty)swap(from,to);
		// cerr<<"rang "<<from<<" "<<to<<" "<<ty<<"\n";
		vv ret;
		for(ll p=stval[ty].find(from);(ty?p<to:p>to);p=stval[ty].find(p))ret.pb(p);
		return ret;
	};
	auto get_sum=[&](ll i, ll ty){
		ll sq00=ft.query(i,a[i]);
		if(!ty)return sq00;
		ll sq10=ft.query(-1,a[i]);
		ll sq01=ft.query(i,n);
		ll sq11=ft.tot;
		return sq11+sq00-sq10-sq01;
	};
	ll res=0;
	fore(_,0,n){
		// cout<<"\nround "<<_+1<<":\n";
		auto [fst,ty]=min(pair<ii,ll>(st[0].queryall(),0),pair<ii,ll>(st[1].queryall(),1));
		auto [val,i]=fst;
		val=max(val,0);
		// cout<<val<<" "<<i<<": "<<ty<<" val i: ty\n";
		// imp(ids[0])
		// imp(ids[1])
		res=max(res,val);
		ft.upd(i,a[i]);
		ids[ty].erase(i);
		vals[ty].erase(a[i]);
		st[ty].upd(i,st[ty].NEUT);
		stval[ty].upd(i,stval[ty].NEUT);
		auto it=ids[ty].lower_bound(i);
		vv vec=rang(*prev(it),*(it),ty);
		for(auto j:vec){
			ll val=abs(a[j]-j)-get_sum(j,ty);
			st[ty].upd(j,{val,j});
			ids[ty].insert(j);
			vals[ty].insert(a[j]);
			// cout<<"added "<<j<<": "<<val<<" got "<<ft[ty].get(j,a[j])<<"\n";
		}
		ll l=*ids[ty^1].lower_bound(i);
		ll rv=*vals[ty^1].lower_bound(a[i]);
		ll r=p[rv];
		if(ty)swap(l,r);
		// cout<<l<<","<<r<<" l,r"<<endl;
		st[ty^1].upd(l,r,-1);
	}
	cout<<res<<"\n";
	return 0;
}

