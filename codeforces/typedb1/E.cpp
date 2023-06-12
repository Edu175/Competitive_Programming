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
		ll n,k,x; cin>>n>>k>>x;
		vector<vector<ll>>res;
		vector<ll>vis(n+1,0);
		fore(i,1,n+1){
			if(vis[i])continue;
			if((i^x)<=n){
				vector<ll>add={i,i^x};
				if((i^x)==0)add.pop_back();
				res.pb(add);
				vis[i]=1,vis[i^x]=1;
			}
		}
		ll flag=1;
		vector<ll>sob;
		ll xp=0;
		fore(i,1,n+1)if(!vis[i]){sob.pb(i);xp^=i;};
		if(xp==x)res.pb(sob);
		else if(xp==0&&SZ(res))for(auto i:sob)res[0].pb(i);
		else flag=0;
		if(flag&&k<=SZ(res)&&k%2==SZ(res)%2){
			fore(i,k,SZ(res))for(auto j:res[i])res[0].pb(j);
			cout<<"YES\n";
			fore(i,0,k){
				cout<<SZ(res[i])<<" "; imp(res[i]);
			}
		}
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
