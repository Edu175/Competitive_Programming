#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k; m++;
		ll a=k-1,b=n-k;
		// if(a>b)swap(a,b);
		ll res=0;
		
		fore(c,0,n+5){
			ll t=m-c;
			if(t<0)continue;
			t/=2;
			if(t<c)continue;
			ll cur1=min(c,a)+min(t,b);
			ll cur2=min(c,b)+min(t,a);
			ll cur=max(cur1,cur2);
			res=max(res,cur);
		}
		res++;
		cout<<res<<"\n";
	}
	return 0;
}
