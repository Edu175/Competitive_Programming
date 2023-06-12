#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

vector<vector<ll>>comp(MAXN);
vector<ll> id(MAXN);

void uf_init(ll n){fore(i,0,n)comp[i].pb(i),id[i]=i;}
bool uf_join(ll a, ll b){
	if(id[a]==id[b])return false;
	ll ida=id[a], idb=id[b];
	if(SZ(comp[ida])>SZ(comp[idb]))swap(ida,idb);
	for(auto i:comp[ida]){
		comp[idb].pb(i);
		id[i]=idb;
	}
	return true;
}
ll n;


int main(){FIN;
	cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll q; cin>>q;
	uf_init(n);
	fore(i,0,n-1){if(a[i]==a[i+1])uf_join(i,i+1)};
	while(q--){
		ll pos,x; cin>>pos>>x;
		
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
