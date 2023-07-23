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
const ll V=256;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		vector<ll> xp(n+1,0);
		vector<ll>is(V,0);
		fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
		fore(i,0,n+1)is[xp[i]]=1;
		ll res=0;
		fore(i,0,V)fore(j,0,V)if(is[i]&&is[j])res=max(res,i^j);
		cout<<res<<"\n";
	}
	return 0;
}
