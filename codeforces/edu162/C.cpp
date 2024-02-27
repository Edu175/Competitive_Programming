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
		ll n,q; cin>>n>>q;
		vector<ll>a(n),sp(n+1,0),on(n+1,0);
		fore(i,0,n)cin>>a[i];
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1],on[i]=on[i-1]+(a[i-1]==1);
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll c=on[r]-on[l],s=sp[r]-sp[l]-(r-l);
			//cout<<s<<" "<<c<<"\n";
			if(r-l>1&&s>=c)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
