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
const ll MAXN=1e5+5;
vector<ll>g[MAXN];

typedef ll node;
/*struct node{
	//element (if ll typedef)
	node(){}
};*/
#define NEUT 0
node combine(node a, node b){
	return max(a,b);
}
void level_up(node &x){// add edge
	//climb a level in tree
	x++;
}

node h[MAXN],ch[MAXN]; //hijos, complement hijos
vector<node>pre[MAXN],suf[MAXN];//	[0,i)  ,  [i,n)
ll f[MAXN];
void subtree(ll x){
	for(auto y:g[x]){
		if(y==f[x])continue;
		f[y]=x;
		subtree(y);
		h[x]=combine(h[x],h[y]);
	}
	level_up(h[x]);
}
void father_subtree(ll x){
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y==f[x])continue;
		ch[y]=combine(combine(pre[x][i],suf[x][i+1]),ch[x]);
		level_up(ch[y]);
		father_subtree(y);
	}
}
void rerooting(ll n){
	fore(i,0,n){// clear if testcases
		h[i]=NEUT, ch[i]=NEUT; // MUST
		pre[i].clear();
		suf[i].clear();
	}
	subtree(0);
	fore(x,0,n){
		suf[x].resize(SZ(g[x])+1,NEUT);
		pre[x].resize(SZ(g[x])+1,NEUT);
		fore(i,1,SZ(g[x])+1){			
			ll y=g[x][i-1];
			if(y==f[x])pre[x][i]=pre[x][i-1];
			else pre[x][i]=combine(pre[x][i-1],h[y]);
		}
		for(ll i=SZ(g[x])-1;i>=0;i--){
			ll y=g[x][i];
			if(y==f[x])suf[x][i]=suf[x][i+1];
			else suf[x][i]=combine(suf[x][i+1],h[y]);
		}
	}
	father_subtree(0);
	// stores subtree in h and complement in ch
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		g[i].clear();
	}
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	rerooting(n);
	vector<ll>d;
	fore(i,0,n)d.pb(max(h[i]-1,ch[i]));//,cout<<i<<": "<<h[i]-1<<" "<<ch[i]<<"\n";
	sort(ALL(d));
	//imp(d);
	vector<ll>res;
	fore(k,1,n+1){
		ll lwb=lower_bound(ALL(d),k)-d.begin();
		res.pb(lwb+(lwb<n));
	}
	imp(res);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
