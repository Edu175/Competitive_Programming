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
	if(x<0)return 0;
	return (s+g(x))*(k-x);
}
const ll C=20;
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
		//s%10 = 2 4 6 8
		ll l=0,r=k;
		while(l<=r){
			ll m=(l+r)/2;
			if(f(m)<f(m+C))l=m+1;
			else r=m-1;
		}
		fore(i,-C,C+1)res=max(res,f(l+i));
		/*fore(i,0,k+1)cout<<f(i)<<" ";
		cout<<"\n";*/
		cout<<res<<"\n";
	}
	return 0;
}
