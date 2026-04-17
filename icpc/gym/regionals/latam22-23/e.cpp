#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

ll get(ll a, ll b, ll c, ll n){
	bitset<MAXN> dp; dp[0]=1;
	fore(i,1,n+1)if(i!=b&&i!=c)dp|=dp<<i;
	ll res=0;
	fore(i,0,a+1)if(dp[i])res=i;
	return a-res;
}

int main(){
	ET
	ll n,k,e; cin>>n>>k>>e;
	ll a=e,b=n-e-k;
	if(a>b)swap(a,b);
	if(a!=b&&b!=k&&a!=k){
		cout<<"0\n";
		return 0;
	}
	vv v={a,b,k}; sort(ALL(v));
	a=v[0],b=v[1];
	ll c=v[2];
	if(a==c){
		if(k>=5)cout<<"0\n";
		else {
			ll res=2*k;
			vv v(k-1); iota(ALL(v),1);
			do{
				ll a=0,b=0;
				for(auto i:v){
					if(a+i<=k)a+=i;
					else if(b+i<=k)b+=i;
				}
				res=min(res,2*k-a-b);
			}while(next_permutation(ALL(v)));
			cout<<res<<"\n";
		}
		return 0;
	}
	cout<<get(b,a,c,n)<<"\n";
}