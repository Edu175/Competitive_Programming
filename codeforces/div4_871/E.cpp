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
const ll MAXN=1e6+5;

ll d[MAXN];
vector<ll> comp[MAXN]; ll id[MAXN];
void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i;}
bool uf_join(ll a, ll b){
	if(d[a]==0||d[b]==0)return 0;
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b;
	comp[a].clear();
	return 1;
}
ll n,m;
ll cv(ll i, ll j){return m*i+j;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n)fore(j,0,m)cin>>d[i*m+j];
		uf_init(n*m);
		fore(i,0,n)fore(j,0,m){
			if(i)uf_join(cv(i,j),cv(i-1,j));
			if(i<n-1)uf_join(cv(i,j),cv(i+1,j));
			if(j)uf_join(cv(i,j),cv(i,j-1));
			if(j<m-1)uf_join(cv(i,j),cv(i,j+1));
		}
		ll res=0;
		fore(i,0,n*m){
			ll sum=0;
			for(auto j:comp[i])sum+=d[j];//,cout<<j<<" ";
			res=max(res,sum);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
