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
		ll n,d; cin>>n>>d;
		ll sie=0;
		if(n>=3)sie=1;
		else {
			ll x=0;
			fore(i,0,n)x=x*10+d;
			vv ans;
			fore(i,1,10)if((i&1)&&x%i==0)ans.pb(i);
			imp(ans)
			continue;
		}
		ll sum=0;
		if(n>=9)sum=0;
		else {
			ll fac=1;
			fore(i,1,n+1)fac*=i;
			sum=d*fac%9;
		}
		cout<<"1 ";
		if(sum%3==0)cout<<"3 ";
		if(d==5)cout<<"5 ";
		if(sie)cout<<"7 ";
		if(sum==0)cout<<"9 ";
		cout<<"\n";
	}
	return 0;
}
