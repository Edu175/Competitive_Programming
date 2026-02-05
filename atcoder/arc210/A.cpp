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
	ll n,q; cin>>n>>q;
	vv d(n+1),mn(n+1);
	while(q--){
		ll i,x; cin>>i>>x;
		d[i]+=x;
		if(i+1>n)continue;
		d[i+1]-=x;
		mn[i+1]=min(mn[i+1],d[i+1]);
	}
	ll s=0,res=0;
	fore(i,1,n+1){
		s+=-mn[i]+1;
		res+=s;
	}
	cout<<res<<"\n";
	return 0;
}
