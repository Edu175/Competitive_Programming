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
typedef __int128 bint;

bint a,b,c;
ll can(bint k){
	if(2*a<=b)return k*a<=c;
	if(b<=a)return (k/2+1)*b<=c;
	if(k&1)return (k/2)*b+a<=c;
	return (k/2-1)*b+2*a<=c;
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		ll _a,_b,_c; cin>>_a>>_b>>_c; a=_a,b=_b,c=_c;
		ll l=1,r=2*c;
		//cout<<can(101)<<" "<<can(4)<<"\n";
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	return 0;
}
