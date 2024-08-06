#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e4+5;

vector<ll>g[MAXN];

ll c[MAXN];
ll bip=1;
void dfs(ll x, ll d){
	if(c[x]!=-1){
		if(c[x]!=d)bip=0;
		return;
	}
	c[x]=d;
	for(auto y:g[x]){
		dfs(y,d^1);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			c[i]=-1;
			g[i].clear();
		}
		bip=1;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)if(c[i]==-1)dfs(i,0);
		if(bip){
			cout<<"Bob"<<endl;
			queue<ll>q[2];
			fore(i,0,n)q[c[i]].push(i);
			vector<ll>res(n);
			auto say=[&](ll w, ll c){
				auto x=q[w].front(); q[w].pop();
				cout<<x+1<<" "<<c<<endl;
			};
			fore(i,0,n){
				ll a,b; cin>>a>>b;
				if(a>b)swap(a,b);
				if(a==1){
					if(SZ(q[0])){
						say(0,1);
					}
					else {
						say(1,b);
					}
				}
				else {
					if(SZ(q[1]))say(1,a);
					else say(0,b);
				}
			}
		}
		else {
			cout<<"Alice"<<endl;
			fore(i,0,n){
				cout<<"1 2"<<endl;
				ll dfgjh; cin>>dfgjh>>dfgjh;
			}
		}
	}
	return 0;
}
