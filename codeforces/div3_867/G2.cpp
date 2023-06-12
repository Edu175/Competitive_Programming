#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v){cout<<messi<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=1e9+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll CUT=min(1e4/(n*log(n)),sqrt(MAXN)+5);
		map<ll,ll>c;
		ll a[n];
		fore(i,0,n)cin>>a[i],c[a[i]]++;
		ll res=0;
		fore(i,0,n){
			res+=(c[a[i]]-1)*(c[a[i]]-2);
			for(ll b=2;a[i]*b*b<=MAXN&&b<CUT;b++)
				res+=c[a[i]*b]*c[a[i]*b*b];
		}
		for(ll b=CUT;b*b<=MAXN;b++){
			for(ll a0=1;a0*b*b<=MAXN;a0++)
				res+=c[a0]*c[a0*b]*c[a0*b*b];
		}
		cout<<res<<"\n";
	}
	return 0;
}
