#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=200005;

vector<int> g[MAXN];
ll nodos[MAXN];
ll parent[MAXN];
bool vis[MAXN];
vector<ll>ord={0};
void count_nodos(ll v){
	nodos[v]=1;
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			ord.pb(i);
			parent[i]=v;
			count_nodos(i);
			nodos[v]+=nodos[i];
		}
	}
}
ll x[MAXN];
void dfs(ll v){
	for(auto i:g[v]){
		if(i!=parent[v])dfs(i);
	}
	x[v]=0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll arr[n][3];
		fore(i,0,n-1){
			ll a,b; cin>>a>>b>>arr[i][2];
			a--,b--; 
			arr[i][0]=a;
			arr[i][1]=b;
			g[a].pb(b);
			g[b].pb(a);
		}
		count_nodos(0);
		fore(i,0,n-1){
			if(parent[arr[i][1]]==arr[i][0])x[arr[i][1]]=arr[i][2];
			else x[arr[i][0]]=arr[i][2];
		}
		/*fore(i,0,n){
			cout<<i<<": ";
			for(auto j:g[i])cout<<j<<" ";
			cout<<"\n";
		}
		fore(i,0,n)cout<<nodos[i]<<" ";
		cout<<"\n";*/
		/*fore(i,1,n)cout<<x[i]<<" ";
		cout<<"\n";*/
		vector<ll> block;
		for(auto i:ord){
			if(x[i]){
				dfs(i);
				x[i]=1;
			}
		}
		fore(i,1,n)cout<<x[i]<<" ";
		cout<<"\n";
		fore(i,1,n)if(x[i])block.pb(nodos[i]);
		sort(ALL(block));
		reverse(ALL(block));
		ll res=0;
		for(auto i:block){
			if(k<=0){
				break;
			}
			k-=i;
			res++;
		}
		/*for(auto i:block)cout<<i<<" ";
		cout<<"\n";*/
		if(k>0)cout<<-1<<"\n";
		else cout<<res<<"\n";
		fore(i,0,n)vis[i]=0,g[i].clear();
		ord.clear();
	}
	return 0;
}
