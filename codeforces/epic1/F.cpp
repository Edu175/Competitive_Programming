#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef short ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=805;

bitset<MAXN> dp[MAXN][MAXN];
ll a[MAXN];
ll n;
ll g(ll l, ll r, ll b){
	// auto &res=dp2[l][r];
	if(dp[l][r].count(b))return dp[l][r][b];
	auto &res=dp[l][r][b];
	if(l==r)return res=1;
	if((r-l)&1)return res=0;
	
	auto can=[&](ll i){
		return a[i]!=-1&&a[i]<=a[b]+(i-b-1)/2;
	};
	if(!can(l))return res=0;
	if(g(l+1,r-1,l))return res=1;
	fore(m,l+1,r){
		if(/*can(m)&&*/g(l,m,b)&&g(m,r,b))return res=1;
	}
	// cout<<"g "<<l<<" "<<r<<" es 0\n";
	return res=0;
}
ll dp2[MAXN][MAXN];
ll f(ll i, ll s){
	auto &res=dp2[i][s];
	if(res!=-1)return res;
	if(i==n){
		return res=0;
	}
	res=f(i+1,s);
	if(a[i]!=-1&&a[i]<=s){
		fore(r,i+1,n){
			// cout<<i<<","<<r<<"?\n";
			ll d=(r-i+1)/2;
			if(g(i+1,r,i))res=max(res,ll(d+f(r+1,s+d)));
			// else cout<<"no\n";
		}
	}
	// cout<<"f "<<i<<" "<<s<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			ll x; cin>>x; x--;
			if(x>i||(x%2!=i%2))x=-1;
			else x=(i-x)/2;
			a[i]=x;
		}
		// fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
		/*ll j=0,s=0;
		while(j<n){
			ll did=0;
			if(a[j]!=-1&&a[j]<=s){
				for(ll i=n-1;i>j;i--){
					ll d=(i-j+1)/2;
					if(g(j+1,i,j)){
						s+=d,j=i+1;
						did=1;
						break;
					}
				}
			}
			if(!did)j++;
		}
		cout<<s<<"\n";*/
		fore(i,0,n+3)fore(j,0,n+3){
			dp[i][j].clear();
			dp2[i][j]=-1;
			//fore(k,0,n+3)/*dp[i][j][k]=*/dp2[i][j][k]=-1;
		}
		ll res=f(0,0);
		cout<<res<<"\n";
	}
	return 0;
}
