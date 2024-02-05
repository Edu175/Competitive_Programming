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
		vector<vector<ll>>a(n,vector<ll>(n));
		fore(i,0,n)fore(j,0,n)cin>>a[i][j];
		vector<ll>b(n,(1ll<<30)-1);
		fore(i,0,n)fore(j,0,n){
			if(i!=j)b[i]&=a[i][j];
		}
		vector<vector<ll>>c(n,vector<ll>(n));
		fore(i,0,n)fore(j,0,n)if(i!=j)c[i][j]=b[i]|b[j];
		if(c==a){
			cout<<"YES\n";
			imp(b);
		}
		else cout<<"NO\n";
	}
	return 0;
}
