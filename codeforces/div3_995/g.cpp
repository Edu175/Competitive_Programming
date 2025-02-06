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
const ll N=20,INF=1e10;

ll cost[N][N];
ll dp[1ll<<N][N];
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<pair<ll,char>> ops[n];
	vv rs(n);
	fore(i,0,q){
		ll p; char ty; cin>>p>>ty;
		p--;
		ops[p].pb({i,ty});
		if(ty=='+')rs[p]++;
	}
	fore(i,0,n)fore(j,0,n)if(i!=j){
		ll r=0,l=0;
		auto &res=cost[i][j];
		ll p=0,q=0;
		
		auto &v=ops[i];
		auto &w=ops[j];
		// cout<<"cost "<<i<<" "<<j<<":\n";
		// impr(v)
		// impr(w)
		while(p<SZ(v)||q<SZ(w)){
			ll go=0;
			if(p==SZ(v))go=1;
			else if(q!=SZ(w)&&w[q]<v[p])go=1;
			if(!go){
				if(v[p++].snd=='+')r++;
			}
			else if(w[q++].snd=='-')l--;
			// cout<<p<<" "<<q<<": "<<l<<" "<<r<<"\n";
			res=max(res,l+r);
		}
		// cout<<res<<"\n\n";
	}
	fore(x,0,n){
		dp[(1ll<<n)-1][x]=rs[x];
	}
	
	for(ll mk=(1ll<<n)-2;mk>0;mk--)fore(x,0,n)if(mk>>x&1){
		auto &res=dp[mk][x];
		res=INF;
		fore(y,0,n)if(!(mk>>y&1))
			res=min(res,cost[x][y]+dp[mk|(1ll<<y)][y]);
	}
	
	ll res=INF;
	fore(x,0,n)res=min(res,dp[1ll<<x][x]);
	
	res+=n;
	cout<<res<<"\n";
	
	return 0;
}
