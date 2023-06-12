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
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n; cin>>n;
		ll trash=0;
		fore(i,0,n)fore(j,0,n)cin>>trash;
		ll a[n][n],sum=0;
		fore(i,0,n){
			fore(j,0,n)cin>>a[i][j],sum+=a[i][j];
		}
		fore(i,0,2)fore(j,0,n)cin>>trash;
		ll vis[n][n]; mset(vis,0);
		fore(i,0,n){
			ll p=-1;
			fore(j,0,n)if(p==-1||a[i][j]>a[i][p])p=j;
			vis[i][p]=1; sum-=a[i][p];
		}
		vector<ll>b;
		fore(j,0,n){
			ll maxi=0;
			fore(i,0,n){
				if(vis[i][j])continue;
				maxi=max(maxi,a[i][j]);
			}
			b.pb(maxi);
		}
		sort(ALL(b)); reverse(ALL(b));
		b.pop_back();
		for(auto i:b)sum-=i;
		cout<<sum<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
