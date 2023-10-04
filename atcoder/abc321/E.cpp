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
ll n;

ll num(ll x, ll d){
	if(x<=0||d<0)return 0;
	if(de(x)+d<de(n))return 1ll<<d;
	if(de(x)+d>de(n))return 0;
	//if(d>60)return 0;
	ll l=x*(1ll<<d),r=(x+1)*(1ll<<d);
	if(l<=n&&n<r)return n-l+1;
	if(n<l)return 0;
	return r-l;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		//cout<<de(n)<<"\n";
		ll x,k; cin>>x>>k;
		ll p=x;
		ll res=num(x,k); x/=2; k--;
		while(x>0&&k>=0){
			res+=num(x,k)-num(p,k-1);
			//cout<<x<<" "<<k<<" "<<p<<": "<<num(x,k)<<"-"<<num(p,k-1)<<": "<<num(x,k)-num(p,k-1)<<"\n";
			p=x; x/=2; k--;
		}
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}
