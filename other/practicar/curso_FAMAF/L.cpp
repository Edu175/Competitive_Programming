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

const ll K=20;//K such that 2^k>n
#define oper gcd
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s,ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}
struct STree{ //persistent de suma con upd de suma
	ll oper(ll a, ll b){return a+b;}
	#define NEUT 0
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
const ll MAXV=1e9+5;
int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	st_init(a);
	STree stp(MAXV);
	vector<ll>rt={stp.rt};
	fore(i,0,n)rt.pb(stp.upd(a[i],1));
	/*imp(rt);
	fore(i,0,n+1){
		cout<<i<<" "<<rt[i]<<" "<<(i?a[i-1]:-1)<<": ";
		fore(j,0,5)cout<<stp.query(rt[i],j,j+1)<<" ";
		cout<<"\n";
	}*/
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll g=st_query(l,r);
		ll res=stp.query(rt[r],g,g+1)-stp.query(rt[l],g,g+1);
		//cout<<l<<" "<<r<<": "<<g<<": "<<rt[r]<<" - "<<rt[l]<<": "<<stp.query(rt[r],g,g+1)<<"-"<<stp.query(rt[l],g,g+1)<<"\n";
		cout<<(r-l)-res<<"\n";
	}
	return 0;
}
