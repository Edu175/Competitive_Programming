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
const ll MAXN=2e5+5,INF=1e12;

vector<ll>g[MAXN];

struct node{
	ll mini,len;
	node(ll mini, ll len):mini(mini),len(len){}
	node(){}
};
#define NEUT node(INF,0)
node h[MAXN],ch[MAXN]; //hijos, complement hijos
vector<node>pre[MAXN],suf[MAXN];//	[0,i)  ,  [i,n)
ll f[MAXN];
node oper(node a, node b){
	a.mini=min(a.mini,b.mini);
	if(b.len==0)return a;
	if(a.len==0)return b;
	if(b.len<a.len)a.mini=min(a.mini,a.len),a.len=b.len;
	else a.mini=min(a.mini,b.len);
	return a;
}
void level_up(node &x){ //climb a level in tree
	x.len++;
}
void subtree(ll x){
	for(auto y:g[x]){
		if(y==f[x])continue;
		f[y]=x;
		subtree(y);
		h[x]=oper(h[x],h[y]);
	}
	level_up(h[x]);
}
void father_subtree(ll x){
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y==f[x])continue;
		ch[y]=oper(oper(pre[x][i],suf[x][i+1]),ch[x]);
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
			else pre[x][i]=oper(pre[x][i-1],h[y]);
		}
		for(ll i=SZ(g[x])-1;i>=0;i--){
			ll y=g[x][i];
			if(y==f[x])suf[x][i]=suf[x][i+1];
			else suf[x][i]=oper(suf[x][i+1],h[y]);
		}
	}
	father_subtree(0);
	// stores subtree in h and complement in ch
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		rerooting(n);
		ll res=0;
		fore(x,0,n){
			ll resi=min({h[x].mini,ch[x].mini,h[x].len+ch[x].len});
			//cout<<x<<": "<<h[x].mini<<","<<h[x].len<<" "<<ch[x].mini<<","<<ch[x].len<<": "<<resi<<"\n";
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
