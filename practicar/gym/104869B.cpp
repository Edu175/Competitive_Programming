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
const ll MAXN=24,INF=ll(2e18)+100;

ll dp[1ll<<MAXN];

ll add(ll a, ll b){
	return min(a+b,INF);
}

int main(){FIN;
	ll n,k; cin>>n>>k; k--;
	ll N=min(MAXN,n);
	if(n-N&&(n-N)%2==0)N--;
	ll C=n-N;
//	cout<<N<<" "<<C<<"\n";
	dp[(1ll<<N)-1]=1;
	auto valid=[&](ll mk, ll x){
		if(x==N-1)return true;
		if(x==0)return (!C||(mk>>(x+1)&1));
		return !((mk>>(x-1)&1)^(mk>>(x+1)&1)); //xor == 0
	};
	for(ll mk=(1ll<<N)-1;mk>=0;mk--){
		ll &res=dp[mk];
		fore(x,0,N)if(!(mk>>x&1)){
			if(valid(mk,x))res=add(res,dp[mk|(1ll<<x)]);
		}
//		cout<<mk<<": "<<res<<"\n";
	}
//	cout<<dp[0]<<"\n"<<INF<<"\n";
	ll mk=0;
	vector<ll>ans;
	fore(i,0,n){
		if(n-i>N)ans.pb(i);
		else {
//			if(C==-1)C=i;
			fore(x,0,N)if(!(mk>>x&1)&&valid(mk,x)){
				
				ll w=dp[mk|(1ll<<x)];
				if(k<w){
					mk|=1ll<<x;
					ans.pb(x+C);
					break;
				}
				k-=w;
			}
		}
	}
	fore(i,1,C)if(i&1)swap(ans[i],ans[i+1]);
	if(SZ(ans)==n){
		for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	}
	else cout<<"-1\n";
	return 0;
}
