#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ask(ll x, vv v){
	cout<<"1 "<<SZ(v)<<" "<<x+1<<" ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv resto;
		fore(i,1,n)resto.pb(i);
		ll mx=ask(0,resto);
		ll l=1,r=n-1;
		while(l<=r){
			ll m=(l+r)/2;
			vv tmp;
			fore(i,1,m+1)tmp.pb(i);
			if(ask(0,tmp)==mx)r=m-1;
			else l=m+1;
		}
		resto.clear();
		fore(i,0,n)if(i!=l)resto.pb(i);
		ll res=ask(l,resto);
		cout<<"-1 "<<res<<endl;
	}
	return 0;
}