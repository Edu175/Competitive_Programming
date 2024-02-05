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
		ll res=0;
		fore(d,1,n+1)if(n%d==0){
			ll g=0;
			fore(i,0,n)if(i+d<n)g=gcd(g,abs(a[i]-a[i+d]));
			vector<ll>ai=a;
			if(g>=2)fore(i,0,n)ai[i]%=g;
			ll flag=1;
			fore(i,0,n)if(i+d<n&&ai[i]!=ai[i+d])flag=0;
			res+=flag;
			//cout<<d<<" "<<g<<": "; imp(ai); cout<<flag<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
