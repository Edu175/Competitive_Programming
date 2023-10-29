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

ll de(ll n){
	return 63-__builtin_clzll(n);
}

ll dis(ll x, ll y){
	//ll _x=x,_y=y;
	if(de(x)<de(y))swap(x,y);
	ll res=0;
	while(de(x)>de(y))x/=2,res++;
	while(x!=y)res+=2,x/=2,y/=2;
	//cout<<"dis "<<_x<<","<<_y<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll x,k; cin>>x>>k;
		ll res=0;
		fore(i,1,n+1)res+=(dis(i,x)==k);
		cout<<res<<"\n";
	}
	return 0;
}
