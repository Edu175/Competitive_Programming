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
const ll MAXN=2005;

vector<ll> g[MAXN];
int vis[MAXN];

ll n1,n2,q=0,b=1;
void bfs(ll s){
	queue<ll>qu;
	qu.push(s);
	while(SZ(qu)){
		if(b==1&&q>=n1)return;
		if(b==2&&q>=n2)return;
		auto x=qu.front(); qu.pop();
		if(vis[x])continue;
		vis[x]=b;
		q++;
		for(auto y:g[x])if(!vis[y])qu.push(y);
	}
}

int main(){FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		ll n,m; cin>>n1>>n2>>m; n=n1+n2;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll sw=0;
		if(n1>n2)swap(n1,n2),sw=1;
		fore(s,0,n){
			fore(i,0,n)random_shuffle(ALL(g[i]));
			mset(vis,0);
			q=0; b=1;
			bfs(s);
			q=0; b=2;
			fore(i,0,n)if(!vis[i]){
				bfs(i);
				break;
			}
			if(q>=n2){
				//cout<<"SI "<<s<<"\n";
				break;
			}
		}
		vector<ll> gr[3];
		fore(i,0,n)gr[vis[i]].pb(i);
		fore(h,1,3){
			ll hi=h;
			if(sw)hi=2-hi;
			for(auto i:gr[hi])cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
