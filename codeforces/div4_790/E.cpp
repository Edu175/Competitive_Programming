#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q;cin>>n>>q;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		reverse(a,a+n);
		ll sump[n];
		sump[0]=a[0];
		fore(i,1,n)sump[i]=sump[i-1]+a[i];
		while(q--){
			ll x; cin>>x;
			ll res=(lower_bound(sump,sump+n,x)-sump)+1;
			if(res>n)res=-1;
			cout<<res<<"\n";
		}
	}
	return 0;
}
