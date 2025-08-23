#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=105,MAXS=1005;


ii Max(ii a, ii b){
	a.fst*=-1; b.fst*=-1;
	if(a<b){
		a.fst*=-1;
		return a;
	}
	b.fst*=-1;
	return b;
}

int main(){
	JET
	ll n,maxT; cin>>n>>maxT;
	vv t(n),p(n);
	fore(i,0,n)cin>>t[i]>>p[i];
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){
		return t[i]*p[j] < t[j]*p[i];
	});
	vector<vector<ii>> dp(n+5,vector<ii>(maxT+3,{0,0}));
	for(ll i=n-1;i>=0;i--)fore(s,0,maxT+3){
		ll x=per[i];
		auto &res=dp[i][s];
		res=dp[i+1][s];
		// cout<<i<<" "<<s<<": ";
		if(s+t[x]<=maxT){
			ii go=dp[i+1][s+t[x]];
			go.fst+=p[x];
			go.snd+=(s+t[x])*p[x];
			res=Max(res,go);
		}
	}
	auto cost=[&](vv sol){
		ll j=0,s=0;
		ii res={0,0};
		for(auto x:per){
			if(j<SZ(sol)&&x==sol[j]){
				s+=t[x];
				res.fst+=p[x];
				res.snd+=t[x]*p[x];
				j++;
			}
		}
		assert(j==SZ(sol));
		cout<<"cost ";
		for(auto i:sol)cout<<i<<" ";
		cout<<"= "<<res.fst<<","<<res.snd<<"\n";
	};
	// for(auto i:per)cout<<i<<" ";;cout<<"\n";
	// cost({4,0,2});
	// cost({3,1});
	// ii ans=dp[0][0];
	// cerr<<"Respuesta "<<ans.fst<<","<<ans.snd<<"\n";
	vv sol;
	ll s=0;
	fore(i,0,n){
		ll x=per[i];
		ll voy=dp[i][s]!=dp[i+1][s];
		// ll voy=0;
		
		//dbg
		// ii go={-1,-1};
		// if(s+t[x]<=maxT){
		// 	go=dp[i+1][s+t[x]];
		// 	go.fst+=p[x];
		// 	go.snd+=(s+t[x])*p[x];
		// 	// if(dp[i][s]==go)voy=1;
		// }
		// //dbg
		
		// cout<<i<<" "<<s<<": "<<dp[i+1][s].fst<<","<<dp[i+1][s].snd<<" vs "<<go.fst<<","<<go.snd<<": "<<voy<<"\n";
		if(voy){
			sol.pb(x);
			s+=t[x];
		}
	}
	cout<<SZ(sol)<<"\n";
	for(auto i:sol)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}


/*


4 3 1 0 2 
cost 4 0 2 = 180,9000
cost 3 1 = 180,12600
Respuesta 180,18550
0 0: 180,18550 vs 180,19217: 0
1 0: 145,13150 vs 180,18550: 1
2 70: 60,7200 vs 85,11900: 1
3 140: 0,0 vs -1,-1: 0
4 140: 0,0 vs -1,-1: 0
2
4 2 



*/