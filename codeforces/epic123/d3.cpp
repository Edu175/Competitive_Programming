#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;
typedef ll node;
#define oper min
#define NEUT MAXN
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
#define oper2(a,b) ((a)+(b))
#define NEUT2 0
struct STree2{
	int n; vector<node>t;
	STree2(int n):n(n),t(2*n+5,NEUT2){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper2(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT2;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper2(res,t[l++]);
			if(r&1)res=oper2(res,t[--r]);
		}
		return res;
	}
};
vv g[MAXN];
ll S[MAXN],E[MAXN],fa[MAXN];
ll cnt=0;

void dfs0(ll x){
	S[x]=cnt++;
	for(auto y:g[x])fa[y]=x,dfs0(y);
	E[x]=cnt;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n){
			g[i].clear();
		}
		cnt=0;
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fa[0]=-1;
		dfs0(0);
		STree st(n);
		vv a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		auto upd=[&](ll i){st.upd(S[i],p[i]);};
		auto bad=[&](ll i){return !(st.query(S[i],E[i])>=p[i]);};
		fore(i,0,n)upd(i);
		STree2 sum(n);
		fore(i,0,n)sum.upd(i,bad(i));
		fore(_,0,q){
			ll i,j; cin>>i>>j; i--,j--;
			ll x=a[i],y=a[j];
			set<ll>st;
			auto chain=[&](ll x){
				while(x!=-1)st.insert(x),x=fa[x];
			};
			chain(x);
			chain(y);
			// cant-=bad(x)+bad(y);
			swap(a[i],a[j]);
			swap(p[x],p[y]);
			upd(x);
			upd(y);
			for(auto i:st)sum.upd(i,bad(i));
			// cant+=bad(x)+bad(y);
			imp(a)
			// imp(p)
			fore(i,0,n)cout<<"bad "<<i<<": "<<bad(i)<<"\n";
			// cout<<cant<<"\n";
			if(!sum.query(0,n))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
