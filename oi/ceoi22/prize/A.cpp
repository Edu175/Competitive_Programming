#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ceoi=b;i<ceoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto kdjfhg:v)cout<<kdjfhg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5,K=20;

vector<ll> g[2][MAXN]; ll n; ll rt[2];
struct LCA{
	vector<vector<ll>>F; vector<ll>D,V;
	LCA(): F(K,vector<ll>(1<<K)),D(MAXN),V(MAXN){}
	void lca_dfs(ll x, ll z){
		for(auto y:g[z][x])if(y!=F[0][x]){
			F[0][y]=x;
			D[y]=D[x]+1;
			lca_dfs(y,z);
		}
	}
	void lca_init(ll rt, ll z){
		D[rt]=0;F[0][rt]=-1;
		lca_dfs(rt,z);
		fore(k,1,K)fore(i,0,n){
			if(F[k-1][i]<0)F[k][i]=-1;
			else F[k][i]=F[k-1][F[k-1][i]];
		}
	}
	ll lca(ll x, ll y){
		if(D[x]<D[y])swap(x,y);
		for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
		if(x==y)return x;
		for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
			x=F[k][x];
			y=F[k][y];
		}
		x=F[0][x];
		return x;
	}
};
ll S[2][MAXN],E[2][MAXN];
ll cnt=0;
//ll dbg=0;
void dfs(ll x, ll w, ll f=-1){
	//if(dbg)cout<<"dfs "<<x<<" "<<w<<" "<<f<<"\n";
	S[w][x]=cnt++;
	for(auto y:g[w][x])if(y!=f)dfs(y,w,x);
	E[w][x]=cnt;
}
ll cmp0(ll x, ll y){
	return S[0][x]<S[0][y];
}
ll cmp1(ll x, ll y){
	return S[1][x]<S[1][y];
}
//vector<ll>t[2][MAXN];

void make(ll w, vector<ll>v){
	if(w)sort(ALL(v),cmp1);
	else sort(ALL(v),cmp0);
	//cout<<"make ";imp(v);cout<<endl;
	stack<ll>st;
	st.push(v[0]);
	/*for(auto i:v){
		cout<<S[w][i]<<","<<E[w][i]<<endl;
	}*/
	fore(i,1,SZ(v)){
		while(!(S[w][st.top()]<S[w][v[i]]&&S[w][v[i]]<E[w][st.top()]))
			st.pop();
		g[w][st.top()].pb(v[i]);
		g[w][v[i]].pb(st.top());
		st.push(v[i]);
	}
}

int main(){
	ll k,q,consul; cin>>n>>k>>q>>consul;
	fore(h,0,2)fore(i,0,n){
		ll p; cin>>p; p--;
		if(p<0)rt[h]=i;
		else {
			g[h][p].pb(i);
			g[h][i].pb(p);
		}
	}
	fore(h,0,2)cnt=0,dfs(rt[h],h);
	LCA G[2];
	fore(h,0,2)G[h].lca_init(rt[h],h);
	set<ll>st={rt[0],g[0][rt[0]][0]},no;
	set<ll,decltype(cmp0)*>t0(cmp0);
	set<ll,decltype(cmp1)*>t1(cmp1);
	fore(i,0,n)no.insert(i);
	for(auto j:st)no.erase(j),t0.insert(j),t1.insert(j);
	ll w=1,u=0,x=G[1].lca(*st.begin(),*next(st.begin()));
	if(st.count(x))x=-1;
	while(SZ(st)<k){
		if(x==-1)x=*no.begin();
		st.insert(x); no.erase(x);
		set<ll>xs;
		auto tr=t0;
		if(w)tr=t1;
		tr.insert(x);
		auto p=tr.lower_bound(x);
		if(p!=tr.begin()){
			auto l=u=*prev(p);
			ll xi=G[w].lca(l,x);
			if(!st.count(xi))xs.insert(xi);
		}
		if(p!=prev(tr.end())){
			auto r=u=*next(p);
			ll xi=G[w].lca(x,r);
			if(!st.count(xi))xs.insert(xi);
		}
		while(!(SZ(xs)<2));
		if(SZ(xs))x=*xs.begin();
		else x=-1;
		w^=1;
	}
	w^=1;
	vector<ll>nod;
	for(auto i:st)nod.pb(i);
	ll root=(x!=-1?u:nod[0]);
	//dbg=1;
	fore(h,0,2)cnt=0,dfs(root,h);
	fore(h,0,2)fore(i,0,n)g[h][i].clear();
	make(!w,nod);
	if(x!=-1)nod.pb(x);
	make(w,nod);
	if(x!=-1)nod.pop_back();
	fore(h,0,2)G[h].lca_init(root,h);
	for(auto i:nod)cout<<i+1<<" ";;cout<<endl;
	for(auto i:nod){
		cout<<"? "<<i+1<<" "<<root+1<<endl;
	}
	cout<<"!"<<endl;
	fore(i,0,SZ(nod)){
		fore(h,0,2){
			vector<ll>v(2);
			fore(j,0,2)cin>>v[j];
			G[h].V[nod[i]]=v[0]+v[1];
			if(x!=-1&&w==h&&G[h].lca(nod[i],root)==x)G[h].V[x]=v[1];
		}
	}
	/*cout<<root<<endl;
	fore(h,0,2){
		cout<<"tree "<<h<<":\n";
		fore(i,0,n)cout<<G[h].V[i]<<" ";
		cout<<"\n";
	}*/
	vector<ii>ans(consul);
	fore(i,0,consul){
		ll x,y; cin>>x>>y; x--,y--;
		ll p0=G[0].lca(x,y);
		ans[i].fst=G[0].V[x]+G[0].V[y]-2*G[0].V[p0];
		ll p1=G[1].lca(x,y);
		ans[i].snd=G[1].V[x]+G[1].V[y]-2*G[1].V[p1];
		//cout<<x+1<<" "<<y+1<<": "<<p0+1<<" "<<p1+1<<"\n";
	}
	for(auto i:ans)cout<<i.fst<<" "<<i.snd<<endl;
	return 0;
}
