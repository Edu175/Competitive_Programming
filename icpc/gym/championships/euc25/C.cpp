#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool can(vv a, ll c, ll k){
	ll n=2*c;
	if(n>SZ(a))return 0;
	a.resize(n);
	// cerr<<"can "<<c<<" "<<k<<": ";show(a)
	fore(i,0,n)if(a[i]+a[n-1-i]>=k)return 0;
	return 1;
}
ll getc(vv a, ll k){
	ll l=0,r=SZ(a)+1;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(a,m,k))l=m;
		else r=m;
	}
	return l;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a; ll r=0;
		fore(i,0,n){
			ll x; cin>>x;
			if(x<k)a.pb(x);
			else r++;
		}
		sort(ALL(a));
		// cerr<<"a: ";show(a)
		ll c=getc(a,k);
		if(c>=n-2*c){
			cout<<(n+2)/3-1<<"\n";
			continue;
		}
		// cerr<<"c "<<c<<"\n";
		ll z=SZ(a)-2*c;
		// cerr<<"z "<<z<<"\n";
		ll res=0;
		auto dec=[&](ll &a, ll &b){
			ll q=min(a,b);
			a-=q,b-=q;
			res+=q;
		};
		dec(c,r);
		dec(c,z);
		// cerr<<"ahora c z res "<<c<<" "<<z<<": "<<res<<"\n";
		dec(z,r);
		ll INF=n*10+100;
		assert(!c);
		dec(r,INF);
		assert(!r);
		res+=(z+1)/2;
		cout<<res-1<<"\n";
	}
	return 0;
}