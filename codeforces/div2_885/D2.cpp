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

ll s,k;
ll g(ll x){
	ll res=(x/4)*20;
	ll si=s%10;
	fore(i,0,x%4){
		res+=si;
		si=(2*si)%10;
	}
	return res;
}
ll f(ll x){
	return (s+g(x))*(k-x);
}
ll v(ll x){
	ll l=0,r=k/4;
	while(l<=r){
		ll m=(l+r)/2;
		if(f(m*4+x)<f((m+1)*4+x))l=m+1;
		else r=m-1;
	}
	//cout<<x<<": "<<l<<" "<<l*4+x<<" "<<f(l*4+x)<<"\n";
	return f(l*4+x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s>>k;
		ll res=s*k;
		s+=s%10;k--;
		if(s%10==0||k==0){
			cout<<max(res,s*k)<<"\n";
			continue;
		}
		//fore(i,0,k+1)cout<<f(i)<<" ";
		//cout<<"\n";
		//cout<<res<<" "<<v(0)<<" "<<v(1)<<" "<<v(2)<<" "<<v(3)<<"\n";
		cout<<max({res,v(0),v(1),v(2),v(3)})<<"\n";
	}
	return 0;
}
