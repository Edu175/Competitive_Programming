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
		ll a[n],res=0;
		fore(i,0,n)cin>>a[i];
		for(ll i=n-2;i>=0;i--){
			while(a[i]&&a[i]>=a[i+1]){
				res++; a[i]>>=1;
			}
		}
		ll flag=1;
		fore(i,0,n-1)if(a[i]>=a[i+1])flag=0;
		if(flag)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
