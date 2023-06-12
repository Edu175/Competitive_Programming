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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		vector<ll>sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll sum=sp[n];
		while(q--){
			ll l,r,k; cin>>l>>r>>k;
			l--;
			ll sumi=sum-(sp[r]-sp[l])+(r-l)*k;
			if(sumi&1)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
