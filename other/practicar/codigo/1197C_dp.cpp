#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;
ll n;
ll a[MAXN];
string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
ii f(ll lam){
	ii opt={a[n-1],0};
	ii res=opt;
	//cout<<"f "<<lam<<":\n";
	for(ll i=n-1;i>=0;i--){
		res={opt.fst-a[i]+lam,opt.snd+1};
		//cout<<i<<": "<<cv(res)<<"\n";
		if(i){
			res.fst+=a[i-1];
			opt=min(opt,res);
		}
	}
	//cout<<cv(res)<<"\n\n";
	return res;
}

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	ll l=0,r=2e9+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(f(m).snd<=k)r=m-1;
		else l=m+1;
	}
	cout<<f(l).fst-k*l<<"\n";
	return 0;
}
