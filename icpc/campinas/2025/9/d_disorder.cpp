#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3005,MAXT=155,INF=1e12;

vv g[MAXN];

ll n;
vv bfs(ll s){
	vv d(n,-1);
	d[s]=0;
	queue<ll>q; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}
vv d[MAXN];

int main(){
	JET
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll l; cin>>l;
	vv P(l);
	fore(i,0,l)cin>>P[i],P[i]--;
	ll b; cin>>b;
	vv T(b);
	fore(i,0,b)cin>>T[i],T[i]--;
	fore(i,0,n)d[i]=bfs(i);
	
	vector<vv> dp(b+3,vv(l+3));
	for(ll p=l-1;p>=0;p--){
		fore(t,0,b){
			auto &res=dp[p][t];
			ll dif=0;
			multiset<ii>st;
			multiset<ll>cs;
			auto put=[&](ii a){
				a.fst-=dif; a.snd-=dif;
				st.insert(a);
				cs.insert(a.snd);
			};
			auto add=[&](ll del){
				dif+=del;
				while(SZ(st)&&st.rbegin()->fst+dif>k){
					cs.erase(st.rbegin()->snd);
					st.erase(prev(st.end()));
				}
			};
			auto get=[&](){return !SZ(cs)?INF:*cs.begin();};
			
		}
		
		
	}
	
	
	
	
	for(ll i=l-1;i>=0;i--)fore(c,0,k+1){
		auto &res=dp[i][c];
		ll ci=go(i,c);
		if()
	}
	
	return 0;
}