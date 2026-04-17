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
const ll MAXN=2e5+5;
typedef pair<ll,int> node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
node invOper(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
node NEUT={0,0};
struct STree{ //persistent 
	vector<node>st; vector<int>L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	STree(){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]); // *
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, node v){return upd(rt,p,v);} // update on last root
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	
	// (for 2d static queries)
	// n = 2nd coordinate
	// O(p logn) where p = number of points
	// IF ONLY COPYING THIS CHANGE TO oper= IN LEAF UPDATE (acummulate, instead of assign)
	vector<int>rts,keys;
	typedef pair<pair<ll,ll>,node> dat;
	void init(vector<dat>a){
		// init 2d updates, (x,y) coords, value
		rts={0}; keys={};
		sort(ALL(a),[&](const dat &a, const dat &b){
			return a.fst.fst<b.fst.fst;});
		for(auto [pa,v]:a){
			auto [x,y]=pa;
			keys.pb(x);
			rts.pb(upd(y,v));
		}
	}
	node get(ll i, ll j0, ll j1){ // get rectangle [0,i) [j0,j1)
		ll p=lower_bound(ALL(keys),i)-keys.begin();
		return query(rts[p],j0,j1);
	}
	node get(ll i0, ll i1, ll j0, ll j1){
		// get rectangle [i0,i1) [j0,j1) with inverse operation
		return invOper(get(i1,j0,j1),get(i0,j0,j1));
	}
};
vv g[MAXN];
ii par[MAXN];
ll a[MAXN],S[MAXN],E[MAXN];
ll cnt=0;
set<ll> st;
void dfs1(ll x, ll fa){
	S[x]=cnt++;
	st.erase(a[x]);
	auto it=st.begin();
	par[x]={*it,*(++it)};
	for(auto y:g[x])if(y!=fa)dfs1(y,x);
	st.insert(a[x]);
	E[x]=cnt;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		cnt=0;
		st.clear();
		fore(i,0,n+2)st.insert(i);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs1(0,-1);
		
		STree ST1(n);
		vector<pair<ii,node>> ini(n);
		fore(i,0,n)ini[i]={{par[i].fst,S[i]},{par[i].fst,1}};
		ST1.init(ini);
		ll m=n+3;
		vector<STree> STs(m,STree(n));
		vector<vector<pair<ii,node>>> inis(m);
		fore(x,0,n){
			auto [mex1,mex2]=par[x];
			inis[mex1].pb({{mex2,S[x]},{mex2,1}});
		}
		fore(mex,0,m)STs[mex].init(inis[mex]);
		
		ll fij=0;
		fore(x,0,n)fij+=par[x].fst;
		ll res=fij;
		
		fore(x,0,n){
			auto [mex1,mex2]=par[x];
			ll cur=fij;
			{ // mex1_j>a[x]
				auto [sum,cant]=ST1.get(a[x]+1,m,S[x],E[x]);
				cur-=sum;
				cur+=a[x]*cant;
			}
			
			{ // mex1_j=mex1 and mex2_j < a[x]
				auto [sum,cant]=STs[mex1].get(a[x],S[x],E[x]);
				cur+=sum-cant*mex1;
			}
			
			{ // mex1_j=mex1 and mex2_j >= a[x]
				auto [sum,cant]=STs[mex1].get(a[x],m,S[x],E[x]);
				cur+=cant*(a[x]-mex1);
			}
			res=max(res,cur);
		}
		
		cout<<res<<"\n";
	}
	return 0;
}
