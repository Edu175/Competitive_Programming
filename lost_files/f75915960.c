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

ll ask(ll i){
	i++;
	cout<<"? "<<i<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll res=0;
		for(ll i=0;i<n;i+=k){
			res^=ask(i);
		}
		if(n%k==0){
			cout<<"! "<<res<<endl;
			continue;
		}
		res^=ask(n-k);
		ll r=n%k;
		res^=ask(n-k-r/2);
		res^=ask(n-k);
		cout<<"! "<<res<<endl;
	}
	return 0;
}
