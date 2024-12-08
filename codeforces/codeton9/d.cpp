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
		vv a(m);
		fore(i,0,m)cin>>a[i];
		sort(ALL(a));
		vv id(n+1);
		fore(i,1,n+1){
			for(ll j=2*i;j<=n;j+=i)if(id[i]==id[j])id[j]++;
		}
		ll flag=1;
		vv ans(n);
		fore(i,1,n+1){
			if(id[i]>=m)flag=0;
			else ans[i-1]=a[m-1-id[i]];
		}
		if(flag){
			imp(ans);
		}
		else cout<<"-1\n";
	}
	return 0;
}
