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

ll sz=0;

ll query(ll y){
	cout<<"Q "<<y<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}
ll insert(ll x){
	cout<<"I "<<x<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return sz=ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll all=(1ll<<n)-1;
		cout<<"0"<<endl;
		insert(0);
		ll caso=0;
		if(sz==1)insert(all);
		else {
			caso=1;
		}
		ll l=0,r=all+1;
		while(r-l>1){
			ll m=(l+r)/2;
			if(!query(m))r=m;
			else l=m;
		}
		ll c=l,k=-1;
		if(caso){
			if(c==all){
				insert(1);
				if(sz==2)k=2;
				else k=3;
			}
			else {
				insert(all);
				if(query(all))k=2;
				else k=3;
			}
		}
		else k=1;
		cout<<"A "<<k<<" "<<c<<endl;
	}
	return 0;
}
