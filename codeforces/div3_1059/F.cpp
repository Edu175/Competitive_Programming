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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll mx=0,mn=n+5;
		vv hayl(n+1),hayr(n+1);
		fore(i,0,m){
			ll l,r; cin>>l>>r; l--;
			if(r-l==n)continue;
			hayl[l]=1; hayr[r]=1;
			mn=min(mn,r);
			mx=max(mx,l);
		}
		vv res(n,-1);
		ll L=mx,R=mn;
		if(R-L>0){ // ans 0
			res[L]=0;
		}
		else {
			ll did=0; // ans 1
			fore(i,0,n+1){
				if(i<n&&!hayl[i]){
					res[i]=0;
					if(i)res[i-1]=1;
					did=1;
					break;
				}
				if(i&&!hayr[i]){
					res[i-1]=0;
					if(i<n)res[i]=1;
					did=1;
					break;
				}
			}
			if(!did)res[0]=0,res[n-1]=1; // ans 2
		}
		ll cnt=0;
		while(count(ALL(res),cnt))cnt++;
		fore(i,0,n)if(res[i]==-1)res[i]=cnt++;
		imp(res)
	}
	return 0;
}
