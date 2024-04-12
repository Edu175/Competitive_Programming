#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,balkoi=b;i<balkoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdkj:v)cerr<<sdkj<<" ";cout<<endl
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
bool cmp2(ll a, ll b){
	return D[a]>D[b];
}
struct my{ll a;};
bool operator<(my a, my b){return S[a.a]<S[b.a];}
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
	fore(d,0,n)if(SZ(nod[d])){
		auto v=nod[d];
		sort(ALL(v),cmp);
		set<my>st;
		for(auto i:v)st.insert(my({i}));
		vector<ll>ps;
		fore(i,0,SZ(v)-1)ps.pb(lca(v[i],v[i+1]));
		sort(ALL(ps),cmp2);
		//cout<<"depth "<<d<<": "; imp(v);
		for(auto p:ps)if(p){
			vector<ll>h;
			for(auto it=st.lower_bound(my({p}));
			it!=st.end()&&S[it->a]<E[p];it++)
				h.pb(it->a);
			//cout<<p<<": ";imp(h);
			if(SZ(h)>1){
				for(auto i:h)st.erase(my({i})),vis[i]=1;
			}
		}
	}
	fore(i,0,n){
		if(vis[i])cout<<"-1 ";
		else cout<<D[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
