#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,cuca=b;i<cuca;i++)
#define SZ(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005;

vector<vector<ii>> g;

ll nl[MAXN],ccnt=0;
void dfs0(ll x, ll fa){
	ll p=-1;
	fore(i,0,SZ(g[x]))if(g[x][i].fst==fa)p=i;
	assert((p==-1) == (fa==-1));
	if(p!=-1)g[x].erase(g[x].begin()+p);
	for(auto [y,asd]:g[x])dfs0(y,x);
	nl[x]=ccnt++;
}

ll n;
ll greedy(ll diam){
	ll res=0;
	vv dp(n);
	vv got;
	fore(x,0,n){
		got={0};
		for(auto [y,w]:g[x]){
			ll &cur=dp[y];
			cur+=w;
			if(cur<=diam)got.pb(cur);
			else res++;
		}
		sort(ALL(got));
		ll u=SZ(got)-1; // ultimo
		for(;u>0&&got[u]+got[u-1]>diam;u--)res++;
		dp[x]=got[u];
	}
	// cerr<<"greedy "<<diam<<": "<<res<<"\n";
	return res;
}

ll ans[MAXN];

void rec(ll l, ll r, ll s, ll e){
	if(l>=r||s>=e)return;
	ll m=(l+r)/2;
	ll h=greedy(m);
	// cerr<<"rec "<<l<<","<<r<<" "<<s<<","<<e<<": "<<m<<" "<<h<<"\n";
	ans[h]=min(ans[h],m);
	rec(l,m,h,e);
	rec(m+1,r,s,h);
}

int main(){
	FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		g=vector<vector<ii>>(n);
		ccnt=0;
		ll sum=0;
		fore(i,0,n-1){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
			sum+=w;
		}
		dfs0(0,-1);
		auto _g=g;
		g.clear(); g.resize(n);
		fore(x,0,n){
			for(auto [y,w]:_g[x]){
				ll u=nl[x],v=nl[y];
				g[u].pb({v,w});
			}
		}
		_g.clear();
		fore(k,0,n)ans[k]=sum; // arranca de 0
		rec(0,sum+1,0,n); // arranca el segundo intervalo de 0
		fore(i,1,n)ans[i]=min(ans[i],ans[i-1]); // arranca de 1
		fore(k,1,n)cout<<ans[k]<<" ";
		cout<<"\n";
	}
}