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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		ll x=0,o=0;
		fore(i,0,n)cin>>a[i],x=x^a[i];
		fore(i,0,m)cin>>b[i],o|=b[i];
		ll res=0;
		fore(i,0,n)res^=a[i]|o;
		cout<<min(x,res)<<" "<<max(x,res)<<"\n";
		
	}
	return 0;
}
