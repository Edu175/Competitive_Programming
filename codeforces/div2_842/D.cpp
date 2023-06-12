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

vector<ll> comp[MAXN];
ll id[MAXN];

void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i;}
bool uf_join(ll a, ll b){
	if(id[a]==id[b])return 0;
	ll c=id[a], d=id[b]; // c --> d
	if(SZ(comp[c])>SZ(comp[d]))swap(c,d);
	for(auto i:comp[c]){
		comp[d].pb(i);
		id[i]=d;
	}
	comp[c].clear();
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		uf_init(n);
		fore(i,0,n){
			cin>>a[i];
			a[i]--;
		}
		fore(i,0,n){
			uf_join(i,a[i]);
		}
		ll c=0;
		fore(i,0,n)if(SZ(comp[i]))c++;
		ll flag=0;
		fore(i,1,n)if(id[i]==id[i-1])flag=1;
		if(flag)c++;
		else c--;
		ll res=n-c;
		cout/*<<c<<" "<<flag<<" "*/<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
