#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

vector<pair<ii,ll>> c;
vi ins[1005];
vi ins1[1005];

ll rp (ll a){
	ll rta=sqrt(a);
	rta-=2;
	while(rta*rta<=a){
		rta++;
	}
	return rta-1;
}

ll dist(ll a, ll b){
	
	return rp((c[a].fst.fst-c[b].fst.fst)*(c[a].fst.fst-c[b].fst.fst)+(c[a].fst.snd-c[b].fst.snd)*(c[a].fst.snd-c[b].fst.snd));
	
}

int dp[1005];

bool f0 (int a){
	if(dp[a]!=-1) return dp[a];
	else{
		if(c[a].fst.fst-c[a].snd<=0) dp[a]=0;
		else{
			dp[a]=1;
			for(auto x : ins[a]){
				dp[a]=f0(x)*dp[a];
			}
		}
		return dp[a];
	}
}

int dp1[1005];

bool f1 (int a){
	if(dp1[a]!=-1) return dp1[a];
	else{
		if(c[a].fst.snd-c[a].snd<=0) dp1[a]=0;
		else{
			dp1[a]=1;
			for(auto x : ins1[a]){
				dp1[a]=f1(x)*dp1[a];
			}
		}
		return dp1[a];
	}
}

int main(){
	FIN
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,k){
		ll a,b,d;
		cin>>a>>b>>d;
		c.pb({{a,b},d});	
	}
	mset(dp,-1);
	mset(dp1,-1);
	fore(i,0,k)fore(j,0,k){
		if(c[i].fst.fst<c[j].fst.fst && dist(i,j)<=(c[i].snd+c[j].snd)){
			ins[j].pb(i);
		}
		if(c[i].fst.snd<c[j].fst.snd && dist(i,j)<=(c[i].snd+c[j].snd)){
			ins1[j].pb(i);
		}
	}
	fore(i,0,k){
		f0(i);
		f1(i);
		if((dp[i]==0 && c[i].fst.fst+c[i].snd>=m )|| (dp1[i]==0 && c[i].fst.snd+c[i].snd>=n)){
			cout<<"N\n";
			return 0;
		}	
	}	
	cout<<"S\n";
	return 0;
} 