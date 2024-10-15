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
const ll MAXN=5005;

vector<ll> g[MAXN],t[MAXN];

ll vis[MAXN];
ll z1,z2;
void dfs0(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		t[x].pb(y);
		dfs0(y);
	}
}
ll col[MAXN]; // 0 1 2
bool hay(ll x, ll w){
	ll flag=0;
	for(auto y:t[x])flag|=hay(y,w);
	for(auto y:g[x])flag|=col[y]==w;
	return flag;
}
bool safe(ll x, ll w){
	ll flag=1;
	for(auto y:t[x])flag&=hay(y,w);
	cout<<"safe "<<x<<" "<<w<<": "<<flag<<"\n";
	return flag;
}
ll c[3];
void dfs1(ll x, ll w){
	cout<<"dfs1 "<<x<<" "<<w<<"\n";
	if(c[1]==z1||c[2]==z2)return;
	if(!safe(x,w^3))w^=3;
	cout<<"final "<<w<<"\n\n";
	col[x]=w;
	c[w]++;
	for(auto y:t[x])dfs1(y,w);
}

int main(){FIN;
	ll dlfkjg; cin>>dlfkjg;
	while(dlfkjg--){
		ll n,m; cin>>z1>>z2>>m;
		n=z1+z2;
		//RESET
		fore(i,0,n){
			g[i].clear();	
			t[i].clear();
			vis[i]=0;
			col[i]=0;
		}
		fore(i,0,3)c[i]=0;
		//
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs0(0);
		dfs1(0,1);
		vv res[2];
		ll def=(c[1]==z1?2:1);
		fore(i,0,n){
			if(col[i]==0)col[i]=def;
			res[col[i]-1].pb(i);
		}
		auto dbg=[&](){
			vector<int>uf(n,-1);
			auto uf_find=[&](int x, auto &&uf_find)->int{
				return uf[x]<0?x:uf[x]=uf_find(uf[x],uf_find);
			};
			auto uf_join=[&](int x, int y){
				x=uf_find(x,uf_find);y=uf_find(y,uf_find);
				if(x==y)return false;
				if(uf[x]>uf[y])swap(x,y); // y -> x
				uf[x]+=uf[y];uf[y]=x;
				return true;
			};
			fore(x,0,n)for(auto y:g[x])if(col[x]==col[y])
				uf_join(x,y);
			set<ll>st;
			fore(i,0,n)st.insert(uf_find(i,uf_find));
			if(SZ(st)>2)
				cout<<"WA\nnot connected\n";
			if(SZ(res[0])!=z1||SZ(res[1])!=z2)
				cout<<"WA\nsizes do not match\n";
		};
		dbg();
		fore(h,0,2){
			for(auto i:res[h])cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}