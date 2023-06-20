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
		ii a[m];
		fore(i,0,m){
			cin>>a[i].fst>>a[i].snd; a[i].fst--;
		}
		vector<ll>u(n,-1);
		ll q; cin>>q;
		fore(i,0,q){
			ll p; cin>>p; p--;
			u[p]=i;
		}
		STree st(n);
		vector<ll>rt={st.rt};
		fore(i,0,n){
			if(u[i]!=-1)rt.pb(st.upd(u[i],1));
			else rt.pb(rt.back());
		}
		//imp(rt);
		ll res=n+5;
		for(auto i:a){
			ll l=i.fst,r=i.snd;
			ll s=0,e=n-1;
			while(s<=e){
				ll md=(s+e)/2;
				if(st.query(rt[r],0,md+1)-st.query(rt[l],0,md+1)>=(r-l)/2+1)e=md-1;
				else s=md+1;
			}
			//cout<<l<<" "<<r<<"("<<(r-l)/2+1<<"): "<<s<<" "<<e<<" --> "<<st.query(r,0,s+1)<<"-"<<st.query(l,0,s+1)<<" = "<<st.query(r,0,s+1)-st.query(l,0,s+1)<<"\n";
			res=min(res,s);
		}
		if(res>=n)cout<<"-1\n";
		else cout<<res+1<<"\n";
	}
	return 0;
}
