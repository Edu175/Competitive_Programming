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
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll mp=n,ms=n;
		fore(i,1,n)if(a[i]!=a[i-1]){mp=i;break;}
		for(ll i=n-2;i>=0;i--)if(a[i]!=a[i+1]){ms=n-1-i;break;}
		if(mp==n){
			cout<<"0\n";
			continue;
		}
		ll res=min(n-mp,n-ms);
		if(a[0]==a[n-1])res=n-mp-ms;
		cout<<res<<"\n";
	}
	return 0;
}
