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
string get(vv a, ll x, ll y, ll flip){
	ll n=SZ(a);
	if(flip){
		fore(i,0,n)a[i]^=1;
		swap(x,y);
	}
	// vector<ii> ret;
	string ret;
	ll q=0;
	fore(i,0,n){
		q++;
		if(i==n-1||a[i]!=a[i+1]){
			ll ty=a[i];
			ll r=q;
			if(ty)r%=y;
			ret+=string(r,'0'+ty);
			q=0;
		}
	}
	return ret;
}

bool good(vv a, vv b, ll x, ll y, ll flip){
	auto gota=get(a,x,y,flip);
	auto gotb=get(b,x,y,flip);
	// cerr<<"good "<<flip<<":\n";
	// for(auto i:gota)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	// for(auto i:gotb)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	// cout<<(gota==gotb)<<"\n\n";
	return gota==gotb;
}

int main(){FIN;
	ll n,x,y; cin>>n>>x>>y;
	vv a(n),b(n);
	fore(i,0,n){
		char c; cin>>c;
		a[i]=c-'0';
	}
	fore(i,0,n){
		char c; cin>>c;
		b[i]=c-'0';
	}
	ll r0=good(a,b,x,y,0);
	ll r1=good(a,b,x,y,1);
	ll res=r0&&r1;
	if(res)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
