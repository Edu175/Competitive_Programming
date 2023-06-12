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
const ll MAXN=5e5+5;

ll tr[MAXN][15],qidx=0,d[MAXN];
ll add(ll x, ll e){
	ll &res=tr[x][e];
	if(res!=-1)return res;
	res=++qidx,d[res]=d[x]+1;
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n*m+3)mset(tr[i],-1),d[i]=0;
		qidx=0;
		ll a[n][m],p[n][m];
		fore(i,0,n)fore(j,0,m){
			cin>>a[i][j];
			a[i][j]--;
			p[i][a[i][j]]=j;
		}
		//fore(i,0,n){imp(a[i]);} cout<<"\n";
		//fore(i,0,n){imp(p[i]);} cout<<"\n";
		fore(i,0,n){
			ll x=0;
			fore(j,0,m){
				//cout<<x<<" --"<<p[i][j]<<"-> ";
				x=add(x,p[i][j]);
				//cout<<x<<" "<<d[x]<<"\n";
			}
		}
		vector<ll>res(n,m);
		fore(i,0,n){
			ll x=0;
			//cout<<i<<":\n";
			fore(j,0,m){
				ll e=a[i][j];
				//cout<<x<<" "<<e<<": "<<tr[x][e]<<"\n";
				if(tr[x][e]!=-1)x=tr[x][e];
				else {
					res[i]=d[x];
					break;
				}
			}
		}
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
