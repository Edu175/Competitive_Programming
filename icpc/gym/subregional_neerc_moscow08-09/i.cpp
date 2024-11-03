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
const ll MAXV=1e4+5;

ll m0,m1;
vv solve(vector<ii> a, ll L){
	// cout<<"\nsolve ";
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<" | "<<L<<"\n";
	ll n=SZ(a);
	vector<ii> h[MAXV];
	fore(i,0,n)h[a[i].fst].pb({a[i].snd,i});
	vector<vector<int>>dp(L+5,vector<int>(4));
	dp[L][3]=1;
	for(ll i=L-1;i>=0;i--)fore(mk,0,4){
		auto &res=dp[i][mk];
		for(auto [r,j]:h[i]){
			ll mki=mk;
			if(j==m0)mki|=1;
			if(j==m1)mki|=2;
			res|=dp[r][mki];
		}
		// cout<<i<<": "<<dp[i][mk]<<"\n";
	}
	if(!dp[0][0])return {};
	vv ret;
	ll x=0,mk=0;
	while(x<L){
		for(auto [r,j]:h[x]){
			ll mki=mk;
			if(j==m0)mki|=1;
			if(j==m1)mki|=2;
			if(dp[r][mki]){
				ret.pb(j);
				x=r; mk=mki;
				break;
			}
		}
	}
	assert(mk==3);
	return ret;
}


int main(){
	JET
	ll x,y; cin>>x>>y;
	ll n; cin>>n;
	vector<ii> xs(n),ys(n);
	fore(i,0,n){
		cin>>xs[i].fst>>ys[i].fst>>xs[i].snd>>ys[i].snd;
	}
	cin>>m0>>m1; m0--,m1--;
	auto gox=solve(xs,x);
	auto goy=solve(ys,y);
	if(SZ(gox)){
		cout<<SZ(gox)<<"\n";
		for(auto i:gox)cout<<i+1<<" ";;cout<<"\n";
	}
	else if(SZ(goy)){
		cout<<SZ(goy)<<"\n";
		for(auto i:goy)cout<<i+1<<" ";;cout<<"\n";
	}
	else cout<<"-1\n";
	return 0;
}


/*

solve 2,4 3,4 1,3 1,4 1,2 0,1 0,1  | 4
3: 1
2: 1
1: 1
0: 1

solve 0,1 1,3 1,3 3,4 0,1 0,2 2,4  | 4
3: 1
2: 1
1: 1
0: 1
3
6 5 1 


*/