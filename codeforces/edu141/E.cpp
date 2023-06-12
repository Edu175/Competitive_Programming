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
const ll MAXN=2e5+5;

vector<ll>divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
int main(){FIN;
	divisores();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<pair<ll,ll>>rn;
		fore(i,0,n){
			if(a[i]<=b[i])continue;
			rn.pb({b[i],a[i]});
		}
		sort(ALL(rn));
		vector<ll>vis(n+1,0);
		ll r=0;
		for(auto i:rn){
			ll l=max(r,i.fst);
			r=max(r,i.snd);
			fore(j,l,r)vis[j]=1;
			//cout<<"["<<l<<","<<r<<")\n";
		}
		fore(i,1,n+1){
			if(vis[i])for(auto j:divs[i])vis[j]=1;
		}
		vector<ll>res;
		fore(i,1,n+1)if(!vis[i])res.pb(i);
		cout<<SZ(res)<<"\n";
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
