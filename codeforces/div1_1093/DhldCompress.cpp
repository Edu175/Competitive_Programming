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
#pragma GCC target("avx2")
const ll MAXN=2e5+5;
typedef long long ll;
#define W 6
const int Wall=(1<<W)-1;

// 2**W-ary tree
struct STree{
	int offs; 
	vector<ll> t;
	vector<int> bag;
	STree(){}
	STree(int n){
		offs=(n+Wall-1)/Wall;
		t=vv(offs+n);
	}
	void upd(int p, ll fst, int snd){ 
		ll v=(fst<<24)+snd; 
		p+=offs;
		bag.pb(p);
		while(1){
			t[p]+=v;
			if(!p)break;
			p>>=W;
		}
	}
	pair<ll,int> query(int l, int r){
		ll res=0;
		for(l+=offs,r+=offs;l<r;l>>=W,r>>=W){
			while((l&Wall)&&l<r)res+=t[l++];
			while((r&Wall)&&l<r)res+=t[--r];
		}
		return {res>>24, res&0xFFFFFF};
	}
	void reset(){
		for(auto p:bag){
			while(t[p]){
				t[p]=0;
				if(!p)break;
				p>>=W;
			}
		}
		bag.clear();
	}
};
vv g[MAXN];
ii par[MAXN];
ll a[MAXN],S[MAXN],E[MAXN],sz[MAXN],fa[MAXN],ord[MAXN];
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
	S[x]=cnt;
	ord[cnt++]=x;
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
		vector<STree> STs(m);
		vector<vv> vals(m);
		fore(x,0,n){
			auto [mex1,mex2]=par[x];
			vals[mex1].pb(mex2);
		}
		fore(mex,0,m){
			auto &v=vals[mex];
			sort(ALL(v));
			v.resize(unique(ALL(v))-v.begin());
			STs[mex]=STree(SZ(v));
		}
		auto get_idx=[&](ll i, ll j){
			auto &v=vals[i];
			return lower_bound(ALL(v),j)-v.begin();
		};
		vv us;
		auto agr=[&](ll x){
			auto [mex1,mex2]=par[x];
			ST1.upd(mex1,mex1,1);
			STs[mex1].upd(get_idx(mex1,mex2),mex2,1);
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
				auto [sum,cant]=STs[mex1].query(0,get_idx(mex1,a[x]));
				cur+=sum-cant*mex1;
			}
			
			{ // mex1_j=mex1 and mex2_j >= a[x]
				auto [sum,cant]=STs[mex1].query(get_idx(mex1,a[x]),SZ(vals[mex1]));
				cur+=cant*(a[x]-mex1);
			}
			res=max(res,cur);
		};
		fore(_x,0,n)if(SZ(g[_x])==0){
			ll x=_x;
			ll prev=E[x];
			while(1){
				fore(i,prev,E[x])agr(ord[i]);
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