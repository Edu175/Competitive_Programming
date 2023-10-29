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
		ll a[m*n];
		fore(i,0,n*m)cin>>a[i];
		sort(a,a+n*m);
		//imp(a);
		ll e=min(n,m)-1;
		ll l=(e+1)/2,r=n*m-e/2;
		ll mini=1e14,s=-1;
		fore(i,l,r-(n+m-1)+1){
			if(a[i+n+m-2]-a[i]<mini)s=i,mini=a[i+n+m-2]-a[i];
		}
		//cout<<l<<" "<<r<<": "<<s<<" "<<s+n+m-2<<"\n";
		ll vis[n*m];mset(vis,0);
		ll res[n][m];mset(res,-1);
		if(n<=m){
			fore(i,0,n)res[i][0]=a[s],vis[s]=1,s++;
			fore(j,1,m)res[n-1][j]=a[s],vis[s]=1,s++;
			for(ll i=0,h=0;i<n-1;i+=2,h++){
				res[i][1]=a[h],vis[h]=1;
			}
			for(ll i=1,h=r;i<n-1;i+=2,h++){
				res[i][1]=a[h],vis[h]=1;
			}
			ll v=0;
			fore(i,0,n-1){
				fore(j,2,m){
					while(vis[v])v++;
					//assert(v>=m*n);
					res[i][j]=a[v],v++;
				}
			}
		}
		else{
			fore(j,0,m)res[0][j]=a[s],vis[s]=1,s++;
			fore(i,1,n)res[i][m-1]=a[s],vis[s]=1,s++;
			for(ll j=0,h=0;j<m-1;j+=2,h++){
				res[1][j]=a[h],vis[h]=1;
			}
			for(ll j=1,h=r;j<m-1;j+=2,h++){
				res[1][j]=a[h],vis[h]=1;
			}
			ll v=0;
			fore(i,2,n){
				fore(j,0,m-1){
					while(vis[v])v++;
					//assert(v>=m*n);
					res[i][j]=a[v],v++;
				}
			}
		}
		fore(i,0,n){
			fore(j,0,m)cout<<res[i][j]<<" ";
			cout<<"\n";
		}
		//cout<<"\n";
	}
	return 0;
}
//"¿Saaes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
