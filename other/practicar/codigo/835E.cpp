#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll x,y;
ll QUERIES;
ll ask(vv a){
	assert(SZ(a));
	assert(++QUERIES<=19);
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	ll deb=(SZ(a)&1)*x; // if 0
	ll ans=!(ret==deb);
	// cerr<<"ask = "<<ans<<": "<<ret<<": "; show(a)
	return ans;
}

int main(){FIN;
	ll n; cin>>n>>x>>y;
	vv conj;
	ll xr=0;
	ll k=__lg(n-1)+1;
	fore(j,0,k){
		vv a;
		fore(i,0,n)if(i>>j&1)a.pb(i);
		ll got=ask(a);
		xr^=got<<j;
		if(got)conj=a;
	}
	// cerr<<"conj ";;show(conj)
	assert(SZ(conj));
	ll l=-1,r=SZ(conj)-1;
	while(r-l>1){
		ll m=(l+r)/2;
		if(ask(vv(conj.begin(),conj.begin()+m+1)))r=m;
		else l=m;
	}
	ll p=conj[r];
	// cerr<<p<<" "<<xr<<" p xr\n";
	ll q=p^xr; if(p>q)swap(p,q);
	cout<<"! "<<p+1<<" "<<q+1<<endl;
	return 0;
}