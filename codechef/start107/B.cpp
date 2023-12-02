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

ll n,k;
ll f(ll x){
	//cout<<"f "<<x<<": "<<x%k<<"*"<<(n-x)%k<<" = "<<(x%k)*((n-x)%k)<<"\n";
	return (x%k)*((n-x)%k);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		//cout<<(n%k)/2<<" "<<(n%k+k)/2<<"\n";
		ll x1=(n%k)/2,x2=(n%k+k)/2;
		//cout<<x1<<" "<<x2<<": "<<f(x1)<<" "<<f(x2)<<"\n";
		if(f(x1)>=f(x2))cout<<x1<<"\n";
		else cout<<x2<<"\n";
	}
	return 0;
}
