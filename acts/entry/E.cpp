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
const ll MAXN=1005;
vector<ll>g[MAXN];
ll d[MAXN];

void bfs(ll x){
	mset(d,-1);
	d[x]=0;
	queue<ll>q;
	q.push(x);
	while(SZ(q)){
		x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			q.push(y);
			d[y]=d[x]+1;
		}
	}
}

int main(){FIN;
	ll n,s; cin>>n>>s; s--;
	fore(i,0,n){
		ll m; cin>>m;
		fore(_,0,m){
			ll x; cin>>x; x--;
			g[i].pb(x);
		}
	}
	bfs(s);
	ll mx=0;
	fore(i,0,n)mx=max(mx,d[i]);
	vector<ll>res;
	fore(i,0,n)if(d[i]==mx)res.pb(i+1);
	cout<<mx<<"\n";
	imp(res);
	return 0;
}
