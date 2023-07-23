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
const ll MAXN=2e5+5;

ll a[MAXN];
ll n;

ll jump(ll x, ll s){
	//cout<<x<<" "<<s<<"\n";
	if(s==0)return x;
	ll res=x+s;
	ll l=upper_bound(a,a+n,x)-a;
	ll r=upper_bound(a,a+n,res)-a;
	//cout<<r<<"-"<<l<<"\n";
	return jump(res,r-l);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		fore(i,0,n)cin>>a[i];
		ll s=1,x=jump(0,1);
		fore(i,0,k-1){
			ll xi=jump(x,x-s);
			s=x;
			//cout<<i<<": "<<x<<"\n";
			x=xi;
			
		}
		cout<<x<<"\n";
	}
	return 0;
}
