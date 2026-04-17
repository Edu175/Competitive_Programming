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
// node invOper(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
node NEUT={0,0};
struct STree{ // lazy creation
	vector<node> st; vector<int>L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		// if(!k)return NEUT;
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, node v){return upd(rt,p,v);} // update on last root
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	node query(ll a, ll b){return query(rt,0,n,a,b);}
	void reset(){
		*this=STree(n);
	}
};
vv g[MAXN];
ii par[MAXN];
ll a[MAXN],S[MAXN],E[MAXN],sz[MAXN],fa[MAXN];
ll cnt=0;
set<ll> st;
void dfs1(ll x, ll f){
	fa[x]=f;
	sz[x]=1;
	for(auto y:g[x])if(y!=f){
		dfs1(y,x);
		sz[x]+=sz[y];
	}
	sort(ALL(g[x]),[&](ll a, ll b)->bool {
		if(a==f)return 0;
		if(b==f)return 1;
		return sz[a]>sz[b];
	});
	if(f!=-1)g[x].pop_back();
}
void dfs2(ll x){
	S[x]=cnt++;
	
	st.erase(a[x]);
	auto it=st.begin();
	par[x]={*it,*(++it)};

	for(auto y:g[x])dfs2(y);
	E[x]=cnt;
	
	st.insert(a[x]);
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
		dfs2(0);
		ll fij=0;
		fore(x,0,n)fij+=par[x].fst;
		ll res=fij;
		
		ll m=n+3;
		STree ST1(m);
		vector<STree> STs(m,STree(m));
		vv us;
		auto agr=[&](ll x){
			auto [mex1,mex2]=par[x];
			ST1.upd(mex1,{mex1,1});
			STs[mex1].upd(mex2,{mex2,1});
			us.pb(mex1);
		};
		auto reset=[&](){
			ST1.reset();
			for(auto i:us)STs[i].reset();
			us.clear();
		};
		auto answer=[&](ll x){
			auto [mex1,mex2]=par[x];
			ll cur=fij;
			{ // mex1_j>a[x]
				auto [sum,cant]=ST1.query(a[x]+1,m);
				cur-=sum;
				cur+=a[x]*cant;
			}
			
			{ // mex1_j=mex1 and mex2_j < a[x]
				auto [sum,cant]=STs[mex1].query(0,a[x]);
				cur+=sum-cant*mex1;
			}
			
			{ // mex1_j=mex1 and mex2_j >= a[x]
				auto [sum,cant]=STs[mex1].query(a[x],m);
				cur+=cant*(a[x]-mex1);
			}
			res=max(res,cur);
		};
		fore(_x,0,n)if(SZ(g[_x])==0){
			ll x=_x;
			ll prev=E[x];
			while(1){
				fore(y,prev,E[x])agr(y);
				prev=E[x];
				agr(x);
				answer(x);
				if(fa[x]==-1||g[fa[x]][0]!=x)break;
				x=fa[x];
			}
			reset();
		}
		
		cout<<res<<"\n";
	}
	return 0;
}
