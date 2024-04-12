#include "highway.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=9e4+5;
vector<ii> g[MAXN];
ii pa[MAXN];
ll vis[MAXN],D[MAXN];
vector<int>s,h;
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vis[y]){
		pa[y]={x,i};
		D[y]=D[x]+1;
		dfs(y);
	}
	if(SZ(g[x])==1&&g[x][0].fst==pa[x].fst)h.pb(x);
}

ll n;
void paint(ll x, ll r=n){
	fore(i,0,r){
		if(pa[x].fst==-1||s[pa[x].snd]==1)break;
		s[pa[x].snd]=1;
		x=pa[x].fst;
	}
}

/*ll ask(ll x){
	s=vector<int>(m);
	paint(x);
	return ask(s);
}*/
void find_pair(int N, std::vector<int> U, std::vector<int> V, int A, int B) {
	int M = U.size();
	ll m=M,a=A,b=B;
	n=N;
	s.resize(m);
	fore(i,0,m){
		g[U[i]].pb({V[i],i});
		g[V[i]].pb({U[i],i});
	}
	srand(175);
	ll rt=rand()%n;
	pa[rt]={-1,-1};
	D[rt]=0;
	dfs(rt);
	ll d=ask(s)/a;
	// cerr<<rt<<endl;
	// imp(h);
	ll l=0,r=SZ(h)-1;
	while(l<=r){
		ll mid=(l+r)/2;
		s=vector<int>(m);
		fore(i,0,mid+1)paint(h[i]);
		if(ask(s)<d*b)l=mid+1;
		else r=mid-1;
	}
	ll x=h[l];
	l=0,r=SZ(h)-1;
	while(l<=r){
		ll mid=(l+r)/2;
		s=vector<int>(m);
		fore(i,mid,SZ(h))paint(h[i]);
		if(ask(s)<d*b)r=mid-1;
		else l=mid+1;
	}
	ll y=h[r];
	/*ll flag=0;
	if(ask(x)==d*b)flag=1;
	else if(ask(y)==d*b)flag=1,swap(x,y);*/
	
	l=0,r=D[x];
	while(l<=r){
		ll mid=(l+r)/2;
		s=vector<int>(m);
		paint(x,mid);
		if(ask(s)==d*a)l=mid+1;
		else r=mid-1;
	}
	ll S=x;
	//cout<<r<<" r\n";
	fore(i,0,r){
		S=pa[S].fst;
	}
	/*s=vector<int>(m);
	paint(x,1);
	cout<<as*/
	s=vector<int>(n);
	for(ll y=x;y>=0;y=pa[y].fst){
		s[y]=1;
	}
	ll lca=y;
	for(ll i=y;i>=0;i=pa[i].fst){
		if(s[i]){lca=i;break;}
	}
	ll E=-1;
	if(D[lca]>=D[S]){
		ll v=S;
		fore(j,0,d)v=pa[v].fst;
		E=v;
		//cout<<"ig \n";
	}
	else {
		for(ll i=y;i>=0;i=pa[i].fst){
			if(D[i]==d-(D[S]-D[lca])+D[lca]){E=i;break;}
		}
	}
	// cerr<<x<<" "<<y<<"\n"<<lca<<"\n";
	// cout<<S<<" "<<E<<endl;
	answer(S,E); 
}
