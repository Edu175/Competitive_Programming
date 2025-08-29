#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

vv g[MAXN];

ll n;
vv bfs(vv s){
	vv d(n,-1);
	queue<ll>q;
	for(auto i:s)q.push(i),d[i]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}
ll deg(ll x){return SZ(g[x]);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv s;
		fore(x,0,n)if(deg(x)==1)s.pb(x);
		auto d=bfs(s);
		ll a=-1,b=-1,c=-1;
		ll mn=-1;
		fore(x,0,n)if(deg(x)>=3){
			vector<ii> cand;
			for(auto y:g[x])cand.pb({d[y],y});
			sort(ALL(cand));
			ll ci=cand[0].snd,ai=cand[1].snd,cur=cand[0].fst+cand[0].fst;
			if(mn==-1||cur<mn){
				mn=cur;
				a=ai+1,b=x+1,c=ci+1;
			}
		}
		cout<<a;
		if(a!=-1)cout<<" "<<b<<" "<<c;
		cout<<"\n";
	}
	return 0;
}