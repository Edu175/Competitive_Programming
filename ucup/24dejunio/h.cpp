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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-9;
ll n,k;
vv a;

ll lis(vector<ld> a){ // lnds actually
	vector<ld> v;
	ll ans=0;
	for(auto i:a){
		if(i<-EPS){ans=1;continue;} // solo los no negativos
		ll p=upper_bound(ALL(v),i+EPS)-v.begin();
		if(p>=SZ(v))v.pb(i);
		else v[p]=i;
		ans=p+1;
	}
	// cout<<"lis: "; imp(a)
	// cerr<<ans<<"\n";
	return ans;
}

bool can(ld m){
	vector<ld> b(n);
	fore(i,0,n)b[i]=a[i]-m;
	vector<ld> sp(n+1);
	fore(i,0,n)sp[i+1]=sp[i]+b[i];
	auto ret=lis(sp)-1>=k;
	// cerr<<"can "<<m<<": "<<ret<<"\n";
	return ret;
}

int main(){FIN;
	cin>>n>>k;
	a=vv(n);
	fore(i,0,n)cin>>a[i];
	ld l=1e-7,r=1005;
	fore(_,0,66){
		ld m=2*l<r?sqrtl(l*r):(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	cout<<fixed<<setprecision(15);
	cout<<l<<"\n";
	return 0;
}
