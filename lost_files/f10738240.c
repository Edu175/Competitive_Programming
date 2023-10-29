#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

#define NEUT 0
ll oper(ll a, ll b){return a+b;}
struct STree{ //persistent
	vector<int>st,L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]+=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		//cout<<k<<": "<<L[k]<<" "<<R[k]<<" ahora es "<<ks<<": "<<L[ks]<<" "<<R[ks]<<"\n";
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	/*void dbg(ll k, ll s, ll e){
		if(k==0)return;
		cout<<k<<" ("<<st[k]<<"): "<<L[k]<<" "<<R[k]<<"\n";
		if(s+1!=e){
			ll m=(s+e)/2;
			dbg(L[k],s,m); dbg(R[k],m,e);
		}
		
	}*/
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 1)
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};
ll MAXX=1e9+5;
int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	STree st(n);
	vector<ii>rt(n);
	rt.pb({MAXX,st.rt}); //0
	sort(ALL(a));
	/*for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\n";*/
	for(ll i=n-1;i>=0;i--){
		rt[i]={a[i].fst,st.upd(a[i].snd,1)};
		/*cout<<rt[i].fst<<","<<rt[i].snd<<": ";
		fore(j,0,n)cout<<st.query(rt[i].snd,j,j+1)<<" ";
		cout<<"\n";*/
		//cout<<st.st<<"\n";
		//st.dbg(rt[i].snd,0,n); cout<<"\n\n";
		
	}
	ll q; cin>>q;
	while(q--){
		ll l,r,x; cin>>l>>r>>x; l--;
		ii fi={x+1,-1};
		ll k=(*lower_bound(ALL(rt),fi)).snd;
		//cout<<x<<": "<<k<<"\n";
		cout<<st.query(k,l,r)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Ho