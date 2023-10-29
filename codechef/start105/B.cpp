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
		ll p,q; cin>>p>>q;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		sort(ALL(a));
		ll res=a[n-1]-a[0];
		vector<ll>b;
		fore(i,1,n-1)b.pb(abs(a[i]));
		sort(ALL(b)); reverse(ALL(b));
		fore(i,0,min((ll)SZ(b),p+q))res+=b[i];
		cout<<res<<"\n";
	}
	return 0;
}
