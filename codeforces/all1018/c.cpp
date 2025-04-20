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
const ll INF=1e15;
ll solve(vector<vv> a, vv b){
	ll n=SZ(a);
	vector<vv> ban(n,vv(4));
	fore(i,0,n){
		fore(j,0,n-1){
			ll d=a[i][j+1]-a[i][j];
			if(d==0)ban[j][0]=ban[j][3]=1;
			if(d==1)ban[j][2]=1;
			if(d==-1)ban[j][1]=1;
		}
	}
	// fore(i,0,n){
	// 	fore(j,0,4)cout<<ban[i][j];
	// 	cout<<" ";
	// 	// cout<<ban[i]<<" ";;cout<<"\n";
	// }cout<<"\n";
	// imp(b)
	vector<vv> dp(n+1,vv(2));
	for(ll i=n-1;i>=0;i--)fore(d,0,2){
		auto &res=dp[i][d];
		res=INF;
		fore(e,0,2){
			ll mk=2*d+e;
			if(i==0||!ban[i-1][mk])
				res=min(res,(e?b[i]:0)+dp[i+1][e]);
		}
		// cout<<i<<" "<<d<<": "<<res<<"\n";
	}
	return dp[0][0];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vv>a(n,vv(n));
		vv c0(n),c1(n);
		fore(i,0,n)fore(j,0,n)cin>>a[i][j];
		fore(i,0,n)cin>>c0[i];
		fore(i,0,n)cin>>c1[i];
		ll res=solve(a,c1);
		auto b=a;
		fore(i,0,n)fore(j,0,n)a[i][j]=b[n-1-j][i];
		reverse(ALL(c0));
		res+=solve(a,c0);
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
