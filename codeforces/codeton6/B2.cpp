#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;

ll on(ll a, ll b, ll bt){
	if(!(a&(1ll<<bt))&&(b&(1ll<<bt)))return 1;
	return 0;
}
ll off(ll a, ll b, ll bt){
	if((a&(1ll<<bt))&&(b&(1ll<<bt)))return 1;
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		ll x=0,nx=0;
		fore(i,0,n)cin>>a[i],x=x^a[i],nx=nx^(~a[i]);
		fore(i,0,m)cin>>b[i];
		vector<ll>mx=b,mn=b;
		for(ll bt=35;bt>=0;bt--){
			if(!((1ll<<bt)&nx))continue;
			vector<ll>mxi,mni;
			fore(i,0,SZ(mx))if(!off(x,mx[i],bt))mxi.pb(mx[i]);
			fore(i,0,SZ(mn))if(!on(x,mn[i],bt))mni.pb(mn[i]);
			if(SZ(mxi))mx=mxi;
			if(SZ(mni))mn=mni;
		}
		ll s0=0,s1=0;
		fore(i,0,SZ(mx))s0|=mx[i];
		fore(i,0,SZ(mn))s1|=mn[i];
		//imp(mx); imp(mn);
		//cout<<s0<<" "<<s1<<"\n";
		ll rmn=0,rmx=0;
		fore(i,0,n)rmx^=s0|a[i],rmn^=s1|a[i];
		cout<<min(x,rmn)<<" "<<max(x,rmx)<<"\n";
	}
	return 0;
}
