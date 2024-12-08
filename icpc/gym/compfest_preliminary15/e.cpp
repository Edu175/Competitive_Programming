#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=305, INF=1e15;

ll v[MAXN];
ll av[MAXN];
ll cost[MAXN][MAXN][3];
ii req[MAXN];
ll n;

vv ps={0};
ll dp[MAXN][MAXN][MAXN];

ll f(ll i, ll j, ll k, ll idx){
	auto &res=dp[i][j][k];
	if(res!=-1)return res;
	if(idx==SZ(ps))return res=0;
	ll p=ps[idx];
	res=INF;
	if(av[p]>>0&1){
		res=min(res,cost[i][p][0]+f(p,j,k,idx+1));
	}
	if(av[p]>>1&1){
		res=min(res,cost[j][p][1]+f(i,p,k,idx+1));
	}
	if(av[p]>>2&1){
		res=min(res,cost[k][p][2]+f(i,j,p,idx+1));
	}
	return res;
}


int main(){
	JET
	ll skdjhf; cin>>skdjhf>>n;
	fore(i,1,n+1)cin>>v[i];
	av[0]=7; req[0]={1,1}; v[0]=INF;
	mset(dp,-1);
	fore(i,1,n+1){
		ll ty; cin>>ty;
		av[i]=av[i-1];
		if(ty==1){
			ll x,y; cin>>x>>y;
			req[i]={x,y};
			ps.pb(i);
		}
		else {
			ll p; cin>>p; p--;
			av[i]^=1<<p;
		}
	}
	
	fore(i,0,n+1)fore(j,i+1,n+1)fore(w,0,3)if(av[j]>>w&1){
		auto &res=cost[i][j][w];
		res=v[j];
		fore(k,i,j+1)if(av[k]>>w&1)res=min(res,v[k]);
		res=res*abs(req[i].snd-req[j].fst)
		+v[j]*abs(req[j].fst-req[j].snd);
	}
	
	ll res=f(0,0,0,1);
	cout<<res<<"\n";
	return 0;
}