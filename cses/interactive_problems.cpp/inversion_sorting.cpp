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

ll ask(ll l, ll r){
	cout<<l+1<<" "<<r<<endl;
	ll ret; cin>>ret;
	if(ret==0)exit(0);
	return ret;
}
// 3n ops
int main(){FIN;
	ll n; cin>>n;
	vv qs;
	fore(i,0,n){
		ask(0,n);
		qs.pb(ask(0,n-1));
	}
	vv a(n);
	ll invs=qs.back();
	fore(i,0,n){
		ll num=invs-qs[i]+n-1;
		assert(num%2==0);
		a[i]=num/2;
		invs=qs[i];
	}
	
	fore(i,0,n){
		ll p=-1;
		fore(j,0,n)if(a[j]==i)p=j;
		assert(p>=i);
		ask(i,p+1);
		reverse(a.begin()+i,a.begin()+p+1);
	}
	return 0;
}