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
#define NEUT 0
#define oper max
struct STree{
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
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);}
	ll upd(ll p, ll v){return upd(rt,p,v);}
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};
const ll C=1e9+5;
int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].fst+=C;
	STree st(1e10);
	sort(ALL(a));
	for(ll i=n-1;i>=0;i--){
		ll res=st.query(st.rt,a[i].fst+a[i].snd,st.n);
		st.upd(a[i].fst-a[i].snd,res+1);
		//cout<<"\n"<<i<<": "<<a[i].fst-C<<" "<<a[i].snd<<"\n";
		//cout<<"query "<<a[i].fst+a[i].snd+1-C<<","<<st.n<<" = "<<res<<"\n";
		//cout<<"upd "<<a[i].fst-a[i].snd-C<<" "<<res+1<<"\n";
	}
	cout<<st.query(st.rt,0,st.n)<<"\n";
	return 0;
}
