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
		ll n,m; cin>>n>>m;
		ll a[n],b[m+1];
		vector<ll> vis(m+1,0);
		fore(i,0,n){
			cin>>a[i];
			vis[a[i]]++;
		}
		for(ll i=m-1;i>0;i--)vis[i]+=vis[i+1];
		//imp(vis);
		ll res=0;
		fore(i,1,m+1)cin>>b[i];
		for(ll i=m;i>0;i--){
			ll q=0;
			for(ll j=i;j<=m;j+=i)q+=vis[j];
			res=max(res,q*b[i]);
			//cout<<q<<" "<<i<<": "<<q*b[i]<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
