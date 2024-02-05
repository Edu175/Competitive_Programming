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
		ll n,f,u,b; cin>>n>>f>>u>>b;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(i,0,n){
			ll d=a[i]-(i?a[i-1]:0);
			f-=min(b,u*d);
			//cout<<i<<" "<<f<<"\n";
			if(f>0)res++;
		}
		if(res==n)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
