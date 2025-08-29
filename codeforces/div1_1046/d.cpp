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
const ll MAXN=1e5;
ll ask(vv a){
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k=ask(vv(MAXN,1));
		ll l=(MAXN+k-1)/k;
		if(l==MAXN){
			cout<<"! "<<l<<endl;
			continue;
		}
		vv v;
		fore(i,1,l+1)v.pb(l),v.pb(i);
		ll c=ask(v);
		ll r=SZ(v)-c;
		ll res=l+r;
		cout<<"! "<<res<<endl;
	}
	return 0;
}
