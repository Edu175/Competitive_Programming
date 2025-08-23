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
const ll MAXN=2e6+5;

vector<ll> g[MAXN];

ll d[MAXN];
void bfs(ll s){
	//cout<<"bfs\n";
	queue<ll>q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}

int main(){FIN;
	ll n;
	while(cin>>n){
		map<string,ll>mp;
		//vector<string>pm;
		vector<string> a[n];
		fore(i,0,n){
			string s; cin>>s;
			ll m; cin>>m;
			a[i].resize(m);
			fore(j,0,m)cin>>a[i][j],mp[a[i][j]]=-1;
		}
		ll cnt=0;
		for(auto &i:mp){
			i.snd=cnt++;
			//pm.pb(i.fst);
		}
		fore(i,0,cnt){
			g[i].clear();
			d[i]=-1;
		}
		fore(i,0,n){
			vector<ll>b;
			fore(j,0,SZ(a[i]))b.pb(mp[a[i][j]]);
			fore(j,0,SZ(b))fore(k,j+1,SZ(b)){
				ll u=b[j],v=b[k];
				g[u].pb(v);
				g[v].pb(u);
			}
		}
		string kvn="KevinBacon";
		if(mp.count(kvn))bfs(mp[kvn]);
		ll q; cin>>q;
		while(q--){
			string s; cin>>s;
			ll res=d[mp[s]];
			cout<<s<<" ";
			if(res==-1)cout<<"INF\n";
			else cout<<res<<"\n";
		}
		cout<<"---\n";
	}
	return 0;
}
