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
typedef ll node;
#define oper min
#define NEUT 1e11
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
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>c(n);
		ll a[n][m];
		fore(i,0,n)cin>>c[i];
		fore(i,0,n)fore(j,0,m){
			cin>>a[i][j];
		}
		vector<STree> men(m,STree(1e10)),may(m,STree(1e10));
		ll ans=0;
		fore(j,0,m)men[j].upd(a[0][j],0),may[j].upd(a[0][j],a[0][j]);
		fore(i,1,n){
			ll res=INF,resp=INF;
			STree pag(m+1);
			vector<ii>p(m);
			fore(j,0,m){
				pag.upd(m,men[j].query(0,a[i][j]+1));
				ll rq=may[j].query(a[i][j]+1,may[j].n)-a[i][j];
				p[i]={}
				pag.upd(i,);
			}
			fore(j,0,m){
				men[j].upd()
			}
		}
	}
	return 0;
}
