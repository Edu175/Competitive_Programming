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
		sort(ALL(b));
		vector<vector<ll>>res(n);
		ll j=0;
		for(ll i=n-1;i>=0;i--){
			while(j<m&&b[j]<=a[i])res[i].pb(b[j]),j++;
			reverse(ALL(res[i]));
		}
		for(ll i=m-1;i>=j;i--)cout<<b[i]<<" ";
		fore(i,0,n){
			cout<<a[i]<<" ";
			for(auto k:res[i])cout<<k<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
