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
#define ft gr[g[v][0]]
#define sd gr[g[v][1]]
using namespace std;
typedef long long ll;

const int MAXN=200005;

vector<int> g[MAXN];
bool flag=1;
bool vis[MAXN];
short gr[MAXN];

void dfs(ll v){
	//cout<<v<<"\n";
	if(vis[v]==0){
		vis[v]=1;
		if(SZ(g[v])>2)flag=0;
		else if(SZ(g[v])==2){
			//cout<<g[v][0]<<" "<<g[v][1];
			//cout<<" | "<<ft<<" "<<sd;
			if(ft==3||sd==3)flag=0;
			else{
				if(g[v][0]==g[v][1]){
					if(ft)flag=0;
					else ft=3;
				}
				else {
					if(ft>0||sd>0){
						if(ft==sd)flag=0;
						else if(ft>0&&sd==0)sd=3-ft;
						else if(sd>0&&ft==0)ft=3-sd;
					}
					else ft=1,sd=2;
				}
				for(auto i:g[v]){
					if(!vis[i])/*cout<<i<<"\n",*/dfs(i);
				}
				//cout<<" | "<<ft<<" "<<sd<<"\n";
			}
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			ll a,b; cin>>a>>b;
			a--,b--;
			g[a].pb(b);
			g[b].pb(a);
			if(a==b)flag=0;
		}
		fore(i,0,n)dfs(i);
		/*fore(i,0,n){
			cout<<i<<": ";
			for(auto j:g[i])cout<<j<<" ";
			cout<<"\n";
		}*/
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
		/*fore(i,0,n)cout<<gr[i]<<" ";
		cout<<"\n";*/
		flag=1;
		fore(i,0,n)vis[i]=0,gr[i]=0,g[i].clear();
	}
	return 0;
}
