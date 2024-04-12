#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const LL MAXN=1e5+5,K=17;
#define SQSIZE 50//sqrt(cnt*log2(cnt))//1288
ll F[K][MAXN],w[MAXN],sz[MAXN];
LL D[MAXN];
map<ii,ll>mp;
ii amp[MAXN];
vector<vector<ii>>a(MAXN);
ll cv(ii a){return mp[a];}
ii cv(ll x){
	return a[amp[x].fst][amp[x].snd];
}

int main(){FIN;
	ll n; LL t; cin>>n>>t;
	ll cnt=0;
	fore(i,0,n-1){
		ll m; cin>>m;
		fore(_,0,m){
			ll l,r; cin>>l>>r;
			a[i].pb({l,-r});
		}
		sort(ALL(a[i]));
		vector<ii>b;
		for(auto [l,r]:a[i]){
			r=-r;
			while(SZ(b)&&b.back().snd>=r)b.pop_back();
			b.pb({l,r});
		}
		a[i]=b;
		fore(j,0,SZ(a[i]))mp[{i,j}]=cnt,amp[cnt]={i,j},cnt++;
	}
	F[0][cnt]=cnt;
	//cerr<<cnt<<"\n";
	for(ll i=n-2;i>=0;i--)fore(j,0,SZ(a[i])){
		ll x=cv({i,j});
		if(i==n-2)F[0][x]=cnt;
		else {
			ll r=a[i][j].snd;
			auto lwb=lower_bound(ALL(a[i+1]),ii({r,-1}));
			if(lwb==a[i+1].end())lwb=a[i+1].begin();
			F[0][x]=cv({i+1,lwb-a[i+1].begin()});
			w[x]=(lwb->fst-r+t)%t;
		}
		sz[x]=a[i][j].snd-a[i][j].fst;
		w[x]+=sz[x];
		D[x]=D[F[0][x]]+w[x];
	}
	ll C=SQSIZE;
	//cout<<C<<"\n";
	vector<LL>qs[n];
	fore(i,0,n)if(SZ(a[i])>=C){
		//cout<<i<<" entro\n";
		qs[i].resize(n-i);
		qs[i][i-i]=0;
		vector<ll>v;
		vector<LL>mn(cnt+1,t*n*10);
		vector<bool> vis(cnt+1,0);
		fore(j,0,SZ(a[i])){
			ll x=cv({i,j});
			v.pb(x);
			mn[x]=0;
		}
		fore(k,i,n-1){
			vector<ll>vi;
			LL &res=qs[i][k+1-i];
			res=t*n*10;
			//cout<<k<<": "; imp(v);
			for(auto x:v){
				ll p=F[0][x];
				mn[p]=min(mn[p],mn[x]+w[x]);
				res=min(res,mn[x]+sz[x]);
				if(!vis[p])vis[p]=1,vi.pb(p);
			}
			v=vi;
			//cout<<res<<"\n";
		}
		//cout<<"fin ";imp(mn);
	}
	fore(k,1,K)fore(x,0,cnt+1){
		F[k][x]=F[k-1][F[k-1][x]];
	}
	ll q; cin>>q;
	while(q--){
		ll s,e; cin>>s>>e; s--,e--;
		LL ans=-1;
		if(SZ(a[s])>=C)ans=qs[s][e-s];
		else {
			fore(h,0,SZ(a[s])){
				ll x=cv({s,h}),p=s;
				LL res=D[x];
				for(ll k=K-1;k>=0;k--)if(p+(1<<k)<e)x=F[k][x],p+=1<<k;
				res+=-D[x]+cv(x).snd-cv(x).fst;
				if(ans==-1||res<ans)ans=res;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
