#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define bint __int128
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
bint pm(bint b, ll e){
	bint res=1;
	fore(i,0,e)res*=b;
	return res;
}
ll root(ll k, ll x){ // floor
	ll l=1,r=sqrt(x)+10;
	while(l<=r){
		ll m=(l+r)/2;
		if(pm(m,k)<=x)l=m+1;
		else r=m-1;
	}
	return r;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a;
	map<ll,ll>pr,oc;
	fore(i,0,n){
		ll x; cin>>x;
		if(!oc[x]++)a.pb(x);
	}
	n=SZ(a);
	ll res=1;
	fore(i,0,n){
		ll flag=0,x=a[i];
		for(ll k=4;k>=2;k--){
			ll r=root(k,x);
			// cout<<i<<": "<<x<<" "<<k<<": "<<r<<"\n";
			if(pm(r,k)==x){
				pr[r]+=k*oc[x];
				flag=1;
				// cout<<i<<": "<<x<<" "<<k<<"\n";
				break;
			}
		}
		if(!flag){
			fore(j,0,n)if(i!=j){
				ll d=gcd(x,a[j]);
				if(d>1){
					pr[d]+=oc[x],pr[x/d]+=oc[x],flag=1;
					break;
				}
			}
			if(!flag)res=mul(res,mul(oc[x]+1,oc[x]+1));
		}
	}
	// cout<<"res "<<res<<"\n";
	for(auto [i,c]:pr){
		// cout<<i<<","<<c<<"\n";
		res=mul(res,c+1);
		
	}
	cout<<res<<"\n";
	return 0;
}