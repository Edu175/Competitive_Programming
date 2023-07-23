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
typedef pair<ll,ll> ii;
#define bint __int128

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b;
		b=b*b,e>>=1;
	}
	return ret;
}

ll n;
bool can(ll k, ll r){ //<=
	bint c=n*(k-1)+1;
	bint ret=1;
	bint e=r+1,b=k;
	//cout<<"can "<<n<<" "<<k<<" "<<r<<" , "<<(ll)c<<":\n";
	while(e){
		//cout<<(ll)ret<<" "<<(ll)b<<" "<<(ll)e<<"\n";
		if(ret>c||b>c)return 0;
		if(e&1){
			if(ret>c/b+5)return 0;
			//if(log2(ret)+log2(b)>log2(c)+5)return 0;
			ret=ret*b;
		}
		
		e>>=1;
		if(e&&b>c/b+5)return 0;
		b=b*b;
	}
	//cout<<"llego "<<(ll)ret<<" "<<(ll)c<<"\n";
	return (ret<=c);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll flag=0;
		fore(e,2,log2(n)+5){
			ll l=2,r=sqrt(n)+5;
			while(l<=r){
				ll m=(l+r)/2;
				if(can(m,e))l=m+1;
				else r=m-1;
			}
			if(r>=2&&fpow(r,e+1)-1==n*(r-1))flag=1;
			//cout<<e<<": "<<r<<": "<<fpow(r,e+1)-1<<" == "<<n*(r-1)<<"\n";
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
