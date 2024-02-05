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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MAXN=2e5+5;

vector<ll>g[MAXN]; ll n;
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}

ll cnt=0;
vector<ll> dag[3*MAXN];
void add(ll x, ll y, ll t){
	//cout<<"add "<<x<<" "<<y<<"\n";
	//if(x==y)return;
	if(!t)dag[x].pb(y); // down
	else dag[y].pb(x);  // up
}
struct Rang{
	ll n,t; vector<ll>k;
	Rang(){}
	Rang(ll n, ll t):n(n),t(t),k(2*n+5){
		fore(i,0,n){
			k[i]=cnt++;
			k[pos[i]+n]=i;
		}
		fore(i,1,n){
			add(k[i],k[2*i],t);
			add(k[i],k[2*i+1],t);
		}
	}
	void query(ll l, ll r, ll c){
		if(l<=pos[c]&&pos[c]<r){
			query(l,pos[c],c);
			query(pos[c]+1,r,c);
			return;
		}
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)add(c,k[l++],t);
			if(r&1)add(c,k[--r],t);
		}
	}
};

void query(int x, int y, int c, Rang& rmq){
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		rmq.query(pos[head[y]],pos[y]+1,c);
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	rmq.query(pos[x],pos[y]+1,c);	// *
}

ll vis[MAXN*3];
ll flag=1;
vector<ll> ord;

void dfs(ll x){
	vis[x]=1;
	//cout<<"in "<<x<<"\n";
	for(auto y:dag[x]){
		if(!vis[y])dfs(y);
		if(vis[y]==1)flag=0;
		//,cout<<"FAILED "<<x<<" "<<y<<"\n";
	}
	//cout<<"out "<<x<<"\n";
	ord.pb(x);
	vis[x]=2;
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	hld_init();
	cnt=n;
	Rang st[2];
	fore(i,0,2)st[i]=Rang(n,i);
	while(q--){
		ll t,a,b,c; cin>>t>>a>>b>>c; t--,a--,b--,c--;
		//cout<<"query "<<t<<": "<<a<<" "<<b<<" "<<c<<"\n";
		query(a,b,c,st[t]);
		//cout<<"\n";
	}
	/*cout<<cnt<<"\n";
	fore(i,0,3*n){
		cout<<i<<": "<<dag[i]<<"\n";
	}*/
	fore(i,0,n)if(!vis[i])dfs(i);
	fore(i,0,3*n)
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	reverse(ALL(ord));
	vector<ll>res(n);
	ll asd=1;
	for(auto i:ord){
		if(i<n)res[i]=asd++;
	}
	imp(res);
	return 0;
}
