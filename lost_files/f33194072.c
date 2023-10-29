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
typedef long long ll;

const int MAXN=10005;
vector<int> g[MAXN];
bool vis[MAXN];
ll e;
ll res=0;
ll t=0;
void dfs(ll v){
	vis[v]=1;
	//cout<<v<<" ";
	t++;
	for(auto i:g[v]){
		if(!vis[i]){
			if(i==e)res++;//,cout<<res<<"\n";
			else dfs(i);
		}
	}
	vis[v]=0;
}


int main(){
	cout<<"Tamaño del tablero: ";
	ll n; cin>>n;
	ll s=n*(n-1)+n/2;
	e=n/2;
	fore(i,0,n){
		fore(j,0,n){
			if(i){
				g[n*i+j].pb((i-1)*n+j);
				g[n*(i-1)+j].pb(i*n+j);
				if(j){
					g[n*i+j].pb(n*(i-1)+j-1);
					g[n*(i-1)+j-1].pb(n*i+j);
				}
				if(j<n-1){
					g[n*i+j].pb(n*(i-1)+j+1);
					g[n*(i-1)+j+1].pb(n*i+j);
				}
			}
		}
	}
	dfs(s);
	/*fore(i,0,n*n){
		cout<<i<<": ";
		for(auto j:g[i])cout<<j<<" ";
		cout<<"\n";
	}*/
	//cout<<"\n";
	cout<<"Cantidad de caminos: "<<t<<"\nCantidad de caminos posibles: "<<res<<"\n";
	return 0;
}
