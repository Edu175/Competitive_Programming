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
const ll INF=5e9;
#define oper min
#define NEUT INF

struct STree{
	vector<ll>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	

int main(){FIN;
	ll n,q; cin>>n>>q;
	STree r(n),c(n);
	fore(i,0,n)r.upd(i,0),c.upd(i,0);
	while(q--){
		ll t; cin>>t;
		if(t<3){
			ll x,y; cin>>x>>y; x--,y--;
			//cout<<t<<": "<<r.query(x,x+1)<<" "<<c.query(y,y+1)<<": ";
			if(t==1)r.upd(x,r.query(x,x+1)+1),c.upd(y,c.query(y,y+1)+1);
			else r.upd(x,r.query(x,x+1)-1),c.upd(y,c.query(y,y+1)-1);
			//cout<<r.query(x,x+1)<<" "<<c.query(y,y+1)<<"\n";
		}
		else{
			ll x1,y1; cin>>x1>>y1; x1--,y1--;
			ll x2,y2; cin>>x2>>y2;
			//cout<<"["<<x1<<","<<x2<<"): "<<r.query(x1,x2)<<"\n";
			//cout<<"["<<y1<<","<<y2<<"): "<<c.query(y1,y2)<<"\n";
			if(r.query(x1,x2)!=0||c.query(y1,y2)!=0)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
