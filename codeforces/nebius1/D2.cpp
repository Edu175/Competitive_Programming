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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	
int main(){FIN;
	ll n,m; cin>>n>>m;
	char b[n][m];
	ll a[n][m];
	fore(i,0,n)fore(j,0,m){
		cin>>b[i][j],a[i][j]=b[i][j]-'0';
	}
	ll maxi=0;
	vector<ll>res;
	fore(h,0,2){
		maxi=0;
		fore(i,0,n){
			ll s=m/2,d=m/4,maxp=0;
			vector<ll>vis(m,0);
			fore(j,0,m-1){ // max 00
				if(vis[j]||vis[j+1])continue;
				if(!a[i][j]&&!a[i][j+1]&&d){
					vis[j]=1,vis[j+1]=1;
					d--;
				}
			}
			fore(j,0,m-1){ // max 01 10  MIGHT NOT DO
				if(vis[j]||vis[j+1])continue;
				if((a[i][j]^a[i][j+1])&&d){
					vis[j]=1,vis[j+1]=1;
					d--,maxp++;
				}
			}
			if(d)maxp+=s+d;
			else{
				fore(j,0,m)if(a[i][j]&&!vis[j])maxp++;
			}
			fore(j,0,m)cout<<a[i][j]<<" ";
			if(h)maxp=m/2+m/4-maxp;
			cout<<": "<<maxp<<"\n";
			maxi+=maxp;
		}
		cout<<"\n";
		res.pb(maxi);
		fore(i,0,n)fore(j,0,m)a[i][j]^=1;
	}
	reverse(ALL(res));
	imp(res);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
