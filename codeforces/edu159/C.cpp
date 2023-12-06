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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll d=-a[0];
		for(auto &i:a)i+=d;
		ll x=0;
		fore(i,1,n)x=gcd(x,a[i]-a[i-1]);
		if(x==0){
			//assert(n==1);
			cout<<"1\n";
			continue;
		}
		for(auto &i:a)i/=x;
		ll res=0,did=0;
		for(ll i=n-2;i>=0;i--){
			if(!did&&a[i]!=a[i+1]-1)res+=a[n-1]-(a[i+1]-1),did=1;
			res+=a[n-1]-a[i];
		}
		if(!did)res+=n;
		cout<<res<<"\n";
	}
	return 0;
}
