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
		vector<ll>a(n),b(n);
		ll mna=1e10,suma=0;
		fore(i,0,n)cin>>a[i],mna=min(mna,a[i]),suma+=a[i];
		ll mnb=1e10,sumb=0;
		fore(i,0,n)cin>>b[i],mnb=min(mnb,b[i]),sumb+=b[i];
		ll res=min(mna*n+sumb,mnb*n+suma);
		cout<<res<<"\n";
	}
	return 0;
}
