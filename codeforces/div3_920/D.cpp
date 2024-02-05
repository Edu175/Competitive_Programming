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
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		sort(ALL(a)),sort(ALL(b));
		reverse(ALL(b));
		ll l=0,r=m;
		ll res=0,ans=0;
		for(ll i=n-1;i>=0;i--)res+=abs(a[i]-b[--r]);
		ans=res;
		fore(i,0,n){
			//cout<<l<<" "<<r<<": ";
			res-=abs(a[i]-b[r++]);
			res+=abs(a[i]-b[l++]);
			ans=max(ans,res);
			//cout<<res<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
