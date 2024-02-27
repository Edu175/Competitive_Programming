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

ll fact(ll n){
	ll ret=1;
	for(ll i=2;i*i<=n;i++){
		ll c=0;
		while(n%i==0)c++,n/=i;
		if(c&1)ret*=i;
	}
	if(n>1)ret*=n;
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a;
	ll z=0;
	fore(i,0,n){
		ll x; cin>>x;
		if(x==0)z++;
		else a.pb(fact(x));
	}
	map<ll,ll>c;
	ll res=z*(n-z)+z*(z-1)/2;
	//cout<<res<<"\n";
	//imp(a);
	fore(i,0,SZ(a)){
		res+=c[a[i]]++;
	}
	cout<<res<<"\n";
	return 0;
}
