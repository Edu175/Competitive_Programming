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

/*typedef set<ii> node;
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5){}
	void upd(int p, ii v){
		for(p+=n,t[p].insert(v);p>1;p>>=1)t[p>>1].insert(v);
	}
	ll query(ll l, ll r, ii x){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res|=t[l++].count(x);
			if(r&1)res|=t[--r].count(x);
			if(res)return res;
		}
		return res;
	}
};*/
ll cv(ii p){return (p.fst<<30)|p.snd;}

#define NEUT 0
ll oper(ll a, ll b){return a+b;}
struct STree{ //persistent
	vector<ll>st,L,R,rts; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),rts(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ii p){
		ll x=upd(rt,cv(p),1);
		rts.pb(x);
		return x;
	} // update on last root
	ll rquery(ll k, ll a, ll b){return query(k,0,n,a,b);}
	ll query(ll k, ii p){
		ll a=cv(p);
		return rquery(rts[k],a,a+1);
	}
	ll query(ll l, ll r, ii p){
		return query(r,p)-query(l,p);
	}
};

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
int main(){FIN;
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	vector<ii>a;
	for(auto i:s){
		if(i=='U')a.pb({0,1});
		if(i=='D')a.pb({0,-1});
		if(i=='L')a.pb({-1,0});
		if(i=='R')a.pb({1,0});
	}
	vector<ii>nor={{0,0}},rev=nor;
	fore(i,0,n)nor.pb(nor.back()+a[i]);
	reverse(ALL(a));
	fore(i,0,n)rev.pb(rev.back()+a[i]);
	STree st1(n+5),st2(n+5);
	fore(i,0,SZ(nor))st1.upd(nor[i]);
	fore(i,0,SZ(rev))st2.upd(rev[i]);
	while(q--){
		ii p; ll l,r; cin>>p.fst>>p.snd>>l>>r;
		ll res=0;
		res|=st1.query(0,l,p)|st1.query(r,n+1,p);
		p=p-nor[l-1];
		r=n+1-r,l=n+1-l;
		p=p+rev[r-1];
		//cout<<"["<<r<<","<<l<<"] "<<p.fst<<","<<p.snd<<"\n";
		res|=st2.query(r,l+1,p);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
