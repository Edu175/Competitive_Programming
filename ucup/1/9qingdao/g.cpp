#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MOD=1e9+7,MAXN=105;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fn(ll n){return n*(n+1)/2;}

int main(){
	JET
	ll te; cin>>te;
	while(te--){
		ll n,m; cin>>n>>m;
		ll prev=0,maxz=0;
		vector<ii>ind;
		ll a[n+1];
		fore(i,0,n){
			cin>>a[i];
			if(a[i])ind.pb({i,a[i]});
			if(a[i]==1)maxz+=fn(i-prev),prev=i+1;
		}
		maxz+=fn(n-prev);
		a[n]=1,ind.pb({n,1});
		// for(auto i:ind)cout<<i<<" ";;cout<<"\n";
		// cout<<maxz<<"\n"; // ta bem
		ll dp[SZ(ind)+1][maxz+1]; mset(dp,0);
		dp[SZ(ind)][0]=1;
		for(ll i=SZ(ind)-1;i>=0;i--){
			ll s=i?ind[i-1].fst+1:0;
			fore(z,0,maxz+1){
				if(fn(n-s)<z)break;
				auto &res=dp[i][z];
				fore(j,i,SZ(ind)){
					ll c=fn(ind[j].fst-s);
					if(c>z)break;
					res=(ind[j].snd==2?sub:add)(res,dp[j+1][z-c]);
					if(ind[j].snd==1)break;
				}
			}
		}
		
		ll res=0;
		fore(z,0,maxz+1){
			ll c=dp[0][z];
			// cout<<z<<": "<<c<<"\n\n";
			res=add(res,mul(c,fpow(z,m)));
		}
		cout<<res<<"\n";
	}
	return 0;
}