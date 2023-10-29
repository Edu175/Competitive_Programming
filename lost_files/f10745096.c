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
#define oper max
#define NEUT 0

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
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		pair<ll,ll> a[k];
		fore(i,0,k){
			cin>>a[i].fst>>a[i].snd;
			a[i].fst=n-a[i].fst;
			a[i].snd=m-a[i].snd;
			a[i].snd*=-1;
		}
		sort(a,a+k);
		fore(i,0,k)a[i].snd*=-1;
		vector<ll>v;
		fore(i,0,k){
			if(a[i].fst==0||a[i].snd==0)continue;
			//cout<<a[i].fst<<","<<a[i].snd<<"\n";
			ll lwb=lower_bound(ALL(v),a[i].snd)-v.begin();
			if(lwb==SZ(v))v.pb(a[i].snd);
			else v[lwb]=a[i].snd;
		}
		cout<<n+m-2-SZ(v)<<"\n";
		/*STree st(m);
		ll res=0;
		for(auto i:a){
			if(i.snd)
			ll resi=st.query(0,i.snd)+1;
			st.upd(i.snd,resi);
			res=max(res,resi);
		}
		cout<<n+m-2-res<<"\n";*/
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
