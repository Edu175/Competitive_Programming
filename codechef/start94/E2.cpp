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
// rank queries

ll oper(ll a, ll b){return a+b;}
#define NEUT 0 
struct STree{ //persistent
	vector<int>st,L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){ // add v to p
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
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 1)
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		ll a[n];
		map<ll,ll>id;
		fore(i,0,n)cin>>a[i],id[a[i]]=-1;
		ll j=0;
		for(auto &i:id)i.snd=j++;
		fore(i,0,n)a[i]=id[a[i]];
		vector<ll>rt(n+1);
		STree st(n+5);
		rt[0]=st.rt;
		//imp(a);
		fore(i,1,n+1){
			rt[i]=st.upd(a[i-1],1);
			/*cout<<i<<" "<<rt[i]<<": ";
			fore(j,0,n)cout<<st.query(rt[i],j,j+1)<<" ";
			cout<<"\n";*/
		}
		fore(i,0,q){
			ll k,r; cin>>k>>r; k--;// r--;
			ll c=st.query(rt[k],a[k]+1,n),d=st.query(rt[n],a[k]+1,n)-c;
			//if(c>d)swap(c,d);
			//cout<<i<<": "<<rt[k]<<","<<c<<" "<<rt[n]<<","<<st.query(rt[n],a[k]+1,n)<<": "<<c<<" "<<d<<"\n";
			ll s=0,e=n;
			while(s<=e){
				ll m=(s+e)/2;
				if(max(c-m,(ll)0)+max(d-m,(ll)0)+1<=r)e=m-1;
				else s=m+1;
			}
			/*ll x=0,res=n;
			x=d-r;
			if(x>=c)res=min(res,x);
			x=(c+d-r+1)/2;
			if(x<=c)res=min(res,x);*/
			cout<<s<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
