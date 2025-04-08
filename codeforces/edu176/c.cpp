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
		fore(i,0,m)cin>>a[i],a[i]=min(a[i],n-1);
		sort(ALL(a));
		reverse(ALL(a));
		ll p=0,sum=0,res=0;
		fore(i,0,m){
			while(p>0&&a[p]+a[i]<n)sum-=a[--p];
			while(p<i&&a[p]+a[i]>=n)sum+=a[p++];
			ll resi=sum+p*a[i]-(n-1)*p;
			res+=resi;
		}
		cout<<res*2<<"\n";
	}
	return 0;
}
