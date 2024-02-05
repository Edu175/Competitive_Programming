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

ll c1,c2,x,y;
ll can(ll m){
	ll in=m/(x*y);
	ll d1=m/x-in;
	ll d2=m/y-in;
	return max((ll)0,c1-d2)+max((ll)0,c2-d1)<=m-d1-d2-in;
}

int main(){FIN;
	cin>>c1>>c2>>x>>y;
	ll l=0,r=1e18;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
