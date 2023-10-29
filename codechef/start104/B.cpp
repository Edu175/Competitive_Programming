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
typedef pair<ll,ll> ii;

vector<ll> fact(ll x){
	vector<ll>v;
	for(ll i=2; i*i<=x; i++){
		ll flag=0;
		while(x%i==0){
			x/=i;
			flag=1;
		}
		if(flag)v.pb(i);
	}
	if(x>1)v.pb(x);
	return v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>b(n,-1);
		b[0]=a[0];
		fore(i,1,n){
			ll x=a[i-1]/a[i];
			vector<ll>p=fact(x);
			for(ll y=m/a[i];y>=1;y--){
				ll flag=1;
				for(auto j:p)if(y%j==0){
					flag=0;
					break;
				}
				if(flag){
					b[i]=y*a[i];
					break;
				}
			}
		}
		imp(b);
	}
	return 0;
}
