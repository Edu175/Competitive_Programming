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
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m,w; cin>>n>>m>>w;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	auto can=[&](ll x){
		vector<ll>b(n),ev(n);
		ll s=0,ops=0;
		fore(i,0,n)b[i]=x-a[i];
		fore(i,0,n){
			s+=ev[i];
			b[i]-=s;
			if(b[i]>0){
				ops+=b[i];
				s+=b[i];
				if(i+w<n)ev[i+w]-=b[i];
			}
		}
		return ops<=m;
	};
	ll l=0,r=1e10;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}