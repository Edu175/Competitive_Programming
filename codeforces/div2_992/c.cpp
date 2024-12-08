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
const ll INF=1e13;
ll num(ll n){
	if(n>50)return INF;
	return 1ll<<(n-1);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; k--;
		vv res(n);
		ll l=0,r=n-1;
		fore(i,0,n){
			ll nu=num(n-1-i);
			if(r-l==0||k<nu){
				res[l++]=i;
			}
			else {
				k-=nu;
				res[r--]=i;
			}
		}
		if(k)cout<<"-1\n";
		else {
			for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}
