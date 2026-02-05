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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;

vv g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		vv deg(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
			deg[u]++;deg[v]++;
		}
		ll mxd=*max_element(ALL(deg));
		vv fa(n,-1),he(n);
		queue<ll> q;
		fore(i,0,n)if(deg[i]==1)q.push(i);
		ll qued=n;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			ll cnt=0;
			qued--;
			deg[x]=-1;
			for(auto y:g[x])if(deg[y]!=-1&&!(qued==1&&he[x]==he[y])){
				if(--deg[y]==1)q.push(y);
				he[y]=max(he[y],he[x]+1);
				fa[x]=y;
				cnt++;
			}
			assert(cnt<=1);
		}
		ll uno=count(ALL(fa),-1)==1;
		vector<vv> wh(n);
		fore(i,0,n)if(fa[i]!=-1)wh[he[i]].pb(i);
		// fore(i,0,n)cout<<i<<": "<<he[i]<<" "<<fa[i]<<"\n";
		ll cnt=n-1;
		vv ans(n+1,2*n+5);
		for(ll h=n-1;h>=0;h--){
			auto &v=wh[h];
			if(!SZ(v))continue;
			assert(SZ(v)>=2);
			ans[cnt]=2*(h+1)+1; // same except borders
			// cerr<<"h "<<h<<": ";
			// cerr<<cnt<<","<<2*(h+1)+1<<" ";
			map<ll,ll>mp;
			for(auto i:v)mp[fa[i]]++;
			vector<ii> sd;
			for(auto [x,d]:mp)sd.pb({d,x});
			sort(ALL(sd));
			fore(i,0,SZ(sd)-1)cnt-=sd[i].fst;
			// cerr<<cnt<<","<<2*(h+1)<<" ";
			ans[cnt]=2*(h+1);
			ll d=sd.back().fst;
			cnt-=d;
			if(uno)cnt++,uno=0;
			ans[cnt]=2*(h+1)-1; // same except borders
			// cerr<<cnt<<","<<2*(h+1)-1<<"\n";
			// impr(sd)
		}
		// cerr<<cnt<<" cnt\n";
		assert(cnt==1);
		ans[mxd]=2; // n>=2
		for(ll i=n-1;i>=0;i--)ans[i]=min(ans[i],ans[i+1]);
		fore(i,1,n)cout<<ans[i]<<" ";;cout<<"\n";
		// cerr<<"\n";
	}
	return 0;
}
