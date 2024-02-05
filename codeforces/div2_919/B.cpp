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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k,x; cin>>n>>k>>x;
		vector<ll>a(n);
		ll res=0;
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		fore(i,0,n-x)res+=a[i];
		fore(i,n-x,n)res-=a[i];
		ll resi=res;
		for(ll i=n-1,q=0;i>=0&&q<k;i--,q++){
			resi+=a[i];
			if(i-x>=0)resi-=2*a[i-x];
			//cout<<i<<" "<<q<<": "<<resi<<"\n";
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
