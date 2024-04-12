#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,K=17;

ll F[K][MAXN],D[MAXN];
map<ii,ll>mp;
ii amp[MAXN];
vector<vector<ii>>a(MAXN);
ll cv(ii a){return mp[a];}
ii cv(ll x){
	return a[amp[x].fst][amp[x].snd];
}

int main(){FIN;
	ll n,t; cin>>n>>t;
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
		//for(auto j:a[i])cout<<j.fst<<","<<j.snd<<" ";;cout<<"\n";
	}
	//a[n].pb({0,0});
	//mp[a[n][0]]=cnt
	F[0][cnt]=cnt;
	for(ll i=n-2;i>=0;i--)fore(j,0,SZ(a[i])){
		ll x=cv({i,j});
		if(i==n-2)F[0][x]=cnt;
		else {
			ll r=a[i][j].snd;
			auto lwb=lower_bound(ALL(a[i+1]),ii({r,-1}));
			if(lwb==a[i+1].end())lwb=a[i+1].begin();
			F[0][x]=cv({i+1,lwb-a[i+1].begin()});
			D[x]=D[F[0][x]]+(lwb->fst-r+t)%t;
		}
		D[x]+=a[i][j].snd-a[i][j].fst;
		//cout<<i<<","<<j<<": "<<x<<" ("<<cv(x).fst<<","<<cv(x).snd<<"): "<<D[x]<<" "<<F[0][x]<<"\n";
	}
	fore(k,1,K)fore(x,0,cnt+1){
		F[k][x]=F[k-1][F[k-1][x]];
	}
	ll q; cin>>q;
	while(q--){
		ll s,e; cin>>s>>e; s--,e--;
		ll ans=-1;
		fore(h,0,SZ(a[s])){
			ll x=cv({s,h}),res=D[x],p=s;
			for(ll k=K-1;k>=0;k--)if(p+(1ll<<k)<e)x=F[k][x],p+=1ll<<k;
			//while(p+1<e)x=F[0][x],p++;
			res+=-D[x]+cv(x).snd-cv(x).fst;
			//cout<<s<<" "<<e<<": "<<x<<"\n";
			if(ans==-1||res<ans)ans=res;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
