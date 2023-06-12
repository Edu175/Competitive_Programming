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
		ll n,s[2]; cin>>n>>s[0]>>s[1];
		vector<ll>a(n);
		vector<pair<ll,ll>>b;
		fore(i,0,n)cin>>a[i],b.pb({a[i],i});
		sort(ALL(b)); reverse(ALL(b));
		vector<pair<ll,pair<ll,ll>>>c;
		fore(i,0,2)fore(j,0,n){
			c.pb({s[i]*(j+1),{i,j}});
		}
		sort(ALL(c));
		ll res[2][n]; mset(res,-1);
		fore(i,0,n)res[c[i].snd.fst][c[i].snd.snd]=b[i].snd;
		fore(i,0,2){
			vector<ll>pr;
			fore(j,0,n)if(res[i][j]>-1)pr.pb(res[i][j]+1);
			cout<<SZ(pr)<<" "; imp(pr);
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
