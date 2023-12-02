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
		ll n,v; cin>>n>>v;
		vector<ii>a(n);
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
		}
		ll res=0;
		fore(mk,0,1ll<<n){
			ll s=0,w=0;
			fore(i,0,n)if((1ll<<i)&mk)w+=a[i].fst,s+=a[i].snd;
			if(w<=v)res=max(res,s);
		}
		cout<<res<<"\n";
	}
	return 0;
}
