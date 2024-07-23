#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b),e>>=1;
	}
	return r;
}
int main(){JET
	ll n,k; cin>>n>>k;
	vector<ll>ds,ps;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ds.pb(i),ds.pb(n/i);
		if(i*i==n)ds.pop_back();
	}
	sort(ALL(ds));
	ll ni=n;
	for(ll i=2;i*i<=ni;i++){
		ll c=0;
		while(ni%i==0)c++,ni/=i;
		if(c)ps.pb(i);
	}
	if(ni>1)ps.pb(ni);
	ll m=SZ(ds);
	vector<vector<ll>>cr(m);
	fore(j,0,m)for(auto p:ps)if(SZ(cr[j])<2){
		ll d=ds[j];
		if(d%p==0)cr[j].pb(p);
	}
	
	vector<ll>ant0(m,-1),ant1(m,-1),ant2(m,-1),inv(m,1);
	fore(i,0,m){
		ll d=ds[i];
		for(auto p:ps){
			ll c=0;
			while(d%p==0)c++,d/=p;
			inv[i]*=c+1;
		}
		cerr<<ds[i]<<": "<<inv[i]<<"\n";
		inv[i]=fpow(inv[i],MOD-2);
		
	}
	fore(i,0,m){
		if(SZ(cr[i])){
			ll v=ds[i]/cr[i][0];
			cerr<<"ant0 "<<ds[i]<<"->"<<v<<"\n";
			ant0[i]=lower_bound(ALL(ds),v)-ds.begin();
		}
		if(SZ(cr[i])>1){
			ll v=ds[i]/cr[i][1];
			ant1[i]=lower_bound(ALL(ds),v)-ds.begin();
			
			v=ds[i]/cr[i][0]/cr[i][1];
			ant2[i]=lower_bound(ALL(ds),v)-ds.begin();
		}
	}
	for(auto i:ds)cerr<<i<<" ";;cerr<<"\n";
	// fore(i,0,m){
	// 	cout<<i<<" ("<<ds[i]<<"): ";
	// 	for(auto j:cr[i])cout<<j<<",";
	// 	cout<<"\n";
	// }
	for(auto i:ant0)cerr<<(i==-1?"-":to_string(i))<<" ";;cerr<<"\n";
	for(auto i:ant1)cerr<<(i==-1?"-":to_string(i))<<" ";;cerr<<"\n";
	for(auto i:ant2)cerr<<(i==-1?"-":to_string(i))<<" ";;cerr<<"\n";
	for(auto i:inv)cerr<<i<<" ";;cerr<<"\n";
	vector<vector<ll>>dp(2,vector<ll>(m));
	fore(i,0,m)dp[1][i]=ds[i];
	fore(i,0,k){
		ll w=i&1;
		fore(j,0,m){
			ll d=ds[j];
			ll &res=dp[w][j];
			if(!SZ(cr[j])){
				res=dp[w^1][j];
			}
			else if(SZ(cr[j])==1){
				res=add(dp[w^1][j],dp[w][ant0[j]]);
			}
			else {
				res=add(dp[w^1][j],sub(add(dp[w][ant0[j]],dp[w][ant1[j]]),dp[w][ant2[j]]));
			}
		}
		fore(j,0,m)dp[w][j]=mul(dp[w][j],inv[j]);
	}
	cout<<dp[(k-1)&1][m-1]<<"\n";
}