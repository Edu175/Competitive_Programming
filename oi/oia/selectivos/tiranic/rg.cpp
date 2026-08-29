#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll T=1e6,A=100;
random_device rd;
mt19937 rng(rd());

ll wrng(ll r, ll t){
	ll ans=rng()%r;
	if(t<0) fore(_,0,-t)ans=min(ans,ll(rng()%r));
	else fore(_,0,t)ans=max(ans,ll(rng()%r));
	return ans;
}

ll Nrng(ll r, ll x){
	ll t=r/x-2;
	return wrng(r,-t);
}

int main(){
	ll n=Nrng(T,1000)+1; ll m=T/n;
	cout<<n<<" "<<m<<"\n";
	ll l=(A+m-1)/m,r=min(n,A);
	ll h=Nrng(r-l+1,10)+l;
	ll w=(A+h-1)/h;
	assert(h>=1 && w>=1);
	assert(h<=n && w<=m && h*w>=A);
	ll di=rng()%(n-h+1);
	ll dj=rng()%(m-w+1);
	cout<<di<<" "<<m-dj-w<<" "<<n-di-h<<" "<<dj<<"\n";
	cerr<<h<<" "<<w<<"\n";
}
