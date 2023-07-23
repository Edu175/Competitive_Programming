#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; ld d,h; cin>>n>>d>>h;
		ll a[n+1];
		fore(i,0,n)cin>>a[i];
		a[n]=1e10;
		ld res=0;
		for(ll i=n-1;i>=0;i--){
			ld k=a[i+1]-a[i];
			if(k>=h){
				res+=d*h/2;
				continue;
			}
			ld b=d-k*(d/h);
			res+=(b+d)/2*k;
		}
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	return 0;
}
