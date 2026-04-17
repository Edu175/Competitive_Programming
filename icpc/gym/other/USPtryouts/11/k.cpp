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
const ll INF=1e8+5;
#define minig(a,b) a=min(a,b)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii> a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		// por resistance
		sort(ALL(a),[&](ii a, ii b){return a.snd<b.snd;});
		// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		vector<vv> dp(n+3,vv(n+3,INF));
		dp[0][0]=0;
		fore(i,0,n)fore(k,0,n+1){
			auto w=dp[i][k];
			if(w>=INF)continue;
			minig(dp[i+1][k],w);
			// lo elijo
			w+=a[i].fst;
			if(w<=a[i].snd)minig(dp[i+1][k+1],w);
			// cout<<i<<" "<<k<<": "<<dp[i][k]<<"\n";
		}
		ll res=0;
		fore(k,0,n+1)if(dp[n][k]<INF)res=k;
		cout<<res<<"\n";
	}
	return 0;
}
