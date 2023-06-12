#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef int ll;

const int MAXN=300005;

vector<int> g[MAXN];
pair<ll,ll> sp={MAXN,5};
bool vis[MAXN];
ll d[MAXN];

void bfs(int x){
	queue<int> q;
	q.push(x);
	vis[x]=1;
	d[x]=1;
	while(SZ(q)){
		auto f=q.front();
		q.pop();
		//cout<<f+1<<" ";
		for(auto i:g[f]){
			if(!vis[i]){
				q.push(i);
				vis[i]=i;
				d[i]=d[f]+1;
				if(SZ(g[i])<=2){
					if(sp.fst>=d[i]){
						sp.fst=d[i];
						sp.snd=min(sp.snd,SZ(g[i])-1);
					}
				}
			}
		}
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n-1){
			ll a,b; cin>>a>>b;
			a--; b--;
			g[a].pb(b);
			g[b].pb(a);
		}
		//fore(i,0,n)imp(g[i]);
		bfs(0);
		if(SZ(g[0])==1)cout<<n-2<<"\n";
		else cout<<n-sp.fst*2+(sp.snd^1)<<"\n";
		sp.fst=MAXN; sp.snd=5;
		fore(i,0,n)vis[i]=0,g[i].clear();
	}
	return 0;
}
