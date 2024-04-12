#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,balkoi=b;i<balkoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//#define imp(v) for(auto sdkj:v)cerr<<cv(sdkj)<<" ";cout<<endl
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,popcnt,lzcnt")
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5,K=20;
ll n; vector<ll> g[MAXN];
ll F[K][MAXN],D[MAXN],S[MAXN],E[MAXN];
ll cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		F[0][y]=x;
		dfs(y);
	}
	E[x]=cnt;
}
void lca_init(){
	D[0]=0,F[0][0]=-1;
	dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]==-1)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x, ll y){//same depth
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		x=F[k][x];
		y=F[k][y];
	}
	return F[0][x];
}

bool cmp(ll a, ll b){
	return S[a]<S[b];
}
string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
string cv(ll i){return to_string(i);}
void borrar(multiset<ii>&st, ii x){
	auto it=st.find(x);
	if(it!=st.end())st.erase(it);
}
int main(){FIN;
	cin>>n;
	fore(i,1,n){
		ll p; cin>>p;
		g[p].pb(i);
	}
	lca_init();
	vector<ll>car(n);
	fore(i,0,n)cin>>car[i];
	vector<ll> nod[n];
	vector<ll>vis(n);
	fore(i,0,n){
		if(car[i])nod[D[i]].pb(i);
		else vis[i]=1;
	}
	vector<ll>h[n];
	fore(d,0,n)if(SZ(nod[d])){
		auto v=nod[d];
		//cerr<<"depth "<<d<<"\n";
		//imp(v);
		sort(ALL(v),cmp);
		multiset<ii>st;
		set<ii>id;
		for(auto i:v)id.insert({S[i],i});
		vector<ll>ps;
		fore(i,0,SZ(v)-1){
			ll p=lca(v[i],v[i+1]);
			if(!p)continue;
			ps.pb(p);
			st.insert({-D[p],p});
			h[p].pb(v[i]);
			h[p].pb(v[i+1]);
		}
		while(SZ(st)){
			auto [dg,p]=*st.begin(); //st.erase(st.begin());
			//cerr<<p<<" | "; imp(st);
			for(auto x:h[p])if(!vis[x]){
				//cerr<<"saco "<<x<<endl;
				//imp(id);
				vis[x]=1;
				auto lwb=id.lower_bound({S[x],x});
				ll l=-1,r=-1;
				if(lwb!=id.begin()){
					//cout<<"izq"<<endl;
					l=prev(lwb)->snd;
					ll np=lca(l,x);
					if(np)borrar(st,{-D[np],np});
				}
				if(lwb!=prev(id.end())){
					r=next(lwb)->snd;
					ll np=lca(r,x);
					//cout<<"der "<<np<<endl;
					if(np)borrar(st,{-D[np],np});
				}
				id.erase(lwb);
				if(l!=-1&&r!=-1){
					ll np=lca(l,r);
					//assert(p!=np); ///SOLVED
					//while(p==np);
					if(np&&p!=np)st.insert({-D[np],np});
					if(np&&p!=np)h[np].pb(l);
					if(np&&p!=np)h[np].pb(r);
				}
			}
			h[p].clear();
		}
		for(auto p:ps){
			//assert(SZ(h[p])==0);
			h[p].clear();
		}
	}
	fore(i,0,n){
		if(vis[i])cout<<"-1 ";
		else cout<<D[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
