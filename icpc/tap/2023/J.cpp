#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll> g[MAXN];

ll d[2][MAXN];
ll s[2];
void bfs(ll w){
	queue<ll>q;
	q.push(s[w]);
	mset(d[w],-1);
	d[w][s[w]]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[w][y]==-1){
			d[w][y]=d[w][x]+1;
			q.push(y);
		}
	}
}

ll cnt[MAXN][2];
ll cru[MAXN],out[MAXN];
ll res=0,k;

void take(ll x){
	if(res==-1)return;
	out[x]=1;
	cru[d[0][x]]--;
	if(cru[d[0][x]]==0){
		res=-1;
		return;
	}
	else if(cru[d[0][x]]==1)res++;
	for(auto y:g[x])if(!out[y]){
		if(d[0][x]+1==d[0][y]){
			cnt[y][0]--;
			if(cnt[y][0]==0)take(y);
		}
		else if(d[1][x]+1==d[1][y]){
			cnt[y][1]--;
			if(cnt[y][1]==0)take(y);
		}
	}
}

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	s[0]=0,s[1]=n-1;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,2)bfs(i);
	k=d[0][n-1];
	fore(x,0,n){
		if(d[0][x]+d[1][x]==k){
			cru[d[0][x]]++;
			for(auto y:g[x]){
				if(d[0][y]+1==d[0][x])cnt[x][0]++;
				if(d[1][y]+1==d[1][x])cnt[x][1]++;
			}
		}
		else out[x]=1;
	}
	fore(i,1,k)if(cru[i]==1)res++;
	cout<<res<<" ";
	while(q--){
		ll p; cin>>p; p--;
		if(res==-1){
			cout<<"-1 ";
			continue;
		}
		if(!out[p])take(p);
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}
